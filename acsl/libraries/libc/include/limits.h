/**************************************************************************/
/*                                                                        */
/*  This file is part of Frama-C.                                         */
/*                                                                        */
/*  Copyright (C) 2007-2015                                               */
/*    CEA (Commissariat à l'énergie atomique et aux énergies              */
/*         alternatives)                                                  */
/*                                                                        */
/*  you can redistribute it and/or modify it under the terms of the GNU   */
/*  Lesser General Public License as published by the Free Software       */
/*  Foundation, version 2.1.                                              */
/*                                                                        */
/*  It is distributed in the hope that it will be useful,                 */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/*  GNU Lesser General Public License for more details.                   */
/*                                                                        */
/*  See the GNU Lesser General Public License version 2.1                 */
/*  for more details (enclosed in the file licenses/LGPLv2.1).            */
/*                                                                        */
/**************************************************************************/

/* ISO C: 7.10 and 5.2.4.2.1 */
#ifndef __FC_LIMITS
#define __FC_LIMITS

#include "__fc_machdep.h"

/* Number of bits in a `char'.  */
#define CHAR_BIT __CHAR_BIT


/* Minimum and maximum values a `signed char' can hold.  */
#  define SCHAR_MIN __FC_SCHAR_MIN
#  define SCHAR_MAX __FC_SCHAR_MAX

/* Maximum value an `unsigned char' can hold.  (Minimum is 0.)  */
#  define UCHAR_MAX __FC_UCHAR_MAX

/* Minimum and maximum values a `char' can hold.  */
#  ifdef __CHAR_UNSIGNED__
#   define CHAR_MIN 0
#   define CHAR_MAX UCHAR_MAX
#  else
#   define CHAR_MIN SCHAR_MIN
#   define CHAR_MAX SCHAR_MAX
#  endif

#define MB_LEN_MAX 16

/* Minimum and maximum values a `signed short int' can hold.  */
#  define SHRT_MIN  __FC_SHRT_MIN
#  define SHRT_MAX  __FC_SHRT_MAX

/* Maximum value an `unsigned short int' can hold.  (Minimum is 0.)  */
#  define USHRT_MAX     __FC_USHRT_MAX

/* Minimum and maximum values a `signed int' can hold.  */
#  define INT_MIN   __FC_INT_MIN
#  define INT_MAX   __FC_INT_MAX

/* Maximum value an `unsigned int' can hold.  (Minimum is 0.)  */
#  define UINT_MAX  __FC_UINT_MAX

/* Minimum and maximum values a `signed long int' can hold.  */
#  define LONG_MAX  __FC_LONG_MAX
#  define LONG_MIN  __FC_LONG_MIN

/* Maximum value an `unsigned long int' can hold.  (Minimum is 0.)  */
#define ULONG_MAX   __FC_ULONG_MAX

/* Minimum and maximum values a `signed long long int' can hold.  */
#   define LLONG_MAX    __FC_LLONG_MAX
#   define LLONG_MIN    __FC_LLONG_MIN

/* Maximum value an `unsigned long long int' can hold.  (Minimum is 0.)  */
#   define ULLONG_MAX   __FC_ULLONG_MAX

/* Maximum number of bytes in a pathname, including the terminating
   null character. (Minimum is 256.) */
#define PATH_MAX  __FC_PATH_MAX

/* Default process priority. Minimum Acceptable Value: 20 */
#define NZERO 20

/* POSIX requires that these following values are the minimum possible value for the corresponding sysconf value. */

#define _POSIX_AIO_LISTIO_MAX 2
#define _POSIX_AIO_MAX 1
#define _POSIX_ARG_MAX 4096
#define _POSIX_CHILD_MAX 6
#define _POSIX_NGROUPS_MAX 0
#define _POSIX_OPEN_MAX 16
#define _POSIX_SSIZE_MAX 32767
#define _POSIX_STREAM_MAX 8
#define _POSIX_TZNAME_MAX 3
#define _POSIX2_RE_DUP_MAX 255

#define _POSIX_LINK_MAX 8
#define _POSIX_MAX_CANON 255
#define _POSIX_MAX_INPUT 255
#define _POSIX_NAME_MAX 14
#define _POSIX_PATH_MAX 256
#define _POSIX_PIPE_BUF 512
#define SYMLINK_MAX 1024
#define POSIX_REC_INCR_XFER_SIZE 1024
#define POSIX_REC_MAX_XFER_SIZE 1024
#define POSIX_REC_MIN_XFER_SIZE 0
#define POSIX_REC_XFER_ALIGN 1

#define _POSIX2_BC_BASE_MAX 99
#define _POSIX2_BC_DIM_MAX 2048
#define _POSIX2_BC_SCALE_MAX 99
#define _POSIX2_BC_STRING_MAX 1000
#define _POSIX2_COLL_WEIGHTS_MAX 2
#define _POSIX2_EXPR_NEST_MAX 32
#define _POSIX2_LINE_MAX 2048
#define _POSIX2_EQUIV_CLASS_MAX 2

#define _POSIX_VDISABLE '\0'

#endif

