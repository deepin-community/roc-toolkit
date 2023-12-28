/*
 * Copyright (c) 2019 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "roc_fec/codec_map.h"
#include "roc_core/attributes.h"
#include "roc_core/log.h"
#include "roc_core/panic.h"
#include "roc_core/scoped_ptr.h"
#include "roc_packet/fec_scheme_to_str.h"

#ifdef ROC_TARGET_OPENFEC
#include "roc_fec/openfec_decoder.h"
#include "roc_fec/openfec_encoder.h"
#endif // ROC_TARGET_OPENFEC

namespace roc {
namespace fec {

namespace {

template <class I, class T>
ROC_ATTR_UNUSED I* ctor_func(const CodecConfig& config,
                             core::BufferFactory<uint8_t>& buffer_factory,
                             core::IArena& arena) {
    core::ScopedPtr<T> codec(new (arena) T(config, buffer_factory, arena), arena);
    if (!codec || !codec->is_valid()) {
        return NULL;
    }
    return codec.release();
}

} // namespace

CodecMap::CodecMap()
    : n_codecs_(0) {
#ifdef ROC_TARGET_OPENFEC
    {
        Codec codec;
        codec.encoder_ctor = ctor_func<IBlockEncoder, OpenfecEncoder>;
        codec.decoder_ctor = ctor_func<IBlockDecoder, OpenfecDecoder>;

        codec.scheme = packet::FEC_ReedSolomon_M8;
        add_codec_(codec);

        codec.scheme = packet::FEC_LDPC_Staircase;
        add_codec_(codec);
    }
#endif // ROC_TARGET_OPENFEC
}

bool CodecMap::is_supported(packet::FecScheme scheme) const {
    return find_codec_(scheme);
}

size_t CodecMap::num_schemes() const {
    return n_codecs_;
}

packet::FecScheme CodecMap::nth_scheme(size_t n) const {
    roc_panic_if(n >= n_codecs_);
    return codecs_[n].scheme;
}

IBlockEncoder* CodecMap::new_encoder(const CodecConfig& config,
                                     core::BufferFactory<uint8_t>& buffer_factory,
                                     core::IArena& arena) const {
    const Codec* codec = find_codec_(config.scheme);
    if (!codec) {
        return NULL;
    }
    return codec->encoder_ctor(config, buffer_factory, arena);
}

IBlockDecoder* CodecMap::new_decoder(const CodecConfig& config,
                                     core::BufferFactory<uint8_t>& buffer_factory,
                                     core::IArena& arena) const {
    const Codec* codec = find_codec_(config.scheme);
    if (!codec) {
        return NULL;
    }
    return codec->decoder_ctor(config, buffer_factory, arena);
}

void CodecMap::add_codec_(const Codec& codec) {
    roc_panic_if(n_codecs_ == MaxCodecs);
    codecs_[n_codecs_++] = codec;
}

const CodecMap::Codec* CodecMap::find_codec_(packet::FecScheme scheme) const {
    for (size_t n = 0; n < n_codecs_; n++) {
        if (codecs_[n].scheme == scheme) {
            return &codecs_[n];
        }
    }

    roc_log(LogError, "codec map: no codec available for fec scheme '%s'",
            packet::fec_scheme_to_str(scheme));

    return NULL;
}

} // namespace fec
} // namespace roc
