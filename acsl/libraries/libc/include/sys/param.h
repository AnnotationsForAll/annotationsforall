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

#ifndef __FC_SYS_PARAM_H__
#define __FC_SYS_PARAM_H__

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../limits.h"
#include "../endian.h"
#include "../signal.h"
#include "types.h"

/*
This is a header for compatibility with old Unix headers. It defines a lot of miscellaneous macros.
Things may need to be added here on a case-by-case basis for compatibility.
*/

#define HZ             100
#define EXEC_PAGESIZE  4096
#define NOGROUP        (-1)
#define MAXHOSTNAMELEN 64
#define NBBY           CHAR_BIT
#define NCARGS         INT_MAX
#define NODEV          ((dev_t) -1)
#define DEV_BSIZE      512

#define setbit(a,i) ((a)[(i)/NBBY] |= 1<<((i)%NBBY))
#define clrbit(a,i) ((a)[(i)/NBBY] &= ~(1<<((i)%NBBY)))
#define isset(a,i)  ((a)[(i)/NBBY] & (1<<((i)%NBBY)))
#define isclr(a,i)  (((a)[(i)/NBBY] & (1<<((i)%NBBY))) == 0)

#define howmany(x, y) (((x) + ((y) - 1)) / (y))
#define roundup(x, y) ((((x) + ((y) - 1)) / (y)) * (y))
#define powerof2(x)   ((((x) - 1) & (x)) == 0)

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#endif
