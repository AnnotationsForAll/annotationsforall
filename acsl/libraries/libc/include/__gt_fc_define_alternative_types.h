#ifndef __GT_FC_DEFINE_ALT_TYPES
#define __GT_FC_DEFINE_ALT_TYPES
#include "__fc_machdep.h"
#include "features.h"

__BEGIN_DECLS

/* ISO C: 7.18.1.1 */
#ifdef __INT8_T
typedef __INT8_T int8_t;
#endif
#ifdef __UINT8_T
typedef __UINT8_T uint8_t;
typedef __UINT8_T u_int8_t;
#endif
#ifdef __INT16_T
typedef __INT16_T int16_t;
#endif
#ifdef __UINT16_T
typedef __UINT16_T uint16_t;
typedef __UINT16_T u_int16_t;
#endif
#ifdef __INT32_T
typedef __INT32_T int32_t;
#endif
#ifdef __UINT32_T
typedef __UINT32_T uint32_t;
typedef __UINT32_T u_int32_t;
#endif
#ifdef __INT64_T
typedef __INT64_T int64_t;
typedef int64_t quad_t;
#endif
#ifdef __UINT64_T
typedef __UINT64_T uint64_t;
typedef __UINT64_T u_int64_t;
typedef u_int64_t u_quad_t;
#endif

// Sys V compatibility
typedef unsigned char  unchar;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;

// BSD compatibility
typedef unsigned char  u_char;
typedef unsigned short u_short;
typedef unsigned int   u_int;
typedef unsigned long  u_long;

__END_DECLS

#endif

