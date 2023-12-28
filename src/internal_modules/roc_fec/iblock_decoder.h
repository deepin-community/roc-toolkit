/*
 * Copyright (c) 2015 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

//! @file roc_fec/iblock_decoder.h
//! @brief FEC block decoder interface.

#ifndef ROC_FEC_IBLOCK_DECODER_H_
#define ROC_FEC_IBLOCK_DECODER_H_

#include "roc_core/slice.h"
#include "roc_core/stddefs.h"

namespace roc {
namespace fec {

//! FEC block decoder interface.
class IBlockDecoder {
public:
    virtual ~IBlockDecoder();

    //! Get the maximum number of encoding symbols for the scheme being used.
    virtual size_t max_block_length() const = 0;

    //! Start block.
    //!
    //! @remarks
    //!  Performs an initial setup for a block. Should be called before
    //!  any operations for the block.
    virtual bool begin(size_t sblen, size_t rblen, size_t payload_size) = 0;

    //! Store source or repair packet buffer for current block.
    //!
    //! @pre
    //!  This method may be called only between begin() and end() calls.
    virtual void set(size_t index, const core::Slice<uint8_t>& buffer) = 0;

    //! Repair source packet buffer.
    //!
    //! @pre
    //!  This method may be called only between begin() and end() calls.
    virtual core::Slice<uint8_t> repair(size_t index) = 0;

    //! Finish block.
    //!
    //! @remarks
    //!  Cleanups the resources allocated for the block. Should be called after
    //!  all operations for the block.
    virtual void end() = 0;
};

} // namespace fec
} // namespace roc

#endif // ROC_FEC_IBLOCK_DECODER_H_
