/*
 * Copyright (c) 2017 Roc Streaming authors
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/**
 * \file roc/context.h
 * \brief Shared context.
 */

#ifndef ROC_CONTEXT_H_
#define ROC_CONTEXT_H_

#include "roc/config.h"
#include "roc/platform.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Shared context.
 *
 * Context contains memory pools and network worker threads, shared among objects attached
 * to the context. It is allowed both to create a separate context for every object, or
 * to create a single context shared between multiple objects.
 *
 * **Life cycle**
 *
 * A context is created using roc_context_open() and destroyed using roc_context_close().
 * Objects can be attached and detached to an opened context at any moment from any
 * thread. However, the user should ensure that the context is not closed until there
 * are no objects attached to the context.
 *
 * **Thread safety**
 *
 * Can be used concurrently
 *
 * \see roc_sender, roc_receiver
 */
typedef struct roc_context roc_context;

/** Open a new context.
 *
 * Allocates and initializes a new context. May start some background threads.
 * Overrides the provided \p result pointer with the newly created context.
 *
 * **Parameters**
 *  - \p config should point to an initialized config
 *  - \p result should point to an unitialized roc_context pointer
 *
 * **Returns**
 *  - returns zero if the context was successfully created
 *  - returns a negative value if the arguments are invalid
 *  - returns a negative value if there are not enough resources
 *
 * **Ownership**
 *  - passes the ownership of \p result to the user; the user is responsible to call
 *    roc_context_close() to free it
 */
ROC_API int roc_context_open(const roc_context_config* config, roc_context** result);

/** Register custom encoding.
 *
 * Registers \p encoding with given \p encoding_id. Registered encodings complement
 * built-in encodings defined by \ref roc_packet_encoding enum. Whenever you need to
 * specify packet encoding, you can use both built-in and registered encodings.
 *
 * On sender, you should register custom encoding and set to \c packet_encoding field
 * of \c roc_sender_config, if you need to force specific encoding of packets, but
 * built-in set of encodings is not enough.
 *
 * On receiver, you should register custom encoding with same id and specification,
 * if you did so on sender, and you're not using any signaling protocol (like RTSP)
 * that is capable of automatic exchange of encoding information.
 *
 * In case of RTP, encoding id is mapped directly to payload type field (PT).
 *
 * **Parameters**
 *  - \p context should point to an opened context
 *  - \p encoding_id should be encoding identifier in range [1; 127]
 *  - \p encoding should point to valid encoding specification
 *
 * **Returns**
 *  - returns zero if encoding was successfully registered
 *  - returns a negative value if the arguments are invalid
 *  - returns a negative value if encoding with given identifier already exists
 *
 * **Ownership**
 *  - doesn't take or share the ownership of \p encoding; copies its contents
 *    to internal encodings table
 */
ROC_API int roc_context_register_encoding(roc_context* context,
                                          int encoding_id,
                                          const roc_media_encoding* encoding);

/** Close the context.
 *
 * Stops any started background threads, deinitializes and deallocates the context.
 * The user should ensure that nobody uses the context during and after this call.
 *
 * If this function fails, the context is kept opened.
 *
 * **Parameters**
 *  - \p context should point to an opened context
 *
 * **Returns**
 *  - returns zero if the context was successfully closed
 *  - returns a negative value if the arguments are invalid
 *  - returns a negative value if there are objects attached to the context
 *
 * **Ownership**
 *  - ends the user ownership of \p context; it can't be used anymore after the
 *    function returns
 */
ROC_API int roc_context_close(roc_context* context);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ROC_CONTEXT_H_ */
