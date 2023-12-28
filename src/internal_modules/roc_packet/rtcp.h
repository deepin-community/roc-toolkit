/*
 * Copyright (c) 2022 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

//! @file roc_packet/rtcp.h
//! @brief RTCP compound packet.

#ifndef ROC_PACKET_RTCP_H_
#define ROC_PACKET_RTCP_H_

#include "roc_core/slice.h"
#include "roc_core/stddefs.h"

namespace roc {
namespace packet {

//! RTCP compound packet.
struct RTCP {
    //! Packet data.
    //! RTCP compound packets does not contain any pre-parsed data.
    //! Use rtcp::Traverser and rtcp::Builder to work with packet.
    core::Slice<uint8_t> data;

    //! Construct zero RTP packet.
    RTCP();
};

} // namespace packet
} // namespace roc

#endif // ROC_PACKET_RTCP_H_
