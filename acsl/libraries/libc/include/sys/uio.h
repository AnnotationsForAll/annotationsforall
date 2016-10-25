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

#ifndef FC_UIO
#define FC_UIO

#include "../__fc_define_ssize_t.h"
#include "../__fc_define_size_t.h"
#include "../__fc_define_off_t.h"
#include "../__fc_define_iovec.h"
#include "../__fc_define_pid_t.h"

/*@
requires \valid( iov+(0..iovcnt-1) );
assigns \result, iov[0 .. iovcnt -1] \from fd, iovcnt;
ensures -1 <= \result <= iovcnt;
 */
ssize_t readv(int fd, const struct iovec *iov, int iovcnt);

/*@
requires \valid_read( iov+(0..iovcnt-1) );
assigns \result \from fd, iov[0 .. iovcnt -1], iovcnt;
ensures -1 <= \result <= iovcnt;
 */
ssize_t writev(int fd, const struct iovec *iov, int iovcnt);

/*@
requires \valid( iov+(0..iovcnt-1) );
assigns \result, iov[0 .. iovcnt -1] \from fd, iovcnt;
ensures -1 <= \result <= iovcnt;
 */
ssize_t preadv(int fd, const struct iovec *iov, int iovcnt, off_t offset);

/*@
requires \valid_read( iov+(0..iovcnt-1) );
assigns \result \from fd, iov[0 .. iovcnt -1], iovcnt;
ensures -1 <= \result <= iovcnt;
 */
ssize_t pwritev(int fd, const struct iovec *iov, int iovcnt, off_t offset);

/*@
requires \valid( iov+(0..iovcnt-1) );
assigns \result, iov[0 .. iovcnt -1] \from fd, iovcnt;
ensures -1 <= \result <= iovcnt;
 */
ssize_t preadv64(int fd, const struct iovec *iov, int iovcnt, off64_t offset);

/*@
requires \valid_read( iov+(0..iovcnt-1) );
assigns \result \from fd, iov[0 .. iovcnt -1], iovcnt;
ensures -1 <= \result <= iovcnt;
 */
ssize_t pwritev64(int fd, const struct iovec *iov, int iovcnt, off64_t offset);

#endif
