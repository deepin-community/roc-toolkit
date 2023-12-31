/*
 * Copyright (c) 2017 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "roc_packet/router.h"
#include "roc_core/log.h"
#include "roc_core/panic.h"
#include "roc_status/status_code.h"

namespace roc {
namespace packet {

Router::Router(core::IArena& arena)
    : routes_(arena) {
}

bool Router::add_route(IWriter& writer, unsigned flags) {
    Route r;
    r.writer = &writer;
    r.flags = flags;
    r.source = 0;
    r.has_source = false;

    if (!routes_.push_back(r)) {
        roc_log(LogError, "router: can't allocate route");
        return false;
    }

    return true;
}

status::StatusCode Router::write(const PacketPtr& packet) {
    if (!packet) {
        roc_panic("router: unexpected null packet");
    }

    for (size_t n = 0; n < routes_.size(); n++) {
        Route& r = routes_[n];

        const unsigned pkt_flags = packet->flags();

        if (r.flags != 0) {
            if ((r.flags & pkt_flags) != r.flags) {
                continue;
            }
        }

        const stream_source_t pkt_source = packet->source();

        if (r.has_source) {
            if (r.source != pkt_source) {
                continue;
            }
        } else {
            r.source = pkt_source;
            r.has_source = true;

            roc_log(LogDebug, "router: detected new stream: source=%lu flags=0x%x",
                    (unsigned long)r.source, (unsigned int)r.flags);
        }

        return r.writer->write(packet);
    }

    roc_log(LogDebug, "router: can't route packet, dropping");
    // TODO(gh-183): return status
    return status::StatusOK;
}

} // namespace packet
} // namespace roc
