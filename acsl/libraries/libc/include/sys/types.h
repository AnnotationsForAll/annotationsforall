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

#ifndef __FC_SYS_TYPES_H__
#define __FC_SYS_TYPES_H__

#include "../__fc_machdep.h"
#include "../__fc_define_id_t.h"
#include "../__fc_define_pid_t.h"
#include "../__fc_define_ssize_t.h"
#include "../__fc_define_uid_and_gid.h"
#include "../__fc_define_time_t.h"
#include "../__fc_define_suseconds_t.h"
#include "../__fc_define_ino_t.h"
#include "../__fc_define_blkcnt_t.h"
#include "../__fc_define_blksize_t.h"
#include "../__fc_define_dev_t.h"
#include "../__fc_define_mode_t.h"
#include "../__fc_define_nlink_t.h"
#include "../__fc_define_off_t.h"
#include "../__gt_fc_define_clock_t.h"
#include "../__gt_fc_define_alternative_types.h"
#include "../__gt_fc_define_caddr_t.h"
#include "../__gt_fc_define_fs_types.h"

#include "sysmacros.h"

typedef char* pthread_t;
typedef char* pthread_attr_t;
typedef char* pthread_barrier_t;
typedef char* pthread_barrierattr_t;
typedef char* pthread_cond_t;
typedef char* pthread_condattr_t;
typedef char* pthread_key_t;
typedef char* pthread_mutex_t;
typedef char* pthread_mutexattr_t;
typedef char* pthread_once_t;
typedef char* pthread_rwlock_t;
typedef char* pthread_rwlockattr_t;
typedef char* pthread_spinlock_t;

typedef long long key_t;
typedef unsigned int timer_t;

typedef void* trace_attr_t;
typedef void* trace_event_id_t;
typedef void* trace_event_set_t;
typedef void* trace_id_t;

/* GNU Extensions */

typedef int register_t;

#endif
