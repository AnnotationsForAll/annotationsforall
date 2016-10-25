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

/* Copyright (C) 1997 Free Software Foundation, Inc.
 This file is part of the GNU C Library.

 The GNU C Library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 The GNU C Library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with the GNU C Library; if not, write to the Free
 Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 02111-1307 USA.  */

#ifndef _BYTESWAP_H
#define _BYTESWAP_H

#define bswap_16(x) ((((x) << 8) & 0xff00) | (((x) >> 8) & 0x00ff))
#define bswap_32(x) ((((x) << 24) & 0xff000000) | (((x) << 8) & 0x00ff0000) | (((x) >> 8) & 0x0000ff00) | (((x) >> 24) & 0x000000ff))
#define bswap_64(x) ((((x) << 56) & 0xff00000000000000L) | (((x) << 40) & 0x00ff000000000000L) | (((x) << 24) & 0x0000ff0000000000L) | (((x) << 8) & 0x000000ff00000000L) | (((x) >> 8) & 0x00000000ff000000L) | (((x) >> 24) & 0x0000000000ff0000L) | (((x) >> 40) & 0x000000000000ff00L) | (((x) >> 56) & 0x00000000000000ffL))

#endif /* byteswap.h */

