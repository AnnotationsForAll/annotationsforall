/*
 * types.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_TYPES_H_
#define LIBC_RPC_TYPES_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_null.h"

// The following headers are not needed, but programs may expect these to be exposed with this header:
#include "../sys/time.h"
#include "../sys/param.h"
#include "../netinet/in.h"
#include "../stdlib.h"

#ifndef FALSE
# define  FALSE (0)
#endif

#ifndef TRUE
# define  TRUE  (1)
#endif

#define mem_alloc(bsize) malloc(bsize)
#define mem_free(ptr, bsize) free(ptr)

typedef int bool_t;
typedef int enum_t;
typedef unsigned long rpcprog_t;
typedef unsigned long rpcvers_t;
typedef unsigned long rpcproc_t;
typedef unsigned long rpcprot_t;
typedef unsigned long rpcport_t;

#endif /* LIBC_RPC_TYPES_H_ */
