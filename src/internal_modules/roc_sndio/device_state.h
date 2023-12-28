/*
 * Copyright (c) 2022 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

//! @file roc_sndio/device_state.h
//! @brief Device state.

#ifndef ROC_SNDIO_DEVICE_STATE_H_
#define ROC_SNDIO_DEVICE_STATE_H_

namespace roc {
namespace sndio {

//! Device state.
enum DeviceState {
    //! Device is running and active.
    //! It is producing some sound.
    DeviceState_Active,

    //! Device is running but is inactive.
    //! It is producing silence. It may be safely paused.
    DeviceState_Idle,

    //! Device is paused.
    //! It's not producing anything.
    DeviceState_Paused
};

//! Convert device state to string.
const char* device_state_to_str(DeviceState state);

} // namespace sndio
} // namespace roc

#endif // ROC_SNDIO_DEVICE_STATE_H_
