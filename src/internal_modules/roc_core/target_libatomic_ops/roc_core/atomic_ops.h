/*
 * THIS FILE IS AUTO-GENERATED USING `atomic_ops_gen.py'.
 */

#ifndef ROC_CORE_ATOMIC_OPS_H_
#define ROC_CORE_ATOMIC_OPS_H_

#include "roc_core/stddefs.h"

#include <atomic_ops.h>

namespace roc {
namespace core {

//! Atomic operations.
class AtomicOps {
public:
    #ifdef AO_HAVE_nop_read
    //! Acquire memory barrier.
    static inline void fence_acquire() {
        AO_nop_read();
    }
    #endif // AO_HAVE_nop_read

    #ifdef AO_HAVE_nop_write
    //! Release memory barrier.
    static inline void fence_release() {
        AO_nop_write();
    }
    #endif // AO_HAVE_nop_write

    #ifdef AO_HAVE_nop_full
    //! Full memory barrier.
    static inline void fence_seq_cst() {
        AO_nop_full();
    }
    #endif // AO_HAVE_nop_full

    // overloads for unsigned char

    #ifdef AO_HAVE_char_load
    //! Atomic load (no barrier).
    static inline unsigned char load_relaxed(unsigned char const& var) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (unsigned char)AO_char_load((unsigned char const*)&var);
    }
    #endif // AO_HAVE_char_load

    #ifdef AO_HAVE_char_store
    //! Atomic store (no barrier).
    static inline void store_relaxed(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_char_store((unsigned char*)&var, (unsigned char)val);
    }
    #endif // AO_HAVE_char_store

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic exchange (no barrier).
    static inline unsigned char exchange_relaxed(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic compare-and-swap (no barrier).
    static inline bool compare_exchange_relaxed(
          unsigned char& var, unsigned char& exp, unsigned char des) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char old = AO_char_fetch_compare_and_swap(
          (unsigned char*)&var, (unsigned char)exp, (unsigned char)des);
        const bool ret = ((unsigned char)exp == old);
        exp = (unsigned char)old;
        return ret;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_fetch_and_add
    //! Atomic fetch-add (no barrier).
    static inline unsigned char fetch_add_relaxed(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (unsigned char)(
            AO_char_fetch_and_add((unsigned char*)&var, (unsigned char)val));
    }
    #endif // AO_HAVE_char_fetch_and_add

    #ifdef AO_HAVE_char_fetch_and_add
    //! Atomic fetch-sub (no barrier).
    static inline unsigned char fetch_sub_relaxed(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (unsigned char)(
            AO_char_fetch_and_add((unsigned char*)&var, (unsigned char)-val));
    }
    #endif // AO_HAVE_char_fetch_and_add

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic fetch-and (no barrier).
    static inline unsigned char fetch_and_relaxed(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         prev & (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic fetch-or (no barrier).
    static inline unsigned char fetch_or_relaxed(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         prev | (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic fetch-xor (no barrier).
    static inline unsigned char fetch_xor_relaxed(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         prev ^ (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_load_acquire
    //! Atomic load (acquire barrier).
    static inline unsigned char load_acquire(unsigned char const& var) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (unsigned char)AO_char_load_acquire((unsigned char const*)&var);
    }
    #endif // AO_HAVE_char_load_acquire

    #ifdef AO_HAVE_char_fetch_compare_and_swap_acquire
    //! Atomic exchange (acquire barrier).
    static inline unsigned char exchange_acquire(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_acquire((unsigned char*)&var, prev,
                                                         (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_char_fetch_compare_and_swap_acquire
    //! Atomic compare-and-swap (acquire barrier).
    static inline bool compare_exchange_acquire(
          unsigned char& var, unsigned char& exp, unsigned char des) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char old = AO_char_fetch_compare_and_swap_acquire(
          (unsigned char*)&var, (unsigned char)exp, (unsigned char)des);
        const bool ret = ((unsigned char)exp == old);
        exp = (unsigned char)old;
        return ret;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_char_fetch_and_add_acquire
    //! Atomic fetch-add (acquire barrier).
    static inline unsigned char fetch_add_acquire(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (unsigned char)(
            AO_char_fetch_and_add_acquire((unsigned char*)&var, (unsigned char)val));
    }
    #endif // AO_HAVE_char_fetch_and_add_acquire

    #ifdef AO_HAVE_char_fetch_and_add_acquire
    //! Atomic fetch-sub (acquire barrier).
    static inline unsigned char fetch_sub_acquire(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (unsigned char)(
            AO_char_fetch_and_add_acquire((unsigned char*)&var, (unsigned char)-val));
    }
    #endif // AO_HAVE_char_fetch_and_add_acquire

    #ifdef AO_HAVE_char_fetch_compare_and_swap_acquire
    //! Atomic fetch-and (acquire barrier).
    static inline unsigned char fetch_and_acquire(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_acquire((unsigned char*)&var, prev,
                                                         prev & (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_char_fetch_compare_and_swap_acquire
    //! Atomic fetch-or (acquire barrier).
    static inline unsigned char fetch_or_acquire(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_acquire((unsigned char*)&var, prev,
                                                         prev | (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_char_fetch_compare_and_swap_acquire
    //! Atomic fetch-xor (acquire barrier).
    static inline unsigned char fetch_xor_acquire(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_acquire((unsigned char*)&var, prev,
                                                         prev ^ (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_char_store_release
    //! Atomic store (release barrier).
    static inline void store_release(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_char_store_release((unsigned char*)&var, (unsigned char)val);
    }
    #endif // AO_HAVE_char_store_release

    #ifdef AO_HAVE_char_fetch_compare_and_swap_release
    //! Atomic exchange (release barrier).
    static inline unsigned char exchange_release(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_release((unsigned char*)&var, prev,
                                                         (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_release

    #ifdef AO_HAVE_char_fetch_compare_and_swap_release
    //! Atomic compare-and-swap (release barrier).
    static inline bool compare_exchange_release(
          unsigned char& var, unsigned char& exp, unsigned char des) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char old = AO_char_fetch_compare_and_swap_release(
          (unsigned char*)&var, (unsigned char)exp, (unsigned char)des);
        const bool ret = ((unsigned char)exp == old);
        exp = (unsigned char)old;
        return ret;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_release

    #ifdef AO_HAVE_char_fetch_and_add_release
    //! Atomic fetch-add (release barrier).
    static inline unsigned char fetch_add_release(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (unsigned char)(
            AO_char_fetch_and_add_release((unsigned char*)&var, (unsigned char)val));
    }
    #endif // AO_HAVE_char_fetch_and_add_release

    #ifdef AO_HAVE_char_fetch_and_add_release
    //! Atomic fetch-sub (release barrier).
    static inline unsigned char fetch_sub_release(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (unsigned char)(
            AO_char_fetch_and_add_release((unsigned char*)&var, (unsigned char)-val));
    }
    #endif // AO_HAVE_char_fetch_and_add_release

    #ifdef AO_HAVE_char_fetch_compare_and_swap_release
    //! Atomic fetch-and (release barrier).
    static inline unsigned char fetch_and_release(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_release((unsigned char*)&var, prev,
                                                         prev & (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_release

    #ifdef AO_HAVE_char_fetch_compare_and_swap_release
    //! Atomic fetch-or (release barrier).
    static inline unsigned char fetch_or_release(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_release((unsigned char*)&var, prev,
                                                         prev | (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_release

    #ifdef AO_HAVE_char_fetch_compare_and_swap_release
    //! Atomic fetch-xor (release barrier).
    static inline unsigned char fetch_xor_release(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_release((unsigned char*)&var, prev,
                                                         prev ^ (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_release

    #ifdef AO_HAVE_char_fetch_compare_and_swap_full
    //! Atomic exchange (acquire-release barrier).
    static inline unsigned char exchange_acq_rel(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_full((unsigned char*)&var, prev,
                                                         (unsigned char)val);
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_full

    #ifdef AO_HAVE_char_fetch_compare_and_swap_full
    //! Atomic compare-and-swap (acquire-release barrier).
    static inline bool compare_exchange_acq_rel(
          unsigned char& var, unsigned char& exp, unsigned char des) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char old = AO_char_fetch_compare_and_swap_full(
          (unsigned char*)&var, (unsigned char)exp, (unsigned char)des);
        const bool ret = ((unsigned char)exp == old);
        exp = (unsigned char)old;
        return ret;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_full

    #ifdef AO_HAVE_char_load_full
    //! Atomic load (full barrier).
    static inline unsigned char load_seq_cst(unsigned char const& var) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (unsigned char)AO_char_load_full((unsigned char const*)&var);
    }
    #endif // AO_HAVE_char_load_full

    #ifdef AO_HAVE_char_store_full
    //! Atomic store (full barrier).
    static inline void store_seq_cst(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_char_store_full((unsigned char*)&var, (unsigned char)val);
    }
    #endif // AO_HAVE_char_store_full

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic exchange (full barrier).
    static inline unsigned char exchange_seq_cst(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_nop_full();
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         (unsigned char)val);
            AO_nop_full();
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic compare-and-swap (full barrier).
    static inline bool compare_exchange_seq_cst(
          unsigned char& var, unsigned char& exp, unsigned char des) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_nop_full();
        unsigned char old = AO_char_fetch_compare_and_swap(
          (unsigned char*)&var, (unsigned char)exp, (unsigned char)des);
        const bool ret = ((unsigned char)exp == old);
        if (ret) {
            AO_nop_full();
        }
        exp = (unsigned char)old;
        return ret;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_fetch_and_add_full
    //! Atomic fetch-add (full barrier).
    static inline unsigned char fetch_add_seq_cst(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (unsigned char)(
            AO_char_fetch_and_add_full((unsigned char*)&var, (unsigned char)val));
    }
    #endif // AO_HAVE_char_fetch_and_add_full

    #ifdef AO_HAVE_char_fetch_and_add_full
    //! Atomic fetch-sub (full barrier).
    static inline unsigned char fetch_sub_seq_cst(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (unsigned char)(
            AO_char_fetch_and_add_full((unsigned char*)&var, (unsigned char)-val));
    }
    #endif // AO_HAVE_char_fetch_and_add_full

    #ifdef AO_HAVE_char_fetch_compare_and_swap_full
    //! Atomic fetch-and (full barrier).
    static inline unsigned char fetch_and_seq_cst(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_nop_full();
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         prev & (unsigned char)val);
            AO_nop_full();
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_full

    #ifdef AO_HAVE_char_fetch_compare_and_swap_full
    //! Atomic fetch-or (full barrier).
    static inline unsigned char fetch_or_seq_cst(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_nop_full();
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         prev | (unsigned char)val);
            AO_nop_full();
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_full

    #ifdef AO_HAVE_char_fetch_compare_and_swap_full
    //! Atomic fetch-xor (full barrier).
    static inline unsigned char fetch_xor_seq_cst(unsigned char& var, unsigned char val) {
        struct TypeCheck {
            int f : sizeof(unsigned char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_nop_full();
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         prev ^ (unsigned char)val);
            AO_nop_full();
        } while (curr != prev);
        return (unsigned char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_full

    // overloads for char

    #ifdef AO_HAVE_char_load
    //! Atomic load (no barrier).
    static inline char load_relaxed(char const& var) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (char)AO_char_load((unsigned char const*)&var);
    }
    #endif // AO_HAVE_char_load

    #ifdef AO_HAVE_char_store
    //! Atomic store (no barrier).
    static inline void store_relaxed(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_char_store((unsigned char*)&var, (unsigned char)val);
    }
    #endif // AO_HAVE_char_store

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic exchange (no barrier).
    static inline char exchange_relaxed(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic compare-and-swap (no barrier).
    static inline bool compare_exchange_relaxed(
          char& var, char& exp, char des) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char old = AO_char_fetch_compare_and_swap(
          (unsigned char*)&var, (unsigned char)exp, (unsigned char)des);
        const bool ret = ((unsigned char)exp == old);
        exp = (char)old;
        return ret;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_fetch_and_add
    //! Atomic fetch-add (no barrier).
    static inline char fetch_add_relaxed(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (char)(
            AO_char_fetch_and_add((unsigned char*)&var, (unsigned char)val));
    }
    #endif // AO_HAVE_char_fetch_and_add

    #ifdef AO_HAVE_char_fetch_and_add
    //! Atomic fetch-sub (no barrier).
    static inline char fetch_sub_relaxed(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (char)(
            AO_char_fetch_and_add((unsigned char*)&var, (unsigned char)-val));
    }
    #endif // AO_HAVE_char_fetch_and_add

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic fetch-and (no barrier).
    static inline char fetch_and_relaxed(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         prev & (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic fetch-or (no barrier).
    static inline char fetch_or_relaxed(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         prev | (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic fetch-xor (no barrier).
    static inline char fetch_xor_relaxed(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         prev ^ (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_load_acquire
    //! Atomic load (acquire barrier).
    static inline char load_acquire(char const& var) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (char)AO_char_load_acquire((unsigned char const*)&var);
    }
    #endif // AO_HAVE_char_load_acquire

    #ifdef AO_HAVE_char_fetch_compare_and_swap_acquire
    //! Atomic exchange (acquire barrier).
    static inline char exchange_acquire(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_acquire((unsigned char*)&var, prev,
                                                         (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_char_fetch_compare_and_swap_acquire
    //! Atomic compare-and-swap (acquire barrier).
    static inline bool compare_exchange_acquire(
          char& var, char& exp, char des) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char old = AO_char_fetch_compare_and_swap_acquire(
          (unsigned char*)&var, (unsigned char)exp, (unsigned char)des);
        const bool ret = ((unsigned char)exp == old);
        exp = (char)old;
        return ret;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_char_fetch_and_add_acquire
    //! Atomic fetch-add (acquire barrier).
    static inline char fetch_add_acquire(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (char)(
            AO_char_fetch_and_add_acquire((unsigned char*)&var, (unsigned char)val));
    }
    #endif // AO_HAVE_char_fetch_and_add_acquire

    #ifdef AO_HAVE_char_fetch_and_add_acquire
    //! Atomic fetch-sub (acquire barrier).
    static inline char fetch_sub_acquire(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (char)(
            AO_char_fetch_and_add_acquire((unsigned char*)&var, (unsigned char)-val));
    }
    #endif // AO_HAVE_char_fetch_and_add_acquire

    #ifdef AO_HAVE_char_fetch_compare_and_swap_acquire
    //! Atomic fetch-and (acquire barrier).
    static inline char fetch_and_acquire(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_acquire((unsigned char*)&var, prev,
                                                         prev & (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_char_fetch_compare_and_swap_acquire
    //! Atomic fetch-or (acquire barrier).
    static inline char fetch_or_acquire(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_acquire((unsigned char*)&var, prev,
                                                         prev | (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_char_fetch_compare_and_swap_acquire
    //! Atomic fetch-xor (acquire barrier).
    static inline char fetch_xor_acquire(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_acquire((unsigned char*)&var, prev,
                                                         prev ^ (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_char_store_release
    //! Atomic store (release barrier).
    static inline void store_release(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_char_store_release((unsigned char*)&var, (unsigned char)val);
    }
    #endif // AO_HAVE_char_store_release

    #ifdef AO_HAVE_char_fetch_compare_and_swap_release
    //! Atomic exchange (release barrier).
    static inline char exchange_release(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_release((unsigned char*)&var, prev,
                                                         (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_release

    #ifdef AO_HAVE_char_fetch_compare_and_swap_release
    //! Atomic compare-and-swap (release barrier).
    static inline bool compare_exchange_release(
          char& var, char& exp, char des) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char old = AO_char_fetch_compare_and_swap_release(
          (unsigned char*)&var, (unsigned char)exp, (unsigned char)des);
        const bool ret = ((unsigned char)exp == old);
        exp = (char)old;
        return ret;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_release

    #ifdef AO_HAVE_char_fetch_and_add_release
    //! Atomic fetch-add (release barrier).
    static inline char fetch_add_release(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (char)(
            AO_char_fetch_and_add_release((unsigned char*)&var, (unsigned char)val));
    }
    #endif // AO_HAVE_char_fetch_and_add_release

    #ifdef AO_HAVE_char_fetch_and_add_release
    //! Atomic fetch-sub (release barrier).
    static inline char fetch_sub_release(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (char)(
            AO_char_fetch_and_add_release((unsigned char*)&var, (unsigned char)-val));
    }
    #endif // AO_HAVE_char_fetch_and_add_release

    #ifdef AO_HAVE_char_fetch_compare_and_swap_release
    //! Atomic fetch-and (release barrier).
    static inline char fetch_and_release(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_release((unsigned char*)&var, prev,
                                                         prev & (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_release

    #ifdef AO_HAVE_char_fetch_compare_and_swap_release
    //! Atomic fetch-or (release barrier).
    static inline char fetch_or_release(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_release((unsigned char*)&var, prev,
                                                         prev | (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_release

    #ifdef AO_HAVE_char_fetch_compare_and_swap_release
    //! Atomic fetch-xor (release barrier).
    static inline char fetch_xor_release(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_release((unsigned char*)&var, prev,
                                                         prev ^ (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_release

    #ifdef AO_HAVE_char_fetch_compare_and_swap_full
    //! Atomic exchange (acquire-release barrier).
    static inline char exchange_acq_rel(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap_full((unsigned char*)&var, prev,
                                                         (unsigned char)val);
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_full

    #ifdef AO_HAVE_char_fetch_compare_and_swap_full
    //! Atomic compare-and-swap (acquire-release barrier).
    static inline bool compare_exchange_acq_rel(
          char& var, char& exp, char des) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        unsigned char old = AO_char_fetch_compare_and_swap_full(
          (unsigned char*)&var, (unsigned char)exp, (unsigned char)des);
        const bool ret = ((unsigned char)exp == old);
        exp = (char)old;
        return ret;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_full

    #ifdef AO_HAVE_char_load_full
    //! Atomic load (full barrier).
    static inline char load_seq_cst(char const& var) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (char)AO_char_load_full((unsigned char const*)&var);
    }
    #endif // AO_HAVE_char_load_full

    #ifdef AO_HAVE_char_store_full
    //! Atomic store (full barrier).
    static inline void store_seq_cst(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_char_store_full((unsigned char*)&var, (unsigned char)val);
    }
    #endif // AO_HAVE_char_store_full

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic exchange (full barrier).
    static inline char exchange_seq_cst(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_nop_full();
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         (unsigned char)val);
            AO_nop_full();
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_fetch_compare_and_swap
    //! Atomic compare-and-swap (full barrier).
    static inline bool compare_exchange_seq_cst(
          char& var, char& exp, char des) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_nop_full();
        unsigned char old = AO_char_fetch_compare_and_swap(
          (unsigned char*)&var, (unsigned char)exp, (unsigned char)des);
        const bool ret = ((unsigned char)exp == old);
        if (ret) {
            AO_nop_full();
        }
        exp = (char)old;
        return ret;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap

    #ifdef AO_HAVE_char_fetch_and_add_full
    //! Atomic fetch-add (full barrier).
    static inline char fetch_add_seq_cst(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (char)(
            AO_char_fetch_and_add_full((unsigned char*)&var, (unsigned char)val));
    }
    #endif // AO_HAVE_char_fetch_and_add_full

    #ifdef AO_HAVE_char_fetch_and_add_full
    //! Atomic fetch-sub (full barrier).
    static inline char fetch_sub_seq_cst(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        return (char)(
            AO_char_fetch_and_add_full((unsigned char*)&var, (unsigned char)-val));
    }
    #endif // AO_HAVE_char_fetch_and_add_full

    #ifdef AO_HAVE_char_fetch_compare_and_swap_full
    //! Atomic fetch-and (full barrier).
    static inline char fetch_and_seq_cst(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_nop_full();
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         prev & (unsigned char)val);
            AO_nop_full();
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_full

    #ifdef AO_HAVE_char_fetch_compare_and_swap_full
    //! Atomic fetch-or (full barrier).
    static inline char fetch_or_seq_cst(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_nop_full();
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         prev | (unsigned char)val);
            AO_nop_full();
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_full

    #ifdef AO_HAVE_char_fetch_compare_and_swap_full
    //! Atomic fetch-xor (full barrier).
    static inline char fetch_xor_seq_cst(char& var, char val) {
        struct TypeCheck {
            int f : sizeof(char) == sizeof(unsigned char) ? 1 : -1;
        };
        AO_nop_full();
        unsigned char curr = AO_char_load((unsigned char*)&var);
        unsigned char prev;
        do {
            prev = curr;
            curr = AO_char_fetch_compare_and_swap((unsigned char*)&var, prev,
                                                         prev ^ (unsigned char)val);
            AO_nop_full();
        } while (curr != prev);
        return (char)curr;
    }
    #endif // AO_HAVE_char_fetch_compare_and_swap_full

    // overloads for unsigned short

    #ifdef AO_HAVE_short_load
    //! Atomic load (no barrier).
    static inline unsigned short load_relaxed(unsigned short const& var) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (unsigned short)AO_short_load((unsigned short const*)&var);
    }
    #endif // AO_HAVE_short_load

    #ifdef AO_HAVE_short_store
    //! Atomic store (no barrier).
    static inline void store_relaxed(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_short_store((unsigned short*)&var, (unsigned short)val);
    }
    #endif // AO_HAVE_short_store

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic exchange (no barrier).
    static inline unsigned short exchange_relaxed(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic compare-and-swap (no barrier).
    static inline bool compare_exchange_relaxed(
          unsigned short& var, unsigned short& exp, unsigned short des) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short old = AO_short_fetch_compare_and_swap(
          (unsigned short*)&var, (unsigned short)exp, (unsigned short)des);
        const bool ret = ((unsigned short)exp == old);
        exp = (unsigned short)old;
        return ret;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_fetch_and_add
    //! Atomic fetch-add (no barrier).
    static inline unsigned short fetch_add_relaxed(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (unsigned short)(
            AO_short_fetch_and_add((unsigned short*)&var, (unsigned short)val));
    }
    #endif // AO_HAVE_short_fetch_and_add

    #ifdef AO_HAVE_short_fetch_and_add
    //! Atomic fetch-sub (no barrier).
    static inline unsigned short fetch_sub_relaxed(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (unsigned short)(
            AO_short_fetch_and_add((unsigned short*)&var, (unsigned short)-val));
    }
    #endif // AO_HAVE_short_fetch_and_add

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic fetch-and (no barrier).
    static inline unsigned short fetch_and_relaxed(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         prev & (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic fetch-or (no barrier).
    static inline unsigned short fetch_or_relaxed(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         prev | (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic fetch-xor (no barrier).
    static inline unsigned short fetch_xor_relaxed(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         prev ^ (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_load_acquire
    //! Atomic load (acquire barrier).
    static inline unsigned short load_acquire(unsigned short const& var) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (unsigned short)AO_short_load_acquire((unsigned short const*)&var);
    }
    #endif // AO_HAVE_short_load_acquire

    #ifdef AO_HAVE_short_fetch_compare_and_swap_acquire
    //! Atomic exchange (acquire barrier).
    static inline unsigned short exchange_acquire(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_acquire((unsigned short*)&var, prev,
                                                         (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_short_fetch_compare_and_swap_acquire
    //! Atomic compare-and-swap (acquire barrier).
    static inline bool compare_exchange_acquire(
          unsigned short& var, unsigned short& exp, unsigned short des) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short old = AO_short_fetch_compare_and_swap_acquire(
          (unsigned short*)&var, (unsigned short)exp, (unsigned short)des);
        const bool ret = ((unsigned short)exp == old);
        exp = (unsigned short)old;
        return ret;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_short_fetch_and_add_acquire
    //! Atomic fetch-add (acquire barrier).
    static inline unsigned short fetch_add_acquire(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (unsigned short)(
            AO_short_fetch_and_add_acquire((unsigned short*)&var, (unsigned short)val));
    }
    #endif // AO_HAVE_short_fetch_and_add_acquire

    #ifdef AO_HAVE_short_fetch_and_add_acquire
    //! Atomic fetch-sub (acquire barrier).
    static inline unsigned short fetch_sub_acquire(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (unsigned short)(
            AO_short_fetch_and_add_acquire((unsigned short*)&var, (unsigned short)-val));
    }
    #endif // AO_HAVE_short_fetch_and_add_acquire

    #ifdef AO_HAVE_short_fetch_compare_and_swap_acquire
    //! Atomic fetch-and (acquire barrier).
    static inline unsigned short fetch_and_acquire(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_acquire((unsigned short*)&var, prev,
                                                         prev & (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_short_fetch_compare_and_swap_acquire
    //! Atomic fetch-or (acquire barrier).
    static inline unsigned short fetch_or_acquire(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_acquire((unsigned short*)&var, prev,
                                                         prev | (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_short_fetch_compare_and_swap_acquire
    //! Atomic fetch-xor (acquire barrier).
    static inline unsigned short fetch_xor_acquire(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_acquire((unsigned short*)&var, prev,
                                                         prev ^ (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_short_store_release
    //! Atomic store (release barrier).
    static inline void store_release(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_short_store_release((unsigned short*)&var, (unsigned short)val);
    }
    #endif // AO_HAVE_short_store_release

    #ifdef AO_HAVE_short_fetch_compare_and_swap_release
    //! Atomic exchange (release barrier).
    static inline unsigned short exchange_release(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_release((unsigned short*)&var, prev,
                                                         (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_release

    #ifdef AO_HAVE_short_fetch_compare_and_swap_release
    //! Atomic compare-and-swap (release barrier).
    static inline bool compare_exchange_release(
          unsigned short& var, unsigned short& exp, unsigned short des) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short old = AO_short_fetch_compare_and_swap_release(
          (unsigned short*)&var, (unsigned short)exp, (unsigned short)des);
        const bool ret = ((unsigned short)exp == old);
        exp = (unsigned short)old;
        return ret;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_release

    #ifdef AO_HAVE_short_fetch_and_add_release
    //! Atomic fetch-add (release barrier).
    static inline unsigned short fetch_add_release(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (unsigned short)(
            AO_short_fetch_and_add_release((unsigned short*)&var, (unsigned short)val));
    }
    #endif // AO_HAVE_short_fetch_and_add_release

    #ifdef AO_HAVE_short_fetch_and_add_release
    //! Atomic fetch-sub (release barrier).
    static inline unsigned short fetch_sub_release(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (unsigned short)(
            AO_short_fetch_and_add_release((unsigned short*)&var, (unsigned short)-val));
    }
    #endif // AO_HAVE_short_fetch_and_add_release

    #ifdef AO_HAVE_short_fetch_compare_and_swap_release
    //! Atomic fetch-and (release barrier).
    static inline unsigned short fetch_and_release(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_release((unsigned short*)&var, prev,
                                                         prev & (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_release

    #ifdef AO_HAVE_short_fetch_compare_and_swap_release
    //! Atomic fetch-or (release barrier).
    static inline unsigned short fetch_or_release(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_release((unsigned short*)&var, prev,
                                                         prev | (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_release

    #ifdef AO_HAVE_short_fetch_compare_and_swap_release
    //! Atomic fetch-xor (release barrier).
    static inline unsigned short fetch_xor_release(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_release((unsigned short*)&var, prev,
                                                         prev ^ (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_release

    #ifdef AO_HAVE_short_fetch_compare_and_swap_full
    //! Atomic exchange (acquire-release barrier).
    static inline unsigned short exchange_acq_rel(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_full((unsigned short*)&var, prev,
                                                         (unsigned short)val);
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_full

    #ifdef AO_HAVE_short_fetch_compare_and_swap_full
    //! Atomic compare-and-swap (acquire-release barrier).
    static inline bool compare_exchange_acq_rel(
          unsigned short& var, unsigned short& exp, unsigned short des) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short old = AO_short_fetch_compare_and_swap_full(
          (unsigned short*)&var, (unsigned short)exp, (unsigned short)des);
        const bool ret = ((unsigned short)exp == old);
        exp = (unsigned short)old;
        return ret;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_full

    #ifdef AO_HAVE_short_load_full
    //! Atomic load (full barrier).
    static inline unsigned short load_seq_cst(unsigned short const& var) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (unsigned short)AO_short_load_full((unsigned short const*)&var);
    }
    #endif // AO_HAVE_short_load_full

    #ifdef AO_HAVE_short_store_full
    //! Atomic store (full barrier).
    static inline void store_seq_cst(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_short_store_full((unsigned short*)&var, (unsigned short)val);
    }
    #endif // AO_HAVE_short_store_full

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic exchange (full barrier).
    static inline unsigned short exchange_seq_cst(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_nop_full();
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         (unsigned short)val);
            AO_nop_full();
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic compare-and-swap (full barrier).
    static inline bool compare_exchange_seq_cst(
          unsigned short& var, unsigned short& exp, unsigned short des) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_nop_full();
        unsigned short old = AO_short_fetch_compare_and_swap(
          (unsigned short*)&var, (unsigned short)exp, (unsigned short)des);
        const bool ret = ((unsigned short)exp == old);
        if (ret) {
            AO_nop_full();
        }
        exp = (unsigned short)old;
        return ret;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_fetch_and_add_full
    //! Atomic fetch-add (full barrier).
    static inline unsigned short fetch_add_seq_cst(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (unsigned short)(
            AO_short_fetch_and_add_full((unsigned short*)&var, (unsigned short)val));
    }
    #endif // AO_HAVE_short_fetch_and_add_full

    #ifdef AO_HAVE_short_fetch_and_add_full
    //! Atomic fetch-sub (full barrier).
    static inline unsigned short fetch_sub_seq_cst(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (unsigned short)(
            AO_short_fetch_and_add_full((unsigned short*)&var, (unsigned short)-val));
    }
    #endif // AO_HAVE_short_fetch_and_add_full

    #ifdef AO_HAVE_short_fetch_compare_and_swap_full
    //! Atomic fetch-and (full barrier).
    static inline unsigned short fetch_and_seq_cst(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_nop_full();
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         prev & (unsigned short)val);
            AO_nop_full();
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_full

    #ifdef AO_HAVE_short_fetch_compare_and_swap_full
    //! Atomic fetch-or (full barrier).
    static inline unsigned short fetch_or_seq_cst(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_nop_full();
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         prev | (unsigned short)val);
            AO_nop_full();
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_full

    #ifdef AO_HAVE_short_fetch_compare_and_swap_full
    //! Atomic fetch-xor (full barrier).
    static inline unsigned short fetch_xor_seq_cst(unsigned short& var, unsigned short val) {
        struct TypeCheck {
            int f : sizeof(unsigned short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_nop_full();
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         prev ^ (unsigned short)val);
            AO_nop_full();
        } while (curr != prev);
        return (unsigned short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_full

    // overloads for short

    #ifdef AO_HAVE_short_load
    //! Atomic load (no barrier).
    static inline short load_relaxed(short const& var) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (short)AO_short_load((unsigned short const*)&var);
    }
    #endif // AO_HAVE_short_load

    #ifdef AO_HAVE_short_store
    //! Atomic store (no barrier).
    static inline void store_relaxed(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_short_store((unsigned short*)&var, (unsigned short)val);
    }
    #endif // AO_HAVE_short_store

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic exchange (no barrier).
    static inline short exchange_relaxed(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic compare-and-swap (no barrier).
    static inline bool compare_exchange_relaxed(
          short& var, short& exp, short des) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short old = AO_short_fetch_compare_and_swap(
          (unsigned short*)&var, (unsigned short)exp, (unsigned short)des);
        const bool ret = ((unsigned short)exp == old);
        exp = (short)old;
        return ret;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_fetch_and_add
    //! Atomic fetch-add (no barrier).
    static inline short fetch_add_relaxed(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (short)(
            AO_short_fetch_and_add((unsigned short*)&var, (unsigned short)val));
    }
    #endif // AO_HAVE_short_fetch_and_add

    #ifdef AO_HAVE_short_fetch_and_add
    //! Atomic fetch-sub (no barrier).
    static inline short fetch_sub_relaxed(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (short)(
            AO_short_fetch_and_add((unsigned short*)&var, (unsigned short)-val));
    }
    #endif // AO_HAVE_short_fetch_and_add

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic fetch-and (no barrier).
    static inline short fetch_and_relaxed(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         prev & (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic fetch-or (no barrier).
    static inline short fetch_or_relaxed(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         prev | (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic fetch-xor (no barrier).
    static inline short fetch_xor_relaxed(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         prev ^ (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_load_acquire
    //! Atomic load (acquire barrier).
    static inline short load_acquire(short const& var) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (short)AO_short_load_acquire((unsigned short const*)&var);
    }
    #endif // AO_HAVE_short_load_acquire

    #ifdef AO_HAVE_short_fetch_compare_and_swap_acquire
    //! Atomic exchange (acquire barrier).
    static inline short exchange_acquire(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_acquire((unsigned short*)&var, prev,
                                                         (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_short_fetch_compare_and_swap_acquire
    //! Atomic compare-and-swap (acquire barrier).
    static inline bool compare_exchange_acquire(
          short& var, short& exp, short des) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short old = AO_short_fetch_compare_and_swap_acquire(
          (unsigned short*)&var, (unsigned short)exp, (unsigned short)des);
        const bool ret = ((unsigned short)exp == old);
        exp = (short)old;
        return ret;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_short_fetch_and_add_acquire
    //! Atomic fetch-add (acquire barrier).
    static inline short fetch_add_acquire(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (short)(
            AO_short_fetch_and_add_acquire((unsigned short*)&var, (unsigned short)val));
    }
    #endif // AO_HAVE_short_fetch_and_add_acquire

    #ifdef AO_HAVE_short_fetch_and_add_acquire
    //! Atomic fetch-sub (acquire barrier).
    static inline short fetch_sub_acquire(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (short)(
            AO_short_fetch_and_add_acquire((unsigned short*)&var, (unsigned short)-val));
    }
    #endif // AO_HAVE_short_fetch_and_add_acquire

    #ifdef AO_HAVE_short_fetch_compare_and_swap_acquire
    //! Atomic fetch-and (acquire barrier).
    static inline short fetch_and_acquire(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_acquire((unsigned short*)&var, prev,
                                                         prev & (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_short_fetch_compare_and_swap_acquire
    //! Atomic fetch-or (acquire barrier).
    static inline short fetch_or_acquire(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_acquire((unsigned short*)&var, prev,
                                                         prev | (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_short_fetch_compare_and_swap_acquire
    //! Atomic fetch-xor (acquire barrier).
    static inline short fetch_xor_acquire(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_acquire((unsigned short*)&var, prev,
                                                         prev ^ (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_short_store_release
    //! Atomic store (release barrier).
    static inline void store_release(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_short_store_release((unsigned short*)&var, (unsigned short)val);
    }
    #endif // AO_HAVE_short_store_release

    #ifdef AO_HAVE_short_fetch_compare_and_swap_release
    //! Atomic exchange (release barrier).
    static inline short exchange_release(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_release((unsigned short*)&var, prev,
                                                         (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_release

    #ifdef AO_HAVE_short_fetch_compare_and_swap_release
    //! Atomic compare-and-swap (release barrier).
    static inline bool compare_exchange_release(
          short& var, short& exp, short des) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short old = AO_short_fetch_compare_and_swap_release(
          (unsigned short*)&var, (unsigned short)exp, (unsigned short)des);
        const bool ret = ((unsigned short)exp == old);
        exp = (short)old;
        return ret;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_release

    #ifdef AO_HAVE_short_fetch_and_add_release
    //! Atomic fetch-add (release barrier).
    static inline short fetch_add_release(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (short)(
            AO_short_fetch_and_add_release((unsigned short*)&var, (unsigned short)val));
    }
    #endif // AO_HAVE_short_fetch_and_add_release

    #ifdef AO_HAVE_short_fetch_and_add_release
    //! Atomic fetch-sub (release barrier).
    static inline short fetch_sub_release(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (short)(
            AO_short_fetch_and_add_release((unsigned short*)&var, (unsigned short)-val));
    }
    #endif // AO_HAVE_short_fetch_and_add_release

    #ifdef AO_HAVE_short_fetch_compare_and_swap_release
    //! Atomic fetch-and (release barrier).
    static inline short fetch_and_release(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_release((unsigned short*)&var, prev,
                                                         prev & (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_release

    #ifdef AO_HAVE_short_fetch_compare_and_swap_release
    //! Atomic fetch-or (release barrier).
    static inline short fetch_or_release(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_release((unsigned short*)&var, prev,
                                                         prev | (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_release

    #ifdef AO_HAVE_short_fetch_compare_and_swap_release
    //! Atomic fetch-xor (release barrier).
    static inline short fetch_xor_release(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_release((unsigned short*)&var, prev,
                                                         prev ^ (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_release

    #ifdef AO_HAVE_short_fetch_compare_and_swap_full
    //! Atomic exchange (acquire-release barrier).
    static inline short exchange_acq_rel(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap_full((unsigned short*)&var, prev,
                                                         (unsigned short)val);
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_full

    #ifdef AO_HAVE_short_fetch_compare_and_swap_full
    //! Atomic compare-and-swap (acquire-release barrier).
    static inline bool compare_exchange_acq_rel(
          short& var, short& exp, short des) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        unsigned short old = AO_short_fetch_compare_and_swap_full(
          (unsigned short*)&var, (unsigned short)exp, (unsigned short)des);
        const bool ret = ((unsigned short)exp == old);
        exp = (short)old;
        return ret;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_full

    #ifdef AO_HAVE_short_load_full
    //! Atomic load (full barrier).
    static inline short load_seq_cst(short const& var) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (short)AO_short_load_full((unsigned short const*)&var);
    }
    #endif // AO_HAVE_short_load_full

    #ifdef AO_HAVE_short_store_full
    //! Atomic store (full barrier).
    static inline void store_seq_cst(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_short_store_full((unsigned short*)&var, (unsigned short)val);
    }
    #endif // AO_HAVE_short_store_full

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic exchange (full barrier).
    static inline short exchange_seq_cst(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_nop_full();
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         (unsigned short)val);
            AO_nop_full();
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_fetch_compare_and_swap
    //! Atomic compare-and-swap (full barrier).
    static inline bool compare_exchange_seq_cst(
          short& var, short& exp, short des) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_nop_full();
        unsigned short old = AO_short_fetch_compare_and_swap(
          (unsigned short*)&var, (unsigned short)exp, (unsigned short)des);
        const bool ret = ((unsigned short)exp == old);
        if (ret) {
            AO_nop_full();
        }
        exp = (short)old;
        return ret;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap

    #ifdef AO_HAVE_short_fetch_and_add_full
    //! Atomic fetch-add (full barrier).
    static inline short fetch_add_seq_cst(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (short)(
            AO_short_fetch_and_add_full((unsigned short*)&var, (unsigned short)val));
    }
    #endif // AO_HAVE_short_fetch_and_add_full

    #ifdef AO_HAVE_short_fetch_and_add_full
    //! Atomic fetch-sub (full barrier).
    static inline short fetch_sub_seq_cst(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        return (short)(
            AO_short_fetch_and_add_full((unsigned short*)&var, (unsigned short)-val));
    }
    #endif // AO_HAVE_short_fetch_and_add_full

    #ifdef AO_HAVE_short_fetch_compare_and_swap_full
    //! Atomic fetch-and (full barrier).
    static inline short fetch_and_seq_cst(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_nop_full();
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         prev & (unsigned short)val);
            AO_nop_full();
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_full

    #ifdef AO_HAVE_short_fetch_compare_and_swap_full
    //! Atomic fetch-or (full barrier).
    static inline short fetch_or_seq_cst(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_nop_full();
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         prev | (unsigned short)val);
            AO_nop_full();
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_full

    #ifdef AO_HAVE_short_fetch_compare_and_swap_full
    //! Atomic fetch-xor (full barrier).
    static inline short fetch_xor_seq_cst(short& var, short val) {
        struct TypeCheck {
            int f : sizeof(short) == sizeof(unsigned short) ? 1 : -1;
        };
        AO_nop_full();
        unsigned short curr = AO_short_load((unsigned short*)&var);
        unsigned short prev;
        do {
            prev = curr;
            curr = AO_short_fetch_compare_and_swap((unsigned short*)&var, prev,
                                                         prev ^ (unsigned short)val);
            AO_nop_full();
        } while (curr != prev);
        return (short)curr;
    }
    #endif // AO_HAVE_short_fetch_compare_and_swap_full

#ifndef AO_T_IS_INT

    // overloads for unsigned int

    #ifdef AO_HAVE_int_load
    //! Atomic load (no barrier).
    static inline unsigned int load_relaxed(unsigned int const& var) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (unsigned int)AO_int_load((unsigned int const*)&var);
    }
    #endif // AO_HAVE_int_load

    #ifdef AO_HAVE_int_store
    //! Atomic store (no barrier).
    static inline void store_relaxed(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_int_store((unsigned int*)&var, (unsigned int)val);
    }
    #endif // AO_HAVE_int_store

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic exchange (no barrier).
    static inline unsigned int exchange_relaxed(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic compare-and-swap (no barrier).
    static inline bool compare_exchange_relaxed(
          unsigned int& var, unsigned int& exp, unsigned int des) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int old = AO_int_fetch_compare_and_swap(
          (unsigned int*)&var, (unsigned int)exp, (unsigned int)des);
        const bool ret = ((unsigned int)exp == old);
        exp = (unsigned int)old;
        return ret;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_fetch_and_add
    //! Atomic fetch-add (no barrier).
    static inline unsigned int fetch_add_relaxed(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (unsigned int)(
            AO_int_fetch_and_add((unsigned int*)&var, (unsigned int)val));
    }
    #endif // AO_HAVE_int_fetch_and_add

    #ifdef AO_HAVE_int_fetch_and_add
    //! Atomic fetch-sub (no barrier).
    static inline unsigned int fetch_sub_relaxed(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (unsigned int)(
            AO_int_fetch_and_add((unsigned int*)&var, (unsigned int)-val));
    }
    #endif // AO_HAVE_int_fetch_and_add

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic fetch-and (no barrier).
    static inline unsigned int fetch_and_relaxed(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         prev & (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic fetch-or (no barrier).
    static inline unsigned int fetch_or_relaxed(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         prev | (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic fetch-xor (no barrier).
    static inline unsigned int fetch_xor_relaxed(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         prev ^ (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_load_acquire
    //! Atomic load (acquire barrier).
    static inline unsigned int load_acquire(unsigned int const& var) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (unsigned int)AO_int_load_acquire((unsigned int const*)&var);
    }
    #endif // AO_HAVE_int_load_acquire

    #ifdef AO_HAVE_int_fetch_compare_and_swap_acquire
    //! Atomic exchange (acquire barrier).
    static inline unsigned int exchange_acquire(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_acquire((unsigned int*)&var, prev,
                                                         (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_int_fetch_compare_and_swap_acquire
    //! Atomic compare-and-swap (acquire barrier).
    static inline bool compare_exchange_acquire(
          unsigned int& var, unsigned int& exp, unsigned int des) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int old = AO_int_fetch_compare_and_swap_acquire(
          (unsigned int*)&var, (unsigned int)exp, (unsigned int)des);
        const bool ret = ((unsigned int)exp == old);
        exp = (unsigned int)old;
        return ret;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_int_fetch_and_add_acquire
    //! Atomic fetch-add (acquire barrier).
    static inline unsigned int fetch_add_acquire(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (unsigned int)(
            AO_int_fetch_and_add_acquire((unsigned int*)&var, (unsigned int)val));
    }
    #endif // AO_HAVE_int_fetch_and_add_acquire

    #ifdef AO_HAVE_int_fetch_and_add_acquire
    //! Atomic fetch-sub (acquire barrier).
    static inline unsigned int fetch_sub_acquire(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (unsigned int)(
            AO_int_fetch_and_add_acquire((unsigned int*)&var, (unsigned int)-val));
    }
    #endif // AO_HAVE_int_fetch_and_add_acquire

    #ifdef AO_HAVE_int_fetch_compare_and_swap_acquire
    //! Atomic fetch-and (acquire barrier).
    static inline unsigned int fetch_and_acquire(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_acquire((unsigned int*)&var, prev,
                                                         prev & (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_int_fetch_compare_and_swap_acquire
    //! Atomic fetch-or (acquire barrier).
    static inline unsigned int fetch_or_acquire(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_acquire((unsigned int*)&var, prev,
                                                         prev | (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_int_fetch_compare_and_swap_acquire
    //! Atomic fetch-xor (acquire barrier).
    static inline unsigned int fetch_xor_acquire(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_acquire((unsigned int*)&var, prev,
                                                         prev ^ (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_int_store_release
    //! Atomic store (release barrier).
    static inline void store_release(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_int_store_release((unsigned int*)&var, (unsigned int)val);
    }
    #endif // AO_HAVE_int_store_release

    #ifdef AO_HAVE_int_fetch_compare_and_swap_release
    //! Atomic exchange (release barrier).
    static inline unsigned int exchange_release(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_release((unsigned int*)&var, prev,
                                                         (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_release

    #ifdef AO_HAVE_int_fetch_compare_and_swap_release
    //! Atomic compare-and-swap (release barrier).
    static inline bool compare_exchange_release(
          unsigned int& var, unsigned int& exp, unsigned int des) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int old = AO_int_fetch_compare_and_swap_release(
          (unsigned int*)&var, (unsigned int)exp, (unsigned int)des);
        const bool ret = ((unsigned int)exp == old);
        exp = (unsigned int)old;
        return ret;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_release

    #ifdef AO_HAVE_int_fetch_and_add_release
    //! Atomic fetch-add (release barrier).
    static inline unsigned int fetch_add_release(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (unsigned int)(
            AO_int_fetch_and_add_release((unsigned int*)&var, (unsigned int)val));
    }
    #endif // AO_HAVE_int_fetch_and_add_release

    #ifdef AO_HAVE_int_fetch_and_add_release
    //! Atomic fetch-sub (release barrier).
    static inline unsigned int fetch_sub_release(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (unsigned int)(
            AO_int_fetch_and_add_release((unsigned int*)&var, (unsigned int)-val));
    }
    #endif // AO_HAVE_int_fetch_and_add_release

    #ifdef AO_HAVE_int_fetch_compare_and_swap_release
    //! Atomic fetch-and (release barrier).
    static inline unsigned int fetch_and_release(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_release((unsigned int*)&var, prev,
                                                         prev & (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_release

    #ifdef AO_HAVE_int_fetch_compare_and_swap_release
    //! Atomic fetch-or (release barrier).
    static inline unsigned int fetch_or_release(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_release((unsigned int*)&var, prev,
                                                         prev | (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_release

    #ifdef AO_HAVE_int_fetch_compare_and_swap_release
    //! Atomic fetch-xor (release barrier).
    static inline unsigned int fetch_xor_release(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_release((unsigned int*)&var, prev,
                                                         prev ^ (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_release

    #ifdef AO_HAVE_int_fetch_compare_and_swap_full
    //! Atomic exchange (acquire-release barrier).
    static inline unsigned int exchange_acq_rel(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_full((unsigned int*)&var, prev,
                                                         (unsigned int)val);
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_full

    #ifdef AO_HAVE_int_fetch_compare_and_swap_full
    //! Atomic compare-and-swap (acquire-release barrier).
    static inline bool compare_exchange_acq_rel(
          unsigned int& var, unsigned int& exp, unsigned int des) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int old = AO_int_fetch_compare_and_swap_full(
          (unsigned int*)&var, (unsigned int)exp, (unsigned int)des);
        const bool ret = ((unsigned int)exp == old);
        exp = (unsigned int)old;
        return ret;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_full

    #ifdef AO_HAVE_int_load_full
    //! Atomic load (full barrier).
    static inline unsigned int load_seq_cst(unsigned int const& var) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (unsigned int)AO_int_load_full((unsigned int const*)&var);
    }
    #endif // AO_HAVE_int_load_full

    #ifdef AO_HAVE_int_store_full
    //! Atomic store (full barrier).
    static inline void store_seq_cst(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_int_store_full((unsigned int*)&var, (unsigned int)val);
    }
    #endif // AO_HAVE_int_store_full

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic exchange (full barrier).
    static inline unsigned int exchange_seq_cst(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_nop_full();
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         (unsigned int)val);
            AO_nop_full();
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic compare-and-swap (full barrier).
    static inline bool compare_exchange_seq_cst(
          unsigned int& var, unsigned int& exp, unsigned int des) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_nop_full();
        unsigned int old = AO_int_fetch_compare_and_swap(
          (unsigned int*)&var, (unsigned int)exp, (unsigned int)des);
        const bool ret = ((unsigned int)exp == old);
        if (ret) {
            AO_nop_full();
        }
        exp = (unsigned int)old;
        return ret;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_fetch_and_add_full
    //! Atomic fetch-add (full barrier).
    static inline unsigned int fetch_add_seq_cst(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (unsigned int)(
            AO_int_fetch_and_add_full((unsigned int*)&var, (unsigned int)val));
    }
    #endif // AO_HAVE_int_fetch_and_add_full

    #ifdef AO_HAVE_int_fetch_and_add_full
    //! Atomic fetch-sub (full barrier).
    static inline unsigned int fetch_sub_seq_cst(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (unsigned int)(
            AO_int_fetch_and_add_full((unsigned int*)&var, (unsigned int)-val));
    }
    #endif // AO_HAVE_int_fetch_and_add_full

    #ifdef AO_HAVE_int_fetch_compare_and_swap_full
    //! Atomic fetch-and (full barrier).
    static inline unsigned int fetch_and_seq_cst(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_nop_full();
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         prev & (unsigned int)val);
            AO_nop_full();
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_full

    #ifdef AO_HAVE_int_fetch_compare_and_swap_full
    //! Atomic fetch-or (full barrier).
    static inline unsigned int fetch_or_seq_cst(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_nop_full();
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         prev | (unsigned int)val);
            AO_nop_full();
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_full

    #ifdef AO_HAVE_int_fetch_compare_and_swap_full
    //! Atomic fetch-xor (full barrier).
    static inline unsigned int fetch_xor_seq_cst(unsigned int& var, unsigned int val) {
        struct TypeCheck {
            int f : sizeof(unsigned int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_nop_full();
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         prev ^ (unsigned int)val);
            AO_nop_full();
        } while (curr != prev);
        return (unsigned int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_full

    // overloads for int

    #ifdef AO_HAVE_int_load
    //! Atomic load (no barrier).
    static inline int load_relaxed(int const& var) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (int)AO_int_load((unsigned int const*)&var);
    }
    #endif // AO_HAVE_int_load

    #ifdef AO_HAVE_int_store
    //! Atomic store (no barrier).
    static inline void store_relaxed(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_int_store((unsigned int*)&var, (unsigned int)val);
    }
    #endif // AO_HAVE_int_store

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic exchange (no barrier).
    static inline int exchange_relaxed(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic compare-and-swap (no barrier).
    static inline bool compare_exchange_relaxed(
          int& var, int& exp, int des) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int old = AO_int_fetch_compare_and_swap(
          (unsigned int*)&var, (unsigned int)exp, (unsigned int)des);
        const bool ret = ((unsigned int)exp == old);
        exp = (int)old;
        return ret;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_fetch_and_add
    //! Atomic fetch-add (no barrier).
    static inline int fetch_add_relaxed(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (int)(
            AO_int_fetch_and_add((unsigned int*)&var, (unsigned int)val));
    }
    #endif // AO_HAVE_int_fetch_and_add

    #ifdef AO_HAVE_int_fetch_and_add
    //! Atomic fetch-sub (no barrier).
    static inline int fetch_sub_relaxed(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (int)(
            AO_int_fetch_and_add((unsigned int*)&var, (unsigned int)-val));
    }
    #endif // AO_HAVE_int_fetch_and_add

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic fetch-and (no barrier).
    static inline int fetch_and_relaxed(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         prev & (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic fetch-or (no barrier).
    static inline int fetch_or_relaxed(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         prev | (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic fetch-xor (no barrier).
    static inline int fetch_xor_relaxed(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         prev ^ (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_load_acquire
    //! Atomic load (acquire barrier).
    static inline int load_acquire(int const& var) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (int)AO_int_load_acquire((unsigned int const*)&var);
    }
    #endif // AO_HAVE_int_load_acquire

    #ifdef AO_HAVE_int_fetch_compare_and_swap_acquire
    //! Atomic exchange (acquire barrier).
    static inline int exchange_acquire(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_acquire((unsigned int*)&var, prev,
                                                         (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_int_fetch_compare_and_swap_acquire
    //! Atomic compare-and-swap (acquire barrier).
    static inline bool compare_exchange_acquire(
          int& var, int& exp, int des) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int old = AO_int_fetch_compare_and_swap_acquire(
          (unsigned int*)&var, (unsigned int)exp, (unsigned int)des);
        const bool ret = ((unsigned int)exp == old);
        exp = (int)old;
        return ret;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_int_fetch_and_add_acquire
    //! Atomic fetch-add (acquire barrier).
    static inline int fetch_add_acquire(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (int)(
            AO_int_fetch_and_add_acquire((unsigned int*)&var, (unsigned int)val));
    }
    #endif // AO_HAVE_int_fetch_and_add_acquire

    #ifdef AO_HAVE_int_fetch_and_add_acquire
    //! Atomic fetch-sub (acquire barrier).
    static inline int fetch_sub_acquire(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (int)(
            AO_int_fetch_and_add_acquire((unsigned int*)&var, (unsigned int)-val));
    }
    #endif // AO_HAVE_int_fetch_and_add_acquire

    #ifdef AO_HAVE_int_fetch_compare_and_swap_acquire
    //! Atomic fetch-and (acquire barrier).
    static inline int fetch_and_acquire(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_acquire((unsigned int*)&var, prev,
                                                         prev & (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_int_fetch_compare_and_swap_acquire
    //! Atomic fetch-or (acquire barrier).
    static inline int fetch_or_acquire(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_acquire((unsigned int*)&var, prev,
                                                         prev | (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_int_fetch_compare_and_swap_acquire
    //! Atomic fetch-xor (acquire barrier).
    static inline int fetch_xor_acquire(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_acquire((unsigned int*)&var, prev,
                                                         prev ^ (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_int_store_release
    //! Atomic store (release barrier).
    static inline void store_release(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_int_store_release((unsigned int*)&var, (unsigned int)val);
    }
    #endif // AO_HAVE_int_store_release

    #ifdef AO_HAVE_int_fetch_compare_and_swap_release
    //! Atomic exchange (release barrier).
    static inline int exchange_release(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_release((unsigned int*)&var, prev,
                                                         (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_release

    #ifdef AO_HAVE_int_fetch_compare_and_swap_release
    //! Atomic compare-and-swap (release barrier).
    static inline bool compare_exchange_release(
          int& var, int& exp, int des) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int old = AO_int_fetch_compare_and_swap_release(
          (unsigned int*)&var, (unsigned int)exp, (unsigned int)des);
        const bool ret = ((unsigned int)exp == old);
        exp = (int)old;
        return ret;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_release

    #ifdef AO_HAVE_int_fetch_and_add_release
    //! Atomic fetch-add (release barrier).
    static inline int fetch_add_release(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (int)(
            AO_int_fetch_and_add_release((unsigned int*)&var, (unsigned int)val));
    }
    #endif // AO_HAVE_int_fetch_and_add_release

    #ifdef AO_HAVE_int_fetch_and_add_release
    //! Atomic fetch-sub (release barrier).
    static inline int fetch_sub_release(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (int)(
            AO_int_fetch_and_add_release((unsigned int*)&var, (unsigned int)-val));
    }
    #endif // AO_HAVE_int_fetch_and_add_release

    #ifdef AO_HAVE_int_fetch_compare_and_swap_release
    //! Atomic fetch-and (release barrier).
    static inline int fetch_and_release(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_release((unsigned int*)&var, prev,
                                                         prev & (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_release

    #ifdef AO_HAVE_int_fetch_compare_and_swap_release
    //! Atomic fetch-or (release barrier).
    static inline int fetch_or_release(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_release((unsigned int*)&var, prev,
                                                         prev | (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_release

    #ifdef AO_HAVE_int_fetch_compare_and_swap_release
    //! Atomic fetch-xor (release barrier).
    static inline int fetch_xor_release(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_release((unsigned int*)&var, prev,
                                                         prev ^ (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_release

    #ifdef AO_HAVE_int_fetch_compare_and_swap_full
    //! Atomic exchange (acquire-release barrier).
    static inline int exchange_acq_rel(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap_full((unsigned int*)&var, prev,
                                                         (unsigned int)val);
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_full

    #ifdef AO_HAVE_int_fetch_compare_and_swap_full
    //! Atomic compare-and-swap (acquire-release barrier).
    static inline bool compare_exchange_acq_rel(
          int& var, int& exp, int des) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        unsigned int old = AO_int_fetch_compare_and_swap_full(
          (unsigned int*)&var, (unsigned int)exp, (unsigned int)des);
        const bool ret = ((unsigned int)exp == old);
        exp = (int)old;
        return ret;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_full

    #ifdef AO_HAVE_int_load_full
    //! Atomic load (full barrier).
    static inline int load_seq_cst(int const& var) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (int)AO_int_load_full((unsigned int const*)&var);
    }
    #endif // AO_HAVE_int_load_full

    #ifdef AO_HAVE_int_store_full
    //! Atomic store (full barrier).
    static inline void store_seq_cst(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_int_store_full((unsigned int*)&var, (unsigned int)val);
    }
    #endif // AO_HAVE_int_store_full

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic exchange (full barrier).
    static inline int exchange_seq_cst(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_nop_full();
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         (unsigned int)val);
            AO_nop_full();
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_fetch_compare_and_swap
    //! Atomic compare-and-swap (full barrier).
    static inline bool compare_exchange_seq_cst(
          int& var, int& exp, int des) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_nop_full();
        unsigned int old = AO_int_fetch_compare_and_swap(
          (unsigned int*)&var, (unsigned int)exp, (unsigned int)des);
        const bool ret = ((unsigned int)exp == old);
        if (ret) {
            AO_nop_full();
        }
        exp = (int)old;
        return ret;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap

    #ifdef AO_HAVE_int_fetch_and_add_full
    //! Atomic fetch-add (full barrier).
    static inline int fetch_add_seq_cst(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (int)(
            AO_int_fetch_and_add_full((unsigned int*)&var, (unsigned int)val));
    }
    #endif // AO_HAVE_int_fetch_and_add_full

    #ifdef AO_HAVE_int_fetch_and_add_full
    //! Atomic fetch-sub (full barrier).
    static inline int fetch_sub_seq_cst(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        return (int)(
            AO_int_fetch_and_add_full((unsigned int*)&var, (unsigned int)-val));
    }
    #endif // AO_HAVE_int_fetch_and_add_full

    #ifdef AO_HAVE_int_fetch_compare_and_swap_full
    //! Atomic fetch-and (full barrier).
    static inline int fetch_and_seq_cst(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_nop_full();
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         prev & (unsigned int)val);
            AO_nop_full();
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_full

    #ifdef AO_HAVE_int_fetch_compare_and_swap_full
    //! Atomic fetch-or (full barrier).
    static inline int fetch_or_seq_cst(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_nop_full();
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         prev | (unsigned int)val);
            AO_nop_full();
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_full

    #ifdef AO_HAVE_int_fetch_compare_and_swap_full
    //! Atomic fetch-xor (full barrier).
    static inline int fetch_xor_seq_cst(int& var, int val) {
        struct TypeCheck {
            int f : sizeof(int) == sizeof(unsigned int) ? 1 : -1;
        };
        AO_nop_full();
        unsigned int curr = AO_int_load((unsigned int*)&var);
        unsigned int prev;
        do {
            prev = curr;
            curr = AO_int_fetch_compare_and_swap((unsigned int*)&var, prev,
                                                         prev ^ (unsigned int)val);
            AO_nop_full();
        } while (curr != prev);
        return (int)curr;
    }
    #endif // AO_HAVE_int_fetch_compare_and_swap_full

#endif // AO_T_IS_INT

    // overloads for size_t

    #ifdef AO_HAVE_load
    //! Atomic load (no barrier).
    static inline size_t load_relaxed(size_t const& var) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (size_t)AO_load((AO_t const*)&var);
    }
    #endif // AO_HAVE_load

    #ifdef AO_HAVE_store
    //! Atomic store (no barrier).
    static inline void store_relaxed(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_store((AO_t*)&var, (AO_t)val);
    }
    #endif // AO_HAVE_store

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic exchange (no barrier).
    static inline size_t exchange_relaxed(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic compare-and-swap (no barrier).
    static inline bool compare_exchange_relaxed(
          size_t& var, size_t& exp, size_t des) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t old = AO_fetch_compare_and_swap(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        exp = (size_t)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_and_add
    //! Atomic fetch-add (no barrier).
    static inline size_t fetch_add_relaxed(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (size_t)(
            AO_fetch_and_add((AO_t*)&var, (AO_t)val));
    }
    #endif // AO_HAVE_fetch_and_add

    #ifdef AO_HAVE_fetch_and_add
    //! Atomic fetch-sub (no barrier).
    static inline size_t fetch_sub_relaxed(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (size_t)(
            AO_fetch_and_add((AO_t*)&var, (AO_t)-val));
    }
    #endif // AO_HAVE_fetch_and_add

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic fetch-and (no barrier).
    static inline size_t fetch_and_relaxed(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev & (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic fetch-or (no barrier).
    static inline size_t fetch_or_relaxed(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev | (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic fetch-xor (no barrier).
    static inline size_t fetch_xor_relaxed(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev ^ (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_load_acquire
    //! Atomic load (acquire barrier).
    static inline size_t load_acquire(size_t const& var) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (size_t)AO_load_acquire((AO_t const*)&var);
    }
    #endif // AO_HAVE_load_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic exchange (acquire barrier).
    static inline size_t exchange_acquire(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_acquire((AO_t*)&var, prev,
                                                         (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic compare-and-swap (acquire barrier).
    static inline bool compare_exchange_acquire(
          size_t& var, size_t& exp, size_t des) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t old = AO_fetch_compare_and_swap_acquire(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        exp = (size_t)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_fetch_and_add_acquire
    //! Atomic fetch-add (acquire barrier).
    static inline size_t fetch_add_acquire(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (size_t)(
            AO_fetch_and_add_acquire((AO_t*)&var, (AO_t)val));
    }
    #endif // AO_HAVE_fetch_and_add_acquire

    #ifdef AO_HAVE_fetch_and_add_acquire
    //! Atomic fetch-sub (acquire barrier).
    static inline size_t fetch_sub_acquire(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (size_t)(
            AO_fetch_and_add_acquire((AO_t*)&var, (AO_t)-val));
    }
    #endif // AO_HAVE_fetch_and_add_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic fetch-and (acquire barrier).
    static inline size_t fetch_and_acquire(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_acquire((AO_t*)&var, prev,
                                                         prev & (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic fetch-or (acquire barrier).
    static inline size_t fetch_or_acquire(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_acquire((AO_t*)&var, prev,
                                                         prev | (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic fetch-xor (acquire barrier).
    static inline size_t fetch_xor_acquire(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_acquire((AO_t*)&var, prev,
                                                         prev ^ (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_store_release
    //! Atomic store (release barrier).
    static inline void store_release(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_store_release((AO_t*)&var, (AO_t)val);
    }
    #endif // AO_HAVE_store_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic exchange (release barrier).
    static inline size_t exchange_release(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_release((AO_t*)&var, prev,
                                                         (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic compare-and-swap (release barrier).
    static inline bool compare_exchange_release(
          size_t& var, size_t& exp, size_t des) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t old = AO_fetch_compare_and_swap_release(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        exp = (size_t)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_and_add_release
    //! Atomic fetch-add (release barrier).
    static inline size_t fetch_add_release(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (size_t)(
            AO_fetch_and_add_release((AO_t*)&var, (AO_t)val));
    }
    #endif // AO_HAVE_fetch_and_add_release

    #ifdef AO_HAVE_fetch_and_add_release
    //! Atomic fetch-sub (release barrier).
    static inline size_t fetch_sub_release(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (size_t)(
            AO_fetch_and_add_release((AO_t*)&var, (AO_t)-val));
    }
    #endif // AO_HAVE_fetch_and_add_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic fetch-and (release barrier).
    static inline size_t fetch_and_release(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_release((AO_t*)&var, prev,
                                                         prev & (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic fetch-or (release barrier).
    static inline size_t fetch_or_release(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_release((AO_t*)&var, prev,
                                                         prev | (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic fetch-xor (release barrier).
    static inline size_t fetch_xor_release(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_release((AO_t*)&var, prev,
                                                         prev ^ (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic exchange (acquire-release barrier).
    static inline size_t exchange_acq_rel(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_full((AO_t*)&var, prev,
                                                         (AO_t)val);
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic compare-and-swap (acquire-release barrier).
    static inline bool compare_exchange_acq_rel(
          size_t& var, size_t& exp, size_t des) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t old = AO_fetch_compare_and_swap_full(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        exp = (size_t)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    #ifdef AO_HAVE_load_full
    //! Atomic load (full barrier).
    static inline size_t load_seq_cst(size_t const& var) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (size_t)AO_load_full((AO_t const*)&var);
    }
    #endif // AO_HAVE_load_full

    #ifdef AO_HAVE_store_full
    //! Atomic store (full barrier).
    static inline void store_seq_cst(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_store_full((AO_t*)&var, (AO_t)val);
    }
    #endif // AO_HAVE_store_full

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic exchange (full barrier).
    static inline size_t exchange_seq_cst(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         (AO_t)val);
            AO_nop_full();
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic compare-and-swap (full barrier).
    static inline bool compare_exchange_seq_cst(
          size_t& var, size_t& exp, size_t des) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t old = AO_fetch_compare_and_swap(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        if (ret) {
            AO_nop_full();
        }
        exp = (size_t)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_and_add_full
    //! Atomic fetch-add (full barrier).
    static inline size_t fetch_add_seq_cst(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (size_t)(
            AO_fetch_and_add_full((AO_t*)&var, (AO_t)val));
    }
    #endif // AO_HAVE_fetch_and_add_full

    #ifdef AO_HAVE_fetch_and_add_full
    //! Atomic fetch-sub (full barrier).
    static inline size_t fetch_sub_seq_cst(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (size_t)(
            AO_fetch_and_add_full((AO_t*)&var, (AO_t)-val));
    }
    #endif // AO_HAVE_fetch_and_add_full

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic fetch-and (full barrier).
    static inline size_t fetch_and_seq_cst(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev & (AO_t)val);
            AO_nop_full();
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic fetch-or (full barrier).
    static inline size_t fetch_or_seq_cst(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev | (AO_t)val);
            AO_nop_full();
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic fetch-xor (full barrier).
    static inline size_t fetch_xor_seq_cst(size_t& var, size_t val) {
        struct TypeCheck {
            int f : sizeof(size_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev ^ (AO_t)val);
            AO_nop_full();
        } while (curr != prev);
        return (size_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    // overloads for ssize_t

    #ifdef AO_HAVE_load
    //! Atomic load (no barrier).
    static inline ssize_t load_relaxed(ssize_t const& var) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (ssize_t)AO_load((AO_t const*)&var);
    }
    #endif // AO_HAVE_load

    #ifdef AO_HAVE_store
    //! Atomic store (no barrier).
    static inline void store_relaxed(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_store((AO_t*)&var, (AO_t)val);
    }
    #endif // AO_HAVE_store

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic exchange (no barrier).
    static inline ssize_t exchange_relaxed(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic compare-and-swap (no barrier).
    static inline bool compare_exchange_relaxed(
          ssize_t& var, ssize_t& exp, ssize_t des) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t old = AO_fetch_compare_and_swap(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        exp = (ssize_t)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_and_add
    //! Atomic fetch-add (no barrier).
    static inline ssize_t fetch_add_relaxed(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (ssize_t)(
            AO_fetch_and_add((AO_t*)&var, (AO_t)val));
    }
    #endif // AO_HAVE_fetch_and_add

    #ifdef AO_HAVE_fetch_and_add
    //! Atomic fetch-sub (no barrier).
    static inline ssize_t fetch_sub_relaxed(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (ssize_t)(
            AO_fetch_and_add((AO_t*)&var, (AO_t)-val));
    }
    #endif // AO_HAVE_fetch_and_add

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic fetch-and (no barrier).
    static inline ssize_t fetch_and_relaxed(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev & (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic fetch-or (no barrier).
    static inline ssize_t fetch_or_relaxed(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev | (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic fetch-xor (no barrier).
    static inline ssize_t fetch_xor_relaxed(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev ^ (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_load_acquire
    //! Atomic load (acquire barrier).
    static inline ssize_t load_acquire(ssize_t const& var) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (ssize_t)AO_load_acquire((AO_t const*)&var);
    }
    #endif // AO_HAVE_load_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic exchange (acquire barrier).
    static inline ssize_t exchange_acquire(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_acquire((AO_t*)&var, prev,
                                                         (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic compare-and-swap (acquire barrier).
    static inline bool compare_exchange_acquire(
          ssize_t& var, ssize_t& exp, ssize_t des) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t old = AO_fetch_compare_and_swap_acquire(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        exp = (ssize_t)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_fetch_and_add_acquire
    //! Atomic fetch-add (acquire barrier).
    static inline ssize_t fetch_add_acquire(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (ssize_t)(
            AO_fetch_and_add_acquire((AO_t*)&var, (AO_t)val));
    }
    #endif // AO_HAVE_fetch_and_add_acquire

    #ifdef AO_HAVE_fetch_and_add_acquire
    //! Atomic fetch-sub (acquire barrier).
    static inline ssize_t fetch_sub_acquire(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (ssize_t)(
            AO_fetch_and_add_acquire((AO_t*)&var, (AO_t)-val));
    }
    #endif // AO_HAVE_fetch_and_add_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic fetch-and (acquire barrier).
    static inline ssize_t fetch_and_acquire(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_acquire((AO_t*)&var, prev,
                                                         prev & (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic fetch-or (acquire barrier).
    static inline ssize_t fetch_or_acquire(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_acquire((AO_t*)&var, prev,
                                                         prev | (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic fetch-xor (acquire barrier).
    static inline ssize_t fetch_xor_acquire(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_acquire((AO_t*)&var, prev,
                                                         prev ^ (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_store_release
    //! Atomic store (release barrier).
    static inline void store_release(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_store_release((AO_t*)&var, (AO_t)val);
    }
    #endif // AO_HAVE_store_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic exchange (release barrier).
    static inline ssize_t exchange_release(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_release((AO_t*)&var, prev,
                                                         (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic compare-and-swap (release barrier).
    static inline bool compare_exchange_release(
          ssize_t& var, ssize_t& exp, ssize_t des) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t old = AO_fetch_compare_and_swap_release(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        exp = (ssize_t)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_and_add_release
    //! Atomic fetch-add (release barrier).
    static inline ssize_t fetch_add_release(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (ssize_t)(
            AO_fetch_and_add_release((AO_t*)&var, (AO_t)val));
    }
    #endif // AO_HAVE_fetch_and_add_release

    #ifdef AO_HAVE_fetch_and_add_release
    //! Atomic fetch-sub (release barrier).
    static inline ssize_t fetch_sub_release(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (ssize_t)(
            AO_fetch_and_add_release((AO_t*)&var, (AO_t)-val));
    }
    #endif // AO_HAVE_fetch_and_add_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic fetch-and (release barrier).
    static inline ssize_t fetch_and_release(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_release((AO_t*)&var, prev,
                                                         prev & (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic fetch-or (release barrier).
    static inline ssize_t fetch_or_release(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_release((AO_t*)&var, prev,
                                                         prev | (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic fetch-xor (release barrier).
    static inline ssize_t fetch_xor_release(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_release((AO_t*)&var, prev,
                                                         prev ^ (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic exchange (acquire-release barrier).
    static inline ssize_t exchange_acq_rel(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_full((AO_t*)&var, prev,
                                                         (AO_t)val);
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic compare-and-swap (acquire-release barrier).
    static inline bool compare_exchange_acq_rel(
          ssize_t& var, ssize_t& exp, ssize_t des) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t old = AO_fetch_compare_and_swap_full(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        exp = (ssize_t)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    #ifdef AO_HAVE_load_full
    //! Atomic load (full barrier).
    static inline ssize_t load_seq_cst(ssize_t const& var) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (ssize_t)AO_load_full((AO_t const*)&var);
    }
    #endif // AO_HAVE_load_full

    #ifdef AO_HAVE_store_full
    //! Atomic store (full barrier).
    static inline void store_seq_cst(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_store_full((AO_t*)&var, (AO_t)val);
    }
    #endif // AO_HAVE_store_full

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic exchange (full barrier).
    static inline ssize_t exchange_seq_cst(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         (AO_t)val);
            AO_nop_full();
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic compare-and-swap (full barrier).
    static inline bool compare_exchange_seq_cst(
          ssize_t& var, ssize_t& exp, ssize_t des) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t old = AO_fetch_compare_and_swap(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        if (ret) {
            AO_nop_full();
        }
        exp = (ssize_t)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_and_add_full
    //! Atomic fetch-add (full barrier).
    static inline ssize_t fetch_add_seq_cst(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (ssize_t)(
            AO_fetch_and_add_full((AO_t*)&var, (AO_t)val));
    }
    #endif // AO_HAVE_fetch_and_add_full

    #ifdef AO_HAVE_fetch_and_add_full
    //! Atomic fetch-sub (full barrier).
    static inline ssize_t fetch_sub_seq_cst(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        return (ssize_t)(
            AO_fetch_and_add_full((AO_t*)&var, (AO_t)-val));
    }
    #endif // AO_HAVE_fetch_and_add_full

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic fetch-and (full barrier).
    static inline ssize_t fetch_and_seq_cst(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev & (AO_t)val);
            AO_nop_full();
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic fetch-or (full barrier).
    static inline ssize_t fetch_or_seq_cst(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev | (AO_t)val);
            AO_nop_full();
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic fetch-xor (full barrier).
    static inline ssize_t fetch_xor_seq_cst(ssize_t& var, ssize_t val) {
        struct TypeCheck {
            int f : sizeof(ssize_t) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev ^ (AO_t)val);
            AO_nop_full();
        } while (curr != prev);
        return (ssize_t)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    // overloads for T*

    #ifdef AO_HAVE_load
    //! Atomic load (no barrier).
    template <class T> static inline T* load_relaxed(T* const& var) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        return (T*)AO_load((AO_t const*)&var);
    }
    #endif // AO_HAVE_load

    #ifdef AO_HAVE_store
    //! Atomic store (no barrier).
    template <class T> static inline void store_relaxed(T*& var, T* val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_store((AO_t*)&var, (AO_t)val);
    }
    #endif // AO_HAVE_store

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic exchange (no barrier).
    template <class T> static inline T* exchange_relaxed(T*& var, T* val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic compare-and-swap (no barrier).
    template <class T> static inline bool compare_exchange_relaxed(
          T*& var, T*& exp, T* des) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t old = AO_fetch_compare_and_swap(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        exp = (T*)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_and_add
    //! Atomic fetch-add (no barrier).
    template <class T> static inline T* fetch_add_relaxed(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        return (T*)(
            AO_fetch_and_add((AO_t*)&var, (AO_t)val));
    }
    #endif // AO_HAVE_fetch_and_add

    #ifdef AO_HAVE_fetch_and_add
    //! Atomic fetch-sub (no barrier).
    template <class T> static inline T* fetch_sub_relaxed(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        return (T*)(
            AO_fetch_and_add((AO_t*)&var, (AO_t)-val));
    }
    #endif // AO_HAVE_fetch_and_add

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic fetch-and (no barrier).
    template <class T> static inline T* fetch_and_relaxed(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev & (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic fetch-or (no barrier).
    template <class T> static inline T* fetch_or_relaxed(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev | (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic fetch-xor (no barrier).
    template <class T> static inline T* fetch_xor_relaxed(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev ^ (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_load_acquire
    //! Atomic load (acquire barrier).
    template <class T> static inline T* load_acquire(T* const& var) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        return (T*)AO_load_acquire((AO_t const*)&var);
    }
    #endif // AO_HAVE_load_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic exchange (acquire barrier).
    template <class T> static inline T* exchange_acquire(T*& var, T* val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_acquire((AO_t*)&var, prev,
                                                         (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic compare-and-swap (acquire barrier).
    template <class T> static inline bool compare_exchange_acquire(
          T*& var, T*& exp, T* des) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t old = AO_fetch_compare_and_swap_acquire(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        exp = (T*)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_fetch_and_add_acquire
    //! Atomic fetch-add (acquire barrier).
    template <class T> static inline T* fetch_add_acquire(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        return (T*)(
            AO_fetch_and_add_acquire((AO_t*)&var, (AO_t)val));
    }
    #endif // AO_HAVE_fetch_and_add_acquire

    #ifdef AO_HAVE_fetch_and_add_acquire
    //! Atomic fetch-sub (acquire barrier).
    template <class T> static inline T* fetch_sub_acquire(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        return (T*)(
            AO_fetch_and_add_acquire((AO_t*)&var, (AO_t)-val));
    }
    #endif // AO_HAVE_fetch_and_add_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic fetch-and (acquire barrier).
    template <class T> static inline T* fetch_and_acquire(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_acquire((AO_t*)&var, prev,
                                                         prev & (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic fetch-or (acquire barrier).
    template <class T> static inline T* fetch_or_acquire(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_acquire((AO_t*)&var, prev,
                                                         prev | (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_fetch_compare_and_swap_acquire
    //! Atomic fetch-xor (acquire barrier).
    template <class T> static inline T* fetch_xor_acquire(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_acquire((AO_t*)&var, prev,
                                                         prev ^ (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_acquire

    #ifdef AO_HAVE_store_release
    //! Atomic store (release barrier).
    template <class T> static inline void store_release(T*& var, T* val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_store_release((AO_t*)&var, (AO_t)val);
    }
    #endif // AO_HAVE_store_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic exchange (release barrier).
    template <class T> static inline T* exchange_release(T*& var, T* val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_release((AO_t*)&var, prev,
                                                         (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic compare-and-swap (release barrier).
    template <class T> static inline bool compare_exchange_release(
          T*& var, T*& exp, T* des) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t old = AO_fetch_compare_and_swap_release(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        exp = (T*)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_and_add_release
    //! Atomic fetch-add (release barrier).
    template <class T> static inline T* fetch_add_release(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        return (T*)(
            AO_fetch_and_add_release((AO_t*)&var, (AO_t)val));
    }
    #endif // AO_HAVE_fetch_and_add_release

    #ifdef AO_HAVE_fetch_and_add_release
    //! Atomic fetch-sub (release barrier).
    template <class T> static inline T* fetch_sub_release(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        return (T*)(
            AO_fetch_and_add_release((AO_t*)&var, (AO_t)-val));
    }
    #endif // AO_HAVE_fetch_and_add_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic fetch-and (release barrier).
    template <class T> static inline T* fetch_and_release(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_release((AO_t*)&var, prev,
                                                         prev & (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic fetch-or (release barrier).
    template <class T> static inline T* fetch_or_release(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_release((AO_t*)&var, prev,
                                                         prev | (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_compare_and_swap_release
    //! Atomic fetch-xor (release barrier).
    template <class T> static inline T* fetch_xor_release(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_release((AO_t*)&var, prev,
                                                         prev ^ (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_release

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic exchange (acquire-release barrier).
    template <class T> static inline T* exchange_acq_rel(T*& var, T* val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap_full((AO_t*)&var, prev,
                                                         (AO_t)val);
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic compare-and-swap (acquire-release barrier).
    template <class T> static inline bool compare_exchange_acq_rel(
          T*& var, T*& exp, T* des) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_t old = AO_fetch_compare_and_swap_full(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        exp = (T*)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    #ifdef AO_HAVE_load_full
    //! Atomic load (full barrier).
    template <class T> static inline T* load_seq_cst(T* const& var) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        return (T*)AO_load_full((AO_t const*)&var);
    }
    #endif // AO_HAVE_load_full

    #ifdef AO_HAVE_store_full
    //! Atomic store (full barrier).
    template <class T> static inline void store_seq_cst(T*& var, T* val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_store_full((AO_t*)&var, (AO_t)val);
    }
    #endif // AO_HAVE_store_full

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic exchange (full barrier).
    template <class T> static inline T* exchange_seq_cst(T*& var, T* val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         (AO_t)val);
            AO_nop_full();
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_compare_and_swap
    //! Atomic compare-and-swap (full barrier).
    template <class T> static inline bool compare_exchange_seq_cst(
          T*& var, T*& exp, T* des) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t old = AO_fetch_compare_and_swap(
          (AO_t*)&var, (AO_t)exp, (AO_t)des);
        const bool ret = ((AO_t)exp == old);
        if (ret) {
            AO_nop_full();
        }
        exp = (T*)old;
        return ret;
    }
    #endif // AO_HAVE_fetch_compare_and_swap

    #ifdef AO_HAVE_fetch_and_add_full
    //! Atomic fetch-add (full barrier).
    template <class T> static inline T* fetch_add_seq_cst(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        return (T*)(
            AO_fetch_and_add_full((AO_t*)&var, (AO_t)val));
    }
    #endif // AO_HAVE_fetch_and_add_full

    #ifdef AO_HAVE_fetch_and_add_full
    //! Atomic fetch-sub (full barrier).
    template <class T> static inline T* fetch_sub_seq_cst(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        return (T*)(
            AO_fetch_and_add_full((AO_t*)&var, (AO_t)-val));
    }
    #endif // AO_HAVE_fetch_and_add_full

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic fetch-and (full barrier).
    template <class T> static inline T* fetch_and_seq_cst(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev & (AO_t)val);
            AO_nop_full();
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic fetch-or (full barrier).
    template <class T> static inline T* fetch_or_seq_cst(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev | (AO_t)val);
            AO_nop_full();
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full

    #ifdef AO_HAVE_fetch_compare_and_swap_full
    //! Atomic fetch-xor (full barrier).
    template <class T> static inline T* fetch_xor_seq_cst(T*& var, ptrdiff_t val) {
        struct TypeCheck {
            int f : sizeof(T*) == sizeof(AO_t) ? 1 : -1;
        };
        AO_nop_full();
        AO_t curr = AO_load((AO_t*)&var);
        AO_t prev;
        do {
            prev = curr;
            curr = AO_fetch_compare_and_swap((AO_t*)&var, prev,
                                                         prev ^ (AO_t)val);
            AO_nop_full();
        } while (curr != prev);
        return (T*)curr;
    }
    #endif // AO_HAVE_fetch_compare_and_swap_full
};

} // namespace core
} // namespace roc

#endif // ROC_CORE_ATOMIC_OPS_H_
