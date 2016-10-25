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

#ifndef __FC_SYS_RESOURCE_H__
#define __FC_SYS_RESOURCE_H__
#include "time.h"
#include "limits.h"
#include "../unistd.h"
#include "../__fc_define_id_t.h"

#define PRIO_PROCESS    0
#define PRIO_PGRP       1
#define PRIO_USER       2

typedef unsigned long rlim_t;
struct rlimit {
        rlim_t   rlim_cur;
        rlim_t   rlim_max;
};

struct rusage {
  struct timeval ru_utime;
  struct timeval ru_stime;
  // The following members are GNU extensions. Do not use for strictly POSIX compliant work.
  long int ru_maxrss;
  long int ru_ixrss;
  long int ru_idrss;
  long int ru_isrss;
  long int ru_minflt;
  long int ru_majflt;
  long int ru_nswap;
  long int ru_inblock;
  long int ru_oublock;
  long int ru_msgsnd;
  long int ru_msgrcv;
  long int ru_nsignals;
  long int ru_nvcsw;
  long int ru_nivcsw;
};

#define RLIM_INFINITY 0xFFFFFFFFul
#define RLIM_SAVED_MAX RLIM_INFINITY
#define RLIM_SAVED_CUR RLIM_INFINITY

#define RUSAGE_SELF 0
#define RUSAGE_CHILDREN 1

#define RLIMIT_CORE 0
#define RLIMIT_CPU 1
#define RLIMIT_DATA 2
#define RLIMIT_FSIZE 3
#define RLIMIT_NOFILE 4
#define RLIMIT_STACK 5
#define RLIMIT_AS 6

/*@
predicate valid_prio_value(int which) = which == PRIO_PROCESS || which == PRIO_PGRP || which == PRIO_USER;
*/

/*@
requires valid_prio_value(which);
assigns \result \from which, who;
ensures \result == -1 || -NZERO <= \result <= NZERO-1;
*/
int getpriority(int which, id_t who);

/*@
requires valid_prio_value(which);
assigns \result \from which, who, prio;
ensures \result == 0 || \result == -1;
*/
int setpriority(int which, id_t who, int prio);

/*@
requires \valid(rl);
assigns \result, *rl \from r;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> rl->rlim_cur <= rl->rlim_max;
*/
int getrlimit(int r, struct rlimit *rl);

/*@
requires \valid(ru);
assigns \result, *ru \from r;
ensures \result == 0 || \result == -1;
*/
int getrusage(int r, struct rusage *ru);

/*@
requires \valid(rl);
assigns \result \from r, rl->rlim_cur, rl->rlim_max;
ensures \result == 0 || \result == -1;
*/
int setrlimit(int r, const struct rlimit * rl);

/* GNU Extensions */

#define RLIM_NLIMITS 11

#define RLIMIT_RSS 7
#define RLIMIT_MEMLOCK 8
#define RLIMIT_NPROC 9
#define RLIMIT_OFILE 10

#define PRIO_MIN -NZERO
#define PRIO_MAX NZERO-1

typedef unsigned long rlim64_t;
struct rlimit64 {
        rlim64_t   rlim_cur;
        rlim64_t   rlim_max;
};

/*@
requires \valid(rl);
assigns \result, *rl \from r;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> rl->rlim_cur <= rl->rlim_max;
*/
int getrlimit64 (int r, struct rlimit64 *rl);

/*@
requires \valid(rl);
assigns \result \from r, rl->rlim_cur, rl->rlim_max;
ensures \result == 0 || \result == -1;
*/
int setrlimit64 (int r, const struct rlimit64 *rl);

/*@
requires old_limit != \null ==> \valid(old_limit);
requires new_limit != \null ==> \valid_read(new_limit);
assigns \result, *old_limit;
ensures \result == 0 || \result == -1;
*/
int prlimit(pid_t pid, int resource, const struct rlimit *new_limit, struct rlimit *old_limit);

/*@
requires old_limit != \null ==> \valid(old_limit);
requires new_limit != \null ==> \valid_read(new_limit);
assigns \result, *old_limit;
ensures \result == 0 || \result == -1;
*/
int prlimit64(pid_t pid, int resource, const struct rlimit64 *new_limit, struct rlimit64 *old_limit);

#endif
