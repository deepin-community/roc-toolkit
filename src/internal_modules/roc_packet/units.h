/*
 * Copyright (c) 2015 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

//! @file roc_packet/units.h
//! @brief Various units used in packets.

#ifndef ROC_PACKET_UNITS_H_
#define ROC_PACKET_UNITS_H_

#include "roc_core/stddefs.h"
#include "roc_core/time.h"

namespace roc {
namespace packet {

//! Packet stream identifier.
//! @remarks
//!  Identifies packet stream within session.
//!  Unique only within one session.
//!  For example, audio packet stream and repair (FEC) packet stream
//!  usually have different source identifiers.
typedef uint32_t stream_source_t;

//! Packet stream timestamp.
//! @remarks
//!  Defines position of packet contents (e.g. audio chunk) within stream.
//!  Starts from unspecified value and can wrap.
//!  Measured in sender's clock domain and clock rate.
//!  For PCM audio, stream timestamp is incremented by one every N samples,
//!  where N is the number of channels.
typedef uint32_t stream_timestamp_t;

//! Packet stream timestamp delta.
//! @remarks
//!  Signed version of stream_timestamp_t.
typedef int32_t stream_timestamp_diff_t;

//! Compute difference between two timestamps.
inline stream_timestamp_diff_t stream_timestamp_diff(const stream_timestamp_t a,
                                                     const stream_timestamp_t b) {
    return stream_timestamp_diff_t(a - b);
}

//! Check if `a` is before `b`, taking possible wrap into account.
inline bool stream_timestamp_lt(const stream_timestamp_t a, const stream_timestamp_t b) {
    return stream_timestamp_diff(a, b) < 0;
}

//! Check if `a` is before or equal to `b`, taking possible wrap into account.
inline bool stream_timestamp_le(const stream_timestamp_t a, const stream_timestamp_t b) {
    return stream_timestamp_diff(a, b) <= 0;
}

//! Packet sequence number.
//! @remarks
//!  Defines position of packet within stream.
//!  Starts from unspecified value and can wrap.
//!  Incremented by one each packet.
typedef uint16_t seqnum_t;

//! Packet sequence number delta.
//! @remarks
//!  Signed version of seqnum_t.
typedef int16_t seqnum_diff_t;

//! Compute difference between two seqnums.
inline seqnum_diff_t seqnum_diff(const seqnum_t a, const seqnum_t b) {
    return seqnum_diff_t(a - b);
}

//! Check if `a` is before `b`, taking possible wrap into account.
inline bool seqnum_lt(const seqnum_t a, const seqnum_t b) {
    return seqnum_diff(a, b) < 0;
}

//! Check if `a` is before or equal to `b`, taking possible wrap into account.
inline bool seqnum_le(const seqnum_t a, const seqnum_t b) {
    return seqnum_diff(a, b) <= 0;
}

//! FEC packet block number.
//! @remarks
//!  Defines position of FEC packet block within stream.
//!  Starts from unspecified value and can wrap.
//!  Incremented by one each block.
typedef uint16_t blknum_t;

//! FEC packet block number delta.
//! @remarks
//!  Signed version of blknum_t.
typedef int16_t blknum_diff_t;

//! Compute difference between two FEC packet block numbers.
inline blknum_diff_t blknum_diff(const blknum_t a, const blknum_t b) {
    return blknum_diff_t(a - b);
}

//! Check if `a` is before `b`, taking possible wrap into account.
inline bool blknum_lt(const blknum_t a, const blknum_t b) {
    return blknum_diff(a, b) < 0;
}

//! Check if `a` is before or equal to `b`, taking possible wrap into account.
inline bool blknum_le(const blknum_t a, const blknum_t b) {
    return blknum_diff(a, b) <= 0;
}

} // namespace packet
} // namespace roc

#endif // ROC_PACKET_UNITS_H_
