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

#ifndef __FC_SIGNAL
#define __FC_SIGNAL

/* ISO C: 7.14 */

#include "features.h"
#include "__fc_define_pid_t.h"
#include "__fc_define_uid_and_gid.h"
#include "__fc_define_sigset_t.h"
#include "sys/types.h"
#include "time.h"

#include "errno.h"

__BEGIN_DECLS

/* TODO: put sig_atomic_t in machdep */
typedef volatile int sig_atomic_t;
typedef void (*__fc_sighandler_t) (int);


#define SIG_DFL ((__fc_sighandler_t)0)     /* default signal handling */
#define SIG_IGN ((__fc_sighandler_t)1)     /* ignore signal */
#define SIG_ERR ((__fc_sighandler_t)-1)    /* error return from signal */

#define SIG_BLOCK 0
#define SIG_UNBLOCK 1
#define SIG_SETMASK 2

#define SIGHUP       1
#define SIGINT       2
#define SIGQUIT      3
#define SIGILL       4
#define SIGTRAP      5
#define SIGABRT      6
#define SIGIOT       6
#define SIGBUS       7
#define SIGFPE       8
#define SIGKILL      9
#define SIGUSR1     10
#define SIGSEGV     11
#define SIGUSR2     12
#define SIGPIPE     13
#define SIGALRM     14
#define SIGTERM     15
#define SIGSTKFLT   16
#define SIGCHLD     17
#define SIGCONT     18
#define SIGSTOP     19
#define SIGTSTP     20
#define SIGTTIN     21
#define SIGTTOU     22
#define SIGURG      23
#define SIGXCPU     24
#define SIGXFSZ     25
#define SIGVTALRM   26
#define SIGPROF     27
#define SIGWINCH    28
#define SIGIO       29
#define SIGPOLL     SIGIO
#define SIGLOST     29
#define SIGPWR      30
#define SIGSYS      31
#define SIGUNUSED   31

#define SA_NOCLDSTOP (1 << 0)
#define SA_NOCLDWAIT (1 << 1)
#define SA_SIGINFO   (1 << 2)
#define SA_ONSTACK   (1 << 3)
#define SA_RESTART   (1 << 4)
#define SA_NODEFER   (1 << 5)
#define SA_RESETHAND (1 << 6)
#define SA_INTERRUPT (1 << 7)
#define SA_NOMASK    SA_NODEFER
#define SA_ONESHOT   SA_RESETHAND
#define SA_STACK     SA_ONSTACK
#define SA_NOMASK    SA_NODEFER
#define SA_ONESHOT   SA_RESETHAND

/*@ assigns \nothing; */
void (*signal(int sig, void (*func)(int)))(int);

/*@ 
  assigns \nothing;
  ensures \false; */
int raise(int sig);

union sigval {
    int sival_int;
    void *sival_ptr;
};
typedef struct {
    int si_signo;
    int si_code;
    union sigval si_value;
    int si_errno;
    pid_t si_pid;
    uid_t si_uid;
    void *si_addr;
    int si_status;
    int si_band;
    /* GNU Extension Members */
    int si_timerid;
    int si_overrun;
    clock_t si_utime;
    clock_t si_stime;
    int si_int;
    void* si_ptr;
    short int si_addr_lsb;
    void* si_lower;
    void* si_upper;
    int si_fd;
    void* si_call_addr;
    int si_syscall;
    unsigned int si_arch;
} siginfo_t;

struct sigevent {
    int sigev_notify;
    int sigev_signo;
    union sigval sigev_value;
    void (*sigev_notify_function)(union sigval);
    pthread_attr_t *sigev_notify_attributes;
};

struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
           };

typedef struct sigaltstack {
    void *ss_sp;
    size_t ss_size;
    int ss_flags;
} stack_t;

struct sigstack {
    void *ss_sp;
    int ss_onstack;
};

/*@
assigns \result \from pid, sig;
ensures \result == 0 ||  \result == -1;
*/
int kill(pid_t pid, int sig);

/*@
assigns \result \from pgrp, sig;
ensures \result == 0 ||  \result == -1;
*/
int killpg(pid_t pgrp, int sig);

/*@
requires message != \null ==> \valid(message);
requires \valid(pinfo);
*/
void psiginfo(const siginfo_t *pinfo, const char *message);

/*@
requires message != \null ==> \valid(message);
*/
void psignal(int signum, const char *message);

int pthread_kill(pthread_t thread, int sig);
int pthread_sigmask(int how, const sigset_t *restrict set, sigset_t *restrict oset);

/*@
requires \valid(set);
requires oset != \null ==> \valid(oset);
ensures \result == -1 || \result == 0;
*/
int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict oset);

/*@
requires act != \null ==> \valid(act);
requires oact != \null ==> \valid(oact);
ensures \result == 0 || \result == -1;
*/
int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);

/*@
requires \valid(set);
assigns \result, *set \from *set, signo;
ensures \result == 0 ||  \result == -1;
*/
int sigaddset(sigset_t *set, int signo);

/*@
requires ss != \null ==> \valid(ss);
requires oss != \null ==> \valid(oss);
ensures \result == 0 ||  \result == -1;
*/
int sigaltstack(const stack_t *restrict ss, stack_t *restrict oss);

/*@
requires \valid(set);
assigns \result, *set \from *set, signo;
ensures \result == 0 ||  \result == -1;
*/
int sigdelset(sigset_t *set, int signo);

/*@
requires \valid(set);
assigns \result, *set \from *set;
ensures \result == 0 ||  \result == -1;
*/
int sigemptyset(sigset_t *set);

/*@
requires \valid(set);
assigns \result, *set \from *set;
ensures \result == 0 ||  \result == -1;
*/
int sigfillset(sigset_t *set);

/*@
requires \valid(set);
assigns \result \from *set, signo;
ensures -1 <= \result <= 1;
*/
int sigismember(const sigset_t *set, int signo);

/*@
requires \valid(set);
assigns \result, *set \from *set;
ensures \result == 0 ||  \result == -1;
*/
int sigpending(sigset_t *set);

/*@
assigns \result \from pid, signo, value;
ensures \result == 0 ||  \result == -1;
*/
int sigqueue(pid_t pid, int signo, const union sigval value);

/*@
requires \valid(sigmask);
assigns \result \from *sigmask;
ensures \result == -1;
*/
int sigsuspend(const sigset_t *sigmask);

/*@
requires \valid(set);
requires \valid(info);
requires \valid(timeout);
assigns \result \from *set, *info, *timeout;
*/
int sigtimedwait(const sigset_t *restrict set, siginfo_t *restrict info, const struct timespec *restrict timeout);

/*@
requires \valid(set);
requires \valid(info);
assigns \result \from *set, *info;
*/
int sigwaitinfo(const sigset_t *restrict set, siginfo_t *restrict info);

/*@
requires \valid(set);
requires \valid(sig);
assigns \result \from *set, *sig;
*/
int sigwait(const sigset_t *restrict set, int *restrict sig);

/* GNU Extensions */

#define NSIG 32

#define SIGEV_NONE      0
#define SIGEV_SIGNAL    1
#define SIGEV_THREAD    2
#define SIGEV_THREAD_ID 3

#define SV_INTERRUPT (1 << 0)
#define SV_RESETHAND (1 << 1)
#define SV_ONSTACK   (1 << 2)

#define FP_XSTATE_MAGIC1      0x46505853U
#define FP_XSTATE_MAGIC2      0x46505845U
#define FP_XSTATE_MAGIC2_SIZE sizeof(FP_XSTATE_MAGIC2)

#define SI_ASYNCNL 0
#define SI_TKILL   1
#define SI_SIGIO   2
#define SI_ASYNCIO 3
#define SI_MESGQ   4
#define SI_TIMER   5
#define SI_QUEUE   6
#define SI_USER    7
#define SI_KERNEL  8

#define ILL_ILLOPC 1
#define ILL_ILLOPN 2
#define ILL_ILLADR 3
#define ILL_ILLTRP 4
#define ILL_PRVOPC 5
#define ILL_PRVREG 6
#define ILL_COPROC 7
#define ILL_BADSTK 8

#define FPE_INTDIV 1
#define FPE_INTOVF 2
#define FPE_FLTDIV 3
#define FPE_FLTOVF 4
#define FPE_FLTUND 5
#define FPE_FLTRES 6
#define FPE_FLTINV 7
#define FPE_FLTSUB 8

#define SEGV_MAPERR 1
#define SEGV_ACCERR 2

#define BUS_ADRALN    1
#define BUS_ADRERR    2
#define BUS_OBJERR    3
#define BUS_MCEERR_AR 4
#define BUS_MCEERR_AO 5

#define TRAP_BRKPT 1
#define TRAP_TRACE 2

#define CLD_EXITED    1
#define CLD_KILLED    2
#define CLD_DUMPED    3
#define CLD_TRAPPED   4
#define CLD_STOPPED   5
#define CLD_CONTINUED 6

#define POLL_IN  1
#define POLL_OUT 2
#define POLL_MSG 3
#define POLL_ERR 4
#define POLL_PRI 5
#define POLL_HUP 6

#define SIGRTMIN 0
#define SIGRTMAX 0

#define SS_ONSTACK (1 << 0)
#define SS_DISABLE (1 << 1)

#define MINSIGSTKSZ 2048
#define SIGSTKSZ    8192

typedef __fc_sighandler_t sighandler_t;
typedef __fc_sighandler_t sig_t; //BSD name for sighandler_t

extern const char *const _sys_siglist[NSIG];
extern const char *const sys_siglist[NSIG];

struct sigvec {
    void (*sv_handler)(int);
    int sv_mask;
    int sv_flags;
};

struct sigcontext {
    void* __gt_fc_dummy;
};

/*@
assigns errno, \result;
ensures \result == SIG_ERR ? errno != 0 : errno == \old(errno);
*/
sighandler_t sysv_signal(int signum, sighandler_t action);

/*@
assigns errno, \result;
ensures \result == SIG_ERR ? errno != 0 : errno == \old(errno);
*/
sighandler_t ssignal(int signum, sighandler_t action);

/*@
assigns errno, \result;
*/
int gsignal(int signum);

/*@
assigns errno, \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int siginterrupt(int signum, int failflag);

/*@
assigns \result;
*/
int sigmask(int signum);

/*@
assigns errno, \result;
*/
int sigblock(int mask);

/*@
assigns errno, \result;
*/
int sigsetmask(int mask);

/*@
assigns errno, \result;
*/
int sigpause(int mask);

/*@
assigns errno, \result;
*/
int siggetmask(void);

/*@
requires vec != \null ==> \valid_read(vec);
requires ovec != \null ==> \valid(ovec);
assigns errno, \result, *ovec;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sigvec(int sig, const struct sigvec *vec, struct sigvec *ovec);

/*@
assigns errno, \result;
ensures \result == SIG_ERR ? errno != 0 : errno == \old(errno);
*/
sighandler_t sigset(int sig, sighandler_t disp);

/*@
assigns errno, \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sighold(int sig);

/*@
assigns errno, \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sigrelse(int sig);

/*@
assigns errno, \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sigignore(int sig);

/*@
assigns errno, \result;
ensures \result == SIG_ERR ? errno != 0 : errno == \old(errno);
*/
sighandler_t bsd_signal(int signum, sighandler_t handler);

/*@
requires \valid(scp);
assigns \result;
ensures \false;
*/
int sigreturn(struct sigcontext *scp);

/*@
requires \valid(set);
assigns \result \from *set;
ensures -1 <= \result <= 1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sigisemptyset(const sigset_t *set);

/*@
requires \valid(set);
requires \valid(left);
requires \valid(right);
assigns \result, *set \from *left, *right;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sigandset(sigset_t *set, const sigset_t *left, const sigset_t *right);

/*@
requires \valid(set);
requires \valid(left);
requires \valid(right);
assigns \result, *set \from *left, *right;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sigorset(sigset_t *set, const sigset_t *left, const sigset_t *right);

/*@
requires \valid(ss);
requires oss != \null ==> \valid(oss);
assigns errno, \result, *oss;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sigstack(struct sigstack *ss, struct sigstack *oss);

__END_DECLS

#endif
