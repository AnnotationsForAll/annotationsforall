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

#ifndef __FC_DEFINE_STAT_H
#define __FC_DEFINE_STAT_H
#include "features.h"


#include "__fc_define_ino_t.h"
#include "__fc_define_uid_and_gid.h"
#include "__fc_define_time_t.h"
#include "__fc_define_blkcnt_t.h"
#include "__fc_define_blksize_t.h"
#include "__fc_define_dev_t.h"
#include "__fc_define_mode_t.h"
#include "__fc_define_nlink_t.h"
#include "__fc_define_off_t.h"

__BEGIN_DECLS

struct stat {
  dev_t     st_dev;
  ino_t     st_ino;
  mode_t    st_mode;
  nlink_t   st_nlink;
  uid_t     st_uid;
  gid_t     st_gid;
  dev_t     st_rdev;
  off_t     st_size;
  time_t    st_atime;
  time_t    st_mtime;
  time_t    st_ctime;
  blksize_t st_blksize;
  blkcnt_t  st_blocks;

  // These are not part of the spec, but exist in practice - usually a macro for st_atime etc.
  struct timespec   st_atim;
  unsigned long int st_atime_usec;
  struct timespec   st_mtim;
  unsigned long int st_mtime_usec;
  struct timespec   st_ctim;
  unsigned long int st_ctime_usec;
};

/* GNU Extensions */

struct stat64 {
    mode_t st_mode;
    ino64_t st_ino;
    dev_t st_dev;
    nlink_t st_nlink;
    uid_t st_uid;
    gid_t st_gid;
    off64_t st_size;
    time_t st_atime;
    unsigned long int st_atime_usec;
    time_t st_mtime;
    unsigned long int st_mtime_usec;
    time_t st_ctime;
    unsigned long int st_ctime_usec;
    blkcnt64_t st_blocks;
    unsigned int st_blksize;
};

__END_DECLS

#endif
