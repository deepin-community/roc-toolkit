/*
 * Copyright (c) 2022 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "roc_rtcp/builder.h"
#include "roc_rtcp/headers.h"

namespace roc {
namespace rtcp {

Builder::Builder(core::Slice<uint8_t>& data)
    : state_(NONE)
    , data_(data)
    , header_(NULL)
    , xr_header_(NULL)
    , cur_slice_()
    , report_written_(false)
    , cname_written_(false) {
}

void Builder::begin_sr(const header::SenderReportPacket& sr) {
    roc_panic_if_not(state_ == NONE);

    cur_slice_ = data_.subslice(data_.size(), data_.size());
    header::SenderReportPacket* p = (header::SenderReportPacket*)cur_slice_.extend(
        sizeof(header::SenderReportPacket));
    memcpy(p, &sr, sizeof(sr));
    header_ = &p->header();

    state_ = SR_HEAD;
    report_written_ = true;
}

void Builder::add_sr_report(const header::ReceptionReportBlock& report) {
    roc_panic_if_not(state_ == SR_HEAD || state_ == SR_REPORT);

    add_report_(report);

    state_ = SR_REPORT;
}

void Builder::end_sr() {
    roc_panic_if_not(state_ == SR_HEAD || state_ == SR_REPORT);

    end_packet_();
}

void Builder::begin_rr(const header::ReceiverReportPacket& rr) {
    roc_panic_if_not(state_ == NONE);

    cur_slice_ = data_.subslice(data_.size(), data_.size());
    header::ReceiverReportPacket* p = (header::ReceiverReportPacket*)cur_slice_.extend(
        sizeof(header::ReceiverReportPacket));
    memcpy(p, &rr, sizeof(rr));
    header_ = &p->header();

    state_ = RR_HEAD;
    report_written_ = true;
}

void Builder::add_rr_report(const header::ReceptionReportBlock& report) {
    roc_panic_if_not(state_ == RR_HEAD || state_ == RR_REPORT);

    add_report_(report);

    state_ = RR_REPORT;
}

void Builder::end_rr() {
    roc_panic_if_not(state_ == RR_REPORT || state_ == RR_HEAD);

    end_packet_();
}

void Builder::begin_sdes() {
    roc_panic_if_not(state_ == NONE);

    roc_panic_if_msg(!report_written_,
                     "rtcp builder: sdes should come only after sr or rr");

    cur_slice_ = data_.subslice(data_.size(), data_.size());
    header::SdesPacket* p =
        (header::SdesPacket*)cur_slice_.extend(sizeof(header::SdesPacket));
    p->reset();
    header_ = &p->header();

    state_ = SDES_HEAD;
}

void Builder::begin_sdes_chunk(const SdesChunk& chunk) {
    roc_panic_if_not(state_ == SDES_HEAD);

    header::SdesChunkHeader* p =
        (header::SdesChunkHeader*)cur_slice_.extend(sizeof(header::SdesChunkHeader));
    p->reset();
    p->set_ssrc(chunk.ssrc);
    header_->inc_counter();

    state_ = SDES_CHUNK;
    cname_written_ = false;
}

void Builder::add_sdes_item(const SdesItem& item) {
    roc_panic_if_not(state_ == SDES_CHUNK);

    roc_panic_if_msg(!item.text, "rtcp builder: item text can't be null");

    const size_t text_size = strnlen(item.text, header::SdesItemHeader::MaxTextLen);
    const size_t total_size = sizeof(header::SdesItemHeader) + text_size;

    header::SdesItemHeader* p = (header::SdesItemHeader*)cur_slice_.extend(total_size);
    p->reset();
    p->set_type(item.type);
    p->set_text_len(text_size);

    if (text_size) {
        memcpy(p->text(), item.text, text_size);
    }

    if (item.type == header::SDES_CNAME) {
        roc_panic_if_msg(
            cname_written_,
            "rtcp builder: each sdes chunk should have one and only one cname item");

        cname_written_ = true;
    }
}

void Builder::end_sdes_chunk() {
    roc_panic_if_not(state_ == SDES_CHUNK);

    roc_panic_if_msg(
        !cname_written_,
        "rtcp builder: each sdes chunk should have one and only one cname item");

    // Adds at least one byte with zero value and aligns the end with 32 bit border.
    size_t padding_size = header::padding_len(cur_slice_.size(), 1);
    uint8_t* p = cur_slice_.extend(padding_size);
    memset(p, 0, padding_size);

    state_ = SDES_HEAD;
}

void Builder::end_sdes() {
    roc_panic_if_not(state_ == SDES_HEAD);

    end_packet_();
}

void Builder::begin_bye() {
    roc_panic_if_not(state_ == NONE);

    roc_panic_if_msg(!report_written_,
                     "rtcp builder: bye should come only after sr or rr");

    cur_slice_ = data_.subslice(data_.size(), data_.size());
    header::ByePacket* p =
        (header::ByePacket*)cur_slice_.extend(sizeof(header::ByePacket));
    p->reset();
    header_ = &p->header();

    state_ = BYE_HEAD;
}

void Builder::add_bye_ssrc(const packet::stream_source_t ssrc) {
    roc_panic_if_not(state_ == BYE_HEAD || state_ == BYE_SSRC);

    header::ByeSourceHeader* p =
        (header::ByeSourceHeader*)cur_slice_.extend(sizeof(header::ByeSourceHeader));
    p->reset();
    p->set_ssrc(ssrc);
    header_->inc_counter();

    state_ = BYE_SSRC;
}

void Builder::add_bye_reason(const char* reason) {
    roc_panic_if_not(state_ == BYE_SSRC);

    roc_panic_if_msg(!reason, "rtcp builder: bye reason can't be null");

    const size_t text_size = strnlen(reason, header::ByeReasonHeader::MaxTextLen);
    const size_t total_size = sizeof(header::ByeReasonHeader) + text_size;
    const size_t padding_size = header::padding_len(total_size, 0);

    header::ByeReasonHeader* p =
        (header::ByeReasonHeader*)cur_slice_.extend(total_size + padding_size);
    p->reset();
    p->set_text_len(text_size);

    if (text_size) {
        memcpy(p->text(), reason, text_size);
    }
    if (padding_size) {
        memset(p->text() + text_size, 0, padding_size);
    }

    state_ = BYE_REASON;
}

void Builder::end_bye() {
    roc_panic_if_not(state_ == BYE_SSRC || state_ == BYE_REASON);

    end_packet_();
}

void Builder::begin_xr(const header::XrPacket& xr) {
    roc_panic_if_not(state_ == NONE);

    roc_panic_if_msg(!report_written_,
                     "rtcp builder: xr should come only after sr or rr");

    cur_slice_ = data_.subslice(data_.size(), data_.size());
    header::XrPacket* p = (header::XrPacket*)cur_slice_.extend(sizeof(header::XrPacket));
    memcpy(p, &xr, sizeof(xr));
    header_ = &p->header();

    state_ = XR_HEAD;
}

void Builder::add_xr_rrtr(const header::XrRrtrBlock& rrtr) {
    roc_panic_if_not(state_ == XR_HEAD);

    header::XrRrtrBlock* p =
        (header::XrRrtrBlock*)cur_slice_.extend(sizeof(header::XrRrtrBlock));
    memcpy(p, &rrtr, sizeof(rrtr));
    xr_header_ = &p->header();
    xr_header_->set_len_bytes(sizeof(rrtr));
}

void Builder::begin_xr_dlrr(const header::XrDlrrBlock& dlrr) {
    roc_panic_if_not(state_ == XR_HEAD);

    header::XrDlrrBlock* p =
        (header::XrDlrrBlock*)cur_slice_.extend(sizeof(header::XrDlrrBlock));
    memcpy(p, &dlrr, sizeof(dlrr));
    xr_header_ = &p->header();

    state_ = XR_DLRR_HEAD;
}

void Builder::add_xr_dlrr_report(const header::XrDlrrSubblock& report) {
    roc_panic_if_not(state_ == XR_DLRR_HEAD || state_ == XR_DLRR_REPORT);

    header::XrDlrrSubblock* p =
        (header::XrDlrrSubblock*)cur_slice_.extend(sizeof(header::XrDlrrSubblock));
    memcpy(p, &report, sizeof(report));

    state_ = XR_DLRR_REPORT;
}

void Builder::end_xr_dlrr() {
    roc_panic_if_not(state_ == XR_DLRR_REPORT);

    xr_header_->set_len_bytes(size_t(cur_slice_.data_end() - (uint8_t*)xr_header_));

    state_ = XR_HEAD;
}

void Builder::end_xr() {
    roc_panic_if_not(state_ == XR_HEAD);

    end_packet_();
}

void Builder::add_report_(const header::ReceptionReportBlock& report) {
    header::ReceptionReportBlock* p =
        (header::ReceptionReportBlock*)cur_slice_.extend(sizeof(report));
    memcpy(p, &report, sizeof(report));
    header_->set_len_bytes(cur_slice_.size());
    header_->inc_counter();
}

void Builder::end_packet_() {
    header_->set_len_bytes(cur_slice_.size());
    header_ = NULL;

    data_.extend(cur_slice_.size());
    cur_slice_ = core::Slice<uint8_t>();

    state_ = NONE;
}

} // namespace rtcp
} // namespace roc
