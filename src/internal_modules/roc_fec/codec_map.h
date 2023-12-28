/*
 * Copyright (c) 2019 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

//! @file roc_fec/codec_map.h
//! @brief FEC codec map.

#ifndef ROC_FEC_CODEC_MAP_H_
#define ROC_FEC_CODEC_MAP_H_

#include "roc_core/buffer_factory.h"
#include "roc_core/iarena.h"
#include "roc_core/noncopyable.h"
#include "roc_core/singleton.h"
#include "roc_fec/codec_config.h"
#include "roc_fec/iblock_decoder.h"
#include "roc_fec/iblock_encoder.h"

namespace roc {
namespace fec {

//! FEC codec map.
class CodecMap : public core::NonCopyable<> {
public:
    //! Get instance.
    static CodecMap& instance() {
        return core::Singleton<CodecMap>::instance();
    }

    //! Check whether given FEC scheme is supported.
    bool is_supported(packet::FecScheme scheme) const;

    //! Get number of supported FEC schemes.
    size_t num_schemes() const;

    //! Get FEC scheme ID by index.
    packet::FecScheme nth_scheme(size_t n) const;

    //! Create a new block encoder.
    //!
    //! @remarks
    //!  The codec type is determined by @p config.
    //!
    //! @returns
    //!  NULL if parameters are invalid or given codec support is not enabled.
    IBlockEncoder* new_encoder(const CodecConfig& config,
                               core::BufferFactory<uint8_t>& buffer_factory,
                               core::IArena& arena) const;

    //! Create a new block decoder.
    //!
    //! @remarks
    //!  The codec type is determined by @p config.
    //!
    //! @returns
    //!  NULL if parameters are invalid or given codec support is not enabled.
    IBlockDecoder* new_decoder(const CodecConfig& config,
                               core::BufferFactory<uint8_t>& buffer_factory,
                               core::IArena& arena) const;

private:
    friend class core::Singleton<CodecMap>;

    enum { MaxCodecs = 2 };

    struct Codec {
        packet::FecScheme scheme;

        IBlockEncoder* (*encoder_ctor)(const CodecConfig& config,
                                       core::BufferFactory<uint8_t>& buffer_factory,
                                       core::IArena& arena);

        IBlockDecoder* (*decoder_ctor)(const CodecConfig& config,
                                       core::BufferFactory<uint8_t>& buffer_factory,
                                       core::IArena& arena);
    };

    CodecMap();

    void add_codec_(const Codec& codec);
    const Codec* find_codec_(packet::FecScheme scheme) const;

    size_t n_codecs_;
    Codec codecs_[MaxCodecs];
};

} // namespace fec
} // namespace roc

#endif // ROC_FEC_CODEC_MAP_H_
