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

#ifndef __FC_WAIT_H__
#define __FC_WAIT_H__

#define WNOHANG    0
#define WUNTRACED  1
#define WEXITED    2
#define WSTOPPED   3
#define WCONTINUED 4
#define WNOWAIT    5

#include "../__fc_define_pid_t.h"
#include "../__fc_define_uid_and_gid.h"
#include "../signal.h"


typedef enum __FC_IDTYPE_T {
    P_ALL,
    P_PID,
    P_PGID
} idtype_t;

/*@
requires stat_loc != \null ==> \valid(stat_loc);
assigns \result, *stat_loc \from \nothing;
*/
pid_t wait(int *stat_loc);

/*@
requires \valid(sig);
assigns \result, *sig \from idt, id, options;
ensures \result == -1 || \result == 0;
*/
int waitid(idtype_t idt, id_t id, siginfo_t * sig, int options);

/*@
requires stat_loc != \null ==> \valid(stat_loc);
assigns \result, *stat_loc \from pid, options;
*/
pid_t waitpid(pid_t pid, int *stat_loc, int options);

/* BSD Extensions */

#define W_EXITCODE(ret, sig) ((ret) << 8 | (sig))
#define W_STOPCODE(sig)      ((sig) << 8 | 0x7f)
#define W_CONTINUED          0xffff
#define WCOREFLAG            0x80

#define WEXITSTATUS(status)  (((status) & 0xff00) >> 8)
#define WTERMSIG(status)     ((status) & 0x7f)
#define WSTOPSIG(status)     WEXITSTATUS(status)
#define WIFEXITED(status)    (WTERMSIG(status) == 0)
#define WIFSIGNALED(status)  (((signed char) (((status) & 0x7f) + 1) >> 1) > 0)
#define WIFSTOPPED(status)   (((status) & 0xff) == 0x7f)
#define WIFCONTINUED(status) ((status) == W_CONTINUED)
#define WCOREDUMP(status)    ((status) & WCOREFLAG)

union wait {
    int w_status;
    int w_termsig;
    int w_coredump;
    int w_retcode;
    int w_stopsig;
};

#if defined __USE_BSD || defined __USE_XOPEN_EXTENDED
#include "resource.h"

/*@
requires status_ptr != \null ==> \valid(status_ptr);
requires usage != \null ==> \valid(usage);
assigns \result, *status_ptr, *usage \from options;
ensures \result == -1 || \result == 0;
*/
pid_t wait3(union wait *status_ptr, int options, struct rusage *usage);

/*@
requires status_ptr != \null ==> \valid(status_ptr);
requires usage != \null ==> \valid(usage);
assigns \result, *status_ptr, *usage \from pid, options;
ensures \result == -1 || \result == 0;
*/
pid_t wait4(pid_t pid, union wait *status_ptr, int options, struct rusage *usage);

#endif

#endif

