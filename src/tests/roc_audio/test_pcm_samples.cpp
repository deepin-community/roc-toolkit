/*
 * Copyright (c) 2022 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <CppUTest/TestHarness.h>

#include "roc_audio/pcm_mapper.h"
#include "roc_core/log.h"
#include "roc_core/macro_helpers.h"

#include "test_samples/pcm_float32_be.h"
#include "test_samples/pcm_float32_le.h"
#include "test_samples/pcm_sint16_be.h"
#include "test_samples/pcm_sint16_le.h"
#include "test_samples/pcm_sint24_be.h"
#include "test_samples/pcm_sint24_le.h"
#include "test_samples/pcm_sint32_be.h"
#include "test_samples/pcm_sint32_le.h"
#include "test_samples/pcm_sint8_be.h"
#include "test_samples/pcm_sint8_le.h"
#include "test_samples/pcm_uint16_be.h"
#include "test_samples/pcm_uint16_le.h"
#include "test_samples/pcm_uint24_be.h"
#include "test_samples/pcm_uint24_le.h"
#include "test_samples/pcm_uint32_be.h"
#include "test_samples/pcm_uint32_le.h"
#include "test_samples/pcm_uint8_be.h"
#include "test_samples/pcm_uint8_le.h"

namespace roc {
namespace audio {

namespace {

const double Epsilon = 0.01;

const test::SampleInfo* test_samples[] = {
    &test::sample_pcm_float32_be, &test::sample_pcm_float32_le,
    &test::sample_pcm_sint16_be,  &test::sample_pcm_sint16_le,
    &test::sample_pcm_sint24_be,  &test::sample_pcm_sint24_le,
    &test::sample_pcm_sint32_be,  &test::sample_pcm_sint32_le,
    &test::sample_pcm_sint8_be,   &test::sample_pcm_sint8_le,
    &test::sample_pcm_uint16_be,  &test::sample_pcm_uint16_le,
    &test::sample_pcm_uint24_be,  &test::sample_pcm_uint24_le,
    &test::sample_pcm_uint32_be,  &test::sample_pcm_uint32_le,
    &test::sample_pcm_uint8_be,   &test::sample_pcm_uint8_le,
};

} // namespace

TEST_GROUP(pcm_samples) {};

TEST(pcm_samples, decode) {
    for (size_t idx = 0; idx < ROC_ARRAY_SIZE(test_samples); idx++) {
        roc_log(LogDebug, "mapping %s to native", test_samples[idx]->name);

        PcmFormat in_fmt;
        in_fmt.code = test_samples[idx]->encoding;
        in_fmt.endian = test_samples[idx]->endian;

        PcmFormat out_fmt;
        out_fmt.code = PcmCode_Float64;
        out_fmt.endian = PcmEndian_Native;

        PcmMapper mapper(in_fmt, out_fmt);

        UNSIGNED_LONGS_EQUAL(test_samples[idx]->num_samples,
                             mapper.input_sample_count(test_samples[idx]->num_bytes));

        UNSIGNED_LONGS_EQUAL(test_samples[idx]->num_bytes,
                             mapper.input_byte_count(test_samples[idx]->num_samples));

        double decoded_samples[test::SampleInfo::MaxSamples] = {};

        const size_t in_bytes = test_samples[idx]->num_bytes;
        const size_t out_bytes = test_samples[idx]->num_samples * sizeof(double);

        size_t in_off = 0;
        size_t out_off = 0;

        const size_t actual_samples =
            mapper.map(test_samples[idx]->bytes, in_bytes, in_off, decoded_samples,
                       out_bytes, out_off, test_samples[idx]->num_samples);

        UNSIGNED_LONGS_EQUAL(test_samples[idx]->num_samples, actual_samples);

        UNSIGNED_LONGS_EQUAL(in_bytes * 8, in_off);
        UNSIGNED_LONGS_EQUAL(out_bytes * 8, out_off);

        roc_log(LogDebug, "checking samples");

        for (size_t n = 0; n < test_samples[idx]->num_samples; n++) {
            DOUBLES_EQUAL(test_samples[idx]->samples[n], decoded_samples[n], Epsilon);
        }
    }
}

TEST(pcm_samples, recode) {
    for (size_t idx1 = 0; idx1 < ROC_ARRAY_SIZE(test_samples); idx1++) {
        for (size_t idx2 = 0; idx2 < ROC_ARRAY_SIZE(test_samples); idx2++) {
            uint8_t recoded_bytes[test::SampleInfo::MaxBytes] = {};
            double decoded_samples[test::SampleInfo::MaxSamples] = {};

            {
                roc_log(LogDebug, "mapping %s to %s", test_samples[idx1]->name,
                        test_samples[idx2]->name);

                PcmFormat in_fmt;
                in_fmt.code = test_samples[idx1]->encoding;
                in_fmt.endian = test_samples[idx1]->endian;

                PcmFormat out_fmt;
                out_fmt.code = test_samples[idx2]->encoding;
                out_fmt.endian = test_samples[idx2]->endian;

                PcmMapper mapper(in_fmt, out_fmt);

                UNSIGNED_LONGS_EQUAL(
                    test_samples[idx1]->num_samples,
                    mapper.input_sample_count(test_samples[idx1]->num_bytes));

                UNSIGNED_LONGS_EQUAL(
                    test_samples[idx1]->num_bytes,
                    mapper.input_byte_count(test_samples[idx1]->num_samples));

                UNSIGNED_LONGS_EQUAL(
                    test_samples[idx2]->num_samples,
                    mapper.output_sample_count(test_samples[idx2]->num_bytes));

                UNSIGNED_LONGS_EQUAL(
                    test_samples[idx2]->num_bytes,
                    mapper.output_byte_count(test_samples[idx2]->num_samples));

                const size_t in_bytes = test_samples[idx1]->num_bytes;
                const size_t out_bytes = test_samples[idx2]->num_bytes;

                size_t in_off = 0;
                size_t out_off = 0;

                const size_t actual_samples =
                    mapper.map(test_samples[idx1]->bytes, in_bytes, in_off, recoded_bytes,
                               out_bytes, out_off, test_samples[idx1]->num_samples);

                UNSIGNED_LONGS_EQUAL(test_samples[idx1]->num_samples, actual_samples);

                UNSIGNED_LONGS_EQUAL(in_bytes * 8, in_off);
                UNSIGNED_LONGS_EQUAL(out_bytes * 8, out_off);
            }

            {
                roc_log(LogDebug, "mapping %s to native", test_samples[idx2]->name);

                PcmFormat in_fmt;
                in_fmt.code = test_samples[idx2]->encoding;
                in_fmt.endian = test_samples[idx2]->endian;

                PcmFormat out_fmt;
                out_fmt.code = PcmCode_Float64;
                out_fmt.endian = PcmEndian_Native;

                PcmMapper mapper(in_fmt, out_fmt);

                UNSIGNED_LONGS_EQUAL(
                    test_samples[idx2]->num_samples,
                    mapper.input_sample_count(test_samples[idx2]->num_bytes));

                UNSIGNED_LONGS_EQUAL(
                    test_samples[idx2]->num_bytes,
                    mapper.input_byte_count(test_samples[idx2]->num_samples));

                const size_t in_bytes = test_samples[idx2]->num_bytes;
                const size_t out_bytes = test_samples[idx2]->num_samples * sizeof(double);

                size_t in_off = 0;
                size_t out_off = 0;

                const size_t actual_samples =
                    mapper.map(recoded_bytes, in_bytes, in_off, decoded_samples,
                               out_bytes, out_off, test_samples[idx2]->num_samples);

                UNSIGNED_LONGS_EQUAL(test_samples[idx2]->num_samples, actual_samples);

                UNSIGNED_LONGS_EQUAL(in_bytes * 8, in_off);
                UNSIGNED_LONGS_EQUAL(out_bytes * 8, out_off);
            }

            roc_log(LogDebug, "checking samples");

            for (size_t n = 0; n < test_samples[idx1]->num_samples; n++) {
                DOUBLES_EQUAL(test_samples[idx1]->samples[n], decoded_samples[n],
                              Epsilon);
            }
        }
    }
}

} // namespace audio
} // namespace roc
