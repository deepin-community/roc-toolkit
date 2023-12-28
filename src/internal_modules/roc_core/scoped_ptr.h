/*
 * Copyright (c) 2015 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

//! @file roc_core/scoped_ptr.h
//! @brief Unique ownrship pointer.

#ifndef ROC_CORE_SCOPED_PTR_H_
#define ROC_CORE_SCOPED_PTR_H_

#include "roc_core/allocation_policy.h"
#include "roc_core/iarena.h"
#include "roc_core/noncopyable.h"
#include "roc_core/optional.h"
#include "roc_core/panic.h"
#include "roc_core/stddefs.h"

namespace roc {
namespace core {

//! Unique ownrship pointer.
//!
//! @tparam T defines pointee type. It may be const.
//! @tparam AllocationPolicy defies (de)allocation policy.
//!
//! When ScopedPtr is destroyed or reset, it invokes AllocationPolicy::destroy()
//! to destroy the owned object.
template <class T, class AllocationPolicy = ArenaAllocation>
class ScopedPtr : public NonCopyable<> {
public:
    //! Initialize null pointer.
    ScopedPtr()
        : ptr_(NULL) {
    }

    //! Initialize from a raw pointer.
    ScopedPtr(T* ptr, const AllocationPolicy& policy)
        : ptr_(ptr) {
        policy_.reset(new (policy_) AllocationPolicy(policy));
    }

    //! Destroy object.
    ~ScopedPtr() {
        reset();
    }

    //! Reset pointer to null.
    void reset() {
        if (ptr_ != NULL) {
            policy_->destroy(*ptr_);
            policy_.reset();
            ptr_ = NULL;
        }
    }

    //! Reset pointer to a new value.
    void reset(T* new_ptr, const AllocationPolicy& new_policy) {
        if (new_ptr != ptr_) {
            reset();

            ptr_ = new_ptr;
            policy_.reset(new (policy_) AllocationPolicy(new_policy));
        }
    }

    //! Get underlying pointer and pass ownership to the caller.
    T* release() {
        T* ret = ptr_;
        if (ret == NULL) {
            roc_panic("scoped ptr: attempting to release a null pointer");
        }

        ptr_ = NULL;
        policy_.reset();

        return ret;
    }

    //! Get underlying pointer.
    T* get() const {
        return ptr_;
    }

    //! Get underlying pointer.
    T* operator->() const {
        return ptr_;
    }

    //! Get underlying reference.
    T& operator*() const {
        if (ptr_ == NULL) {
            roc_panic("scoped ptr: attempting to dereference a null pointer");
        }
        return *ptr_;
    }

    //! Convert to bool.
    operator const struct unspecified_bool *() const {
        return (unspecified_bool*)ptr_;
    }

private:
    T* ptr_;
    Optional<AllocationPolicy> policy_;
};

} // namespace core
} // namespace roc

#endif // ROC_CORE_SCOPED_PTR_H_
