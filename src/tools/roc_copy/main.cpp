/*
 * Copyright (c) 2019 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "roc_address/io_uri.h"
#include "roc_audio/resampler_profile.h"
#include "roc_core/crash_handler.h"
#include "roc_core/heap_arena.h"
#include "roc_core/log.h"
#include "roc_core/parse_duration.h"
#include "roc_core/scoped_ptr.h"
#include "roc_pipeline/transcoder_sink.h"
#include "roc_sndio/backend_dispatcher.h"
#include "roc_sndio/backend_map.h"
#include "roc_sndio/config.h"
#include "roc_sndio/print_supported.h"
#include "roc_sndio/pump.h"

#include "roc_copy/cmdline.h"

using namespace roc;

int main(int argc, char** argv) {
    core::HeapArena::set_flags(core::DefaultHeapArenaFlags
                               | core::HeapArenaFlag_EnableLeakDetection);

    core::CrashHandler crash_handler;

    gengetopt_args_info args;

    const int code = cmdline_parser(argc, argv, &args);
    if (code != 0) {
        return code;
    }

    core::ScopedPtr<gengetopt_args_info, core::CustomAllocation> args_holder(
        &args, &cmdline_parser_free);

    core::Logger::instance().set_verbosity(args.verbose_given);

    switch (args.color_arg) {
    case color_arg_auto:
        core::Logger::instance().set_colors(core::ColorsAuto);
        break;
    case color_arg_always:
        core::Logger::instance().set_colors(core::ColorsEnabled);
        break;
    case color_arg_never:
        core::Logger::instance().set_colors(core::ColorsDisabled);
        break;
    default:
        break;
    }

    core::HeapArena arena;
    sndio::BackendDispatcher backend_dispatcher(arena);

    if (args.list_supported_given) {
        if (!sndio::print_supported(backend_dispatcher, arena)) {
            return 1;
        }
        return 0;
    }

    pipeline::TranscoderConfig transcoder_config;

    sndio::Config source_config;
    source_config.sample_spec.set_channel_set(
        transcoder_config.input_sample_spec.channel_set());
    source_config.sample_spec.set_sample_rate(0);

    if (args.frame_length_given) {
        if (!core::parse_duration(args.frame_length_arg, source_config.frame_length)) {
            roc_log(LogError, "invalid --frame-length: bad format");
            return 1;
        }
        if (transcoder_config.input_sample_spec.ns_2_samples_overall(
                source_config.frame_length)
            <= 0) {
            roc_log(LogError, "invalid --frame-length: should be > 0");
            return 1;
        }
    }

    sndio::BackendMap::instance().set_frame_size(source_config.frame_length,
                                                 transcoder_config.input_sample_spec);

    core::BufferFactory<audio::sample_t> buffer_factory(
        arena,
        transcoder_config.input_sample_spec.ns_2_samples_overall(
            source_config.frame_length));

    address::IoUri input_uri(arena);
    if (args.input_given) {
        if (!address::parse_io_uri(args.input_arg, input_uri) || !input_uri.is_file()) {
            roc_log(LogError, "invalid --input file URI");
            return 1;
        }
    }

    if (!args.input_format_given && input_uri.is_special_file()) {
        roc_log(LogError, "--input-format should be specified if --input is \"-\"");
        return 1;
    }

    core::ScopedPtr<sndio::ISource> input_source;
    if (input_uri.is_valid()) {
        input_source.reset(backend_dispatcher.open_source(
                               input_uri, args.input_format_arg, source_config),
                           arena);
    } else {
        input_source.reset(backend_dispatcher.open_default_source(source_config), arena);
    }
    if (!input_source) {
        roc_log(LogError, "can't open input: %s", args.input_arg);
        return 1;
    }
    if (input_source->has_clock()) {
        roc_log(LogError, "unsupported input: %s", args.input_arg);
        return 1;
    }

    transcoder_config.input_sample_spec.set_sample_rate(
        input_source->sample_spec().sample_rate());

    if (args.rate_given) {
        transcoder_config.output_sample_spec.set_sample_rate((size_t)args.rate_arg);
    } else {
        transcoder_config.output_sample_spec.set_sample_rate(
            transcoder_config.input_sample_spec.sample_rate());
    }

    switch (args.resampler_backend_arg) {
    case resampler_backend_arg_default:
        transcoder_config.resampler_backend = audio::ResamplerBackend_Default;
        break;
    case resampler_backend_arg_builtin:
        transcoder_config.resampler_backend = audio::ResamplerBackend_Builtin;
        break;
    case resampler_backend_arg_speex:
        transcoder_config.resampler_backend = audio::ResamplerBackend_Speex;
        break;
    case resampler_backend_arg_speexdec:
        transcoder_config.resampler_backend = audio::ResamplerBackend_SpeexDec;
        break;
    default:
        break;
    }

    switch (args.resampler_profile_arg) {
    case resampler_profile_arg_low:
        transcoder_config.resampler_profile = audio::ResamplerProfile_Low;
        break;
    case resampler_profile_arg_medium:
        transcoder_config.resampler_profile = audio::ResamplerProfile_Medium;
        break;
    case resampler_profile_arg_high:
        transcoder_config.resampler_profile = audio::ResamplerProfile_High;
        break;
    default:
        break;
    }

    transcoder_config.enable_profiling = args.profiling_flag;

    audio::IFrameWriter* output_writer = NULL;

    sndio::Config sink_config;
    sink_config.sample_spec = transcoder_config.output_sample_spec;
    sink_config.frame_length = source_config.frame_length;

    address::IoUri output_uri(arena);
    if (args.output_given) {
        if (!address::parse_io_uri(args.output_arg, output_uri)
            || !output_uri.is_file()) {
            roc_log(LogError, "invalid --output file URI");
            return 1;
        }
    }

    if (!args.output_format_given && output_uri.is_special_file()) {
        roc_log(LogError, "--output-format should be specified if --output is \"-\"");
        return 1;
    }

    core::ScopedPtr<sndio::ISink> output_sink;
    if (args.output_given) {
        if (output_uri.is_valid()) {
            output_sink.reset(backend_dispatcher.open_sink(
                                  output_uri, args.output_format_arg, sink_config),
                              arena);
        } else {
            output_sink.reset(backend_dispatcher.open_default_sink(sink_config), arena);
        }
        if (!output_sink) {
            roc_log(LogError, "can't open output: %s", args.output_arg);
            return 1;
        }
        if (output_sink->has_clock()) {
            roc_log(LogError, "unsupported output: %s", args.output_arg);
            return 1;
        }
        output_writer = output_sink.get();
    }

    pipeline::TranscoderSink transcoder(transcoder_config, output_writer, buffer_factory,
                                        arena);
    if (!transcoder.is_valid()) {
        roc_log(LogError, "can't create transcoder pipeline");
        return 1;
    }

    sndio::Pump pump(buffer_factory, *input_source, NULL, transcoder,
                     source_config.frame_length, transcoder_config.input_sample_spec,
                     sndio::Pump::ModePermanent);
    if (!pump.is_valid()) {
        roc_log(LogError, "can't create audio pump");
        return 1;
    }

    const bool ok = pump.run();

    return ok ? 0 : 1;
}
