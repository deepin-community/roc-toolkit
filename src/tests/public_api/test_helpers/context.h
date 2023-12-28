/*
 * Copyright (c) 2020 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef ROC_PUBLIC_API_TEST_HELPERS_CONTEXT_H_
#define ROC_PUBLIC_API_TEST_HELPERS_CONTEXT_H_

#include <CppUTest/TestHarness.h>

#include "test_helpers/utils.h"

#include "roc_core/noncopyable.h"
#include "roc_core/stddefs.h"

#include "roc/config.h"
#include "roc/context.h"

namespace roc {
namespace api {
namespace test {

class Context : public core::NonCopyable<> {
public:
    Context()
        : ctx_(NULL) {
        roc_context_config config;
        memset(&config, 0, sizeof(config));
        config.max_packet_size = MaxBufSize;
        config.max_frame_size = MaxBufSize;

        CHECK(roc_context_open(&config, &ctx_) == 0);
        CHECK(ctx_);
    }

    ~Context() {
        CHECK(roc_context_close(ctx_) == 0);
    }

    roc_context* get() {
        return ctx_;
    }

    void register_multitrack_encoding(int encoding_id, unsigned num_tracks) {
        roc_media_encoding encoding;
        memset(&encoding, 0, sizeof(encoding));
        encoding.rate = SampleRate;
        encoding.format = ROC_FORMAT_PCM_FLOAT32;
        encoding.channels = ROC_CHANNEL_LAYOUT_MULTITRACK;
        encoding.tracks = num_tracks;

        CHECK(roc_context_register_encoding(ctx_, encoding_id, &encoding) == 0);
    }

private:
    roc_context* ctx_;
};

} // namespace test
} // namespace api
} // namespace roc

#endif // ROC_PUBLIC_API_TEST_HELPERS_CONTEXT_H_
