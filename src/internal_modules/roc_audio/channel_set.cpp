/*
 * Copyright (c) 2023 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "roc_audio/channel_set.h"
#include "roc_core/panic.h"

namespace roc {
namespace audio {

ChannelSet::ChannelSet()
    : num_chans_(0)
    , first_chan_(0)
    , last_chan_(0)
    , layout_(ChanLayout_None)
    , order_(ChanOrder_None) {
    memset(words_, 0, sizeof(words_));
}

ChannelSet::ChannelSet(const ChannelLayout layout,
                       ChannelOrder order,
                       const ChannelMask mask)
    : num_chans_(0)
    , first_chan_(0)
    , last_chan_(0)
    , layout_(layout)
    , order_(order) {
    if (layout == ChanLayout_None) {
        roc_panic("channel set: invalid channel layout");
    }

    if (!(layout == ChanLayout_Surround ? order != ChanOrder_None
                                        : order == ChanOrder_None)) {
        roc_panic("channel set: invalid channel order: layout=%s order=%s",
                  channel_layout_to_str(layout), channel_order_to_str(order));
    }

    if (mask == 0) {
        roc_panic("channel set: invalid channel mask: layout=%s mask=0x%lx",
                  channel_layout_to_str(layout), (unsigned long)mask);
    }

    words_[0] = mask;
    for (size_t n = 1; n < NumWords; n++) {
        words_[n] = 0;
    }

    update_();
}

bool ChannelSet::operator==(const ChannelSet& other) const {
    return layout_ == other.layout_ && order_ == other.order_
        && memcmp(words_, other.words_, sizeof(words_)) == 0;
}

bool ChannelSet::operator!=(const ChannelSet& other) const {
    return !(*this == other);
}

bool ChannelSet::is_valid() const {
    switch (layout_) {
    case ChanLayout_None:
        return false;

    case ChanLayout_Surround:
        if (order_ == ChanOrder_None) {
            return false;
        }
        if (num_chans_ == 0) {
            return false;
        }
        break;

    case ChanLayout_Multitrack:
        if (order_ != ChanOrder_None) {
            return false;
        }
        if (num_chans_ == 0) {
            return false;
        }
        break;
    }

    return true;
}

void ChannelSet::clear() {
    layout_ = ChanLayout_None;
    order_ = ChanOrder_None;

    memset(words_, 0, sizeof(words_));

    update_();
}

ChannelLayout ChannelSet::layout() const {
    return layout_;
}

void ChannelSet::set_layout(const ChannelLayout layout) {
    if (layout == ChanLayout_None) {
        roc_panic("channel set: invalid channel layout");
    }

    layout_ = layout;
}

ChannelOrder ChannelSet::order() const {
    return order_;
}

void ChannelSet::set_order(const ChannelOrder order) {
    order_ = order;
}

size_t ChannelSet::max_channels() {
    return MaxChannels;
}

size_t ChannelSet::num_channels() const {
    return num_chans_;
}

bool ChannelSet::has_channel(const size_t n) const {
    if (n >= MaxChannels) {
        roc_panic("channel set: subscript out of range: channel=%lu max_channels=%lu",
                  (unsigned long)n, (unsigned long)MaxChannels);
    }

    return words_[n / WordBits] & (word_t(1) << (n % WordBits));
}

size_t ChannelSet::first_channel() const {
    if (num_chans_ == 0) {
        roc_panic("channel set: attempt to access empty set");
    }

    return first_chan_;
}

size_t ChannelSet::last_channel() const {
    if (num_chans_ == 0) {
        roc_panic("channel set: attempt to access empty set");
    }

    return last_chan_;
}

bool ChannelSet::is_subset(ChannelMask mask) const {
    if (last_chan_ >= WordBits) {
        return false;
    }

    return ((words_[0] & mask) == words_[0]);
}

bool ChannelSet::is_superset(ChannelMask mask) const {
    if (last_chan_ >= WordBits) {
        return true;
    }

    return ((words_[0] & mask) == mask);
}

void ChannelSet::set_channel(const size_t n, const bool enabled) {
    if (n >= MaxChannels) {
        roc_panic("channel set: subscript out of range: channel=%lu max_channels=%lu",
                  (unsigned long)n, (unsigned long)MaxChannels);
    }

    if (enabled) {
        words_[n / WordBits] |= (word_t(1) << (n % WordBits));
    } else {
        words_[n / WordBits] &= ~(word_t(1) << (n % WordBits));
    }

    update_();
}

void ChannelSet::set_channel_range(const size_t from,
                                   const size_t to,
                                   const bool enabled) {
    if (from >= MaxChannels || to >= MaxChannels) {
        roc_panic("channel set: subscript out of range: from=%lu to=%lu max_channels=%lu",
                  (unsigned long)from, (unsigned long)to, (unsigned long)MaxChannels);
    }
    if (from > to) {
        roc_panic("channel set: invalid range: from=%lu to=%lu", (unsigned long)from,
                  (unsigned long)to);
    }

    for (size_t n = from; n <= to; n++) {
        if (enabled) {
            words_[n / WordBits] |= (word_t(1) << (n % WordBits));
        } else {
            words_[n / WordBits] &= ~(word_t(1) << (n % WordBits));
        }
    }

    update_();
}

void ChannelSet::set_channel_mask(const ChannelMask mask) {
    if (mask == 0) {
        roc_panic("channel set: invalid channel mask");
    }

    words_[0] = mask;

    for (size_t n = 1; n < NumWords; n++) {
        words_[n] = 0;
    }

    update_();
}

void ChannelSet::bitwise_and(const ChannelSet& other) {
    for (size_t n = 0; n < NumWords; n++) {
        words_[n] &= other.words_[n];
    }

    update_();
}

void ChannelSet::bitwise_or(const ChannelSet& other) {
    for (size_t n = 0; n < NumWords; n++) {
        words_[n] |= other.words_[n];
    }

    update_();
}

void ChannelSet::bitwise_xor(const ChannelSet& other) {
    for (size_t n = 0; n < NumWords; n++) {
        words_[n] ^= other.words_[n];
    }

    update_();
}

size_t ChannelSet::num_bytes() const {
    return NumWords * WordBytes;
}

uint8_t ChannelSet::byte_at(size_t n) const {
    if (n >= num_bytes()) {
        roc_panic("channel set: subscript out of range: byte=%lu num_bytes=%lu",
                  (unsigned long)n, (unsigned long)num_bytes());
    }

    return (words_[n / WordBytes] >> ((n % WordBytes) * 8)) & 0xff;
}

void ChannelSet::update_() {
    num_chans_ = first_chan_ = last_chan_ = 0;

    bool has_first = false;
    size_t nch = 0;

    for (size_t w = 0; w < NumWords; w++) {
        if (words_[w] != 0) {
            for (size_t b = 0; b < WordBits; b++) {
                if (words_[w] & (word_t(1) << b)) {
                    num_chans_++;
                    if (!has_first) {
                        has_first = true;
                        first_chan_ = nch;
                    }
                    last_chan_ = nch;
                }
                nch++;
            }
        } else {
            nch += WordBits;
        }
    }
}

} // namespace audio
} // namespace roc
