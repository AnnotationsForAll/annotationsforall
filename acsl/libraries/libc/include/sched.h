/*
 * sched.h
 *
 *  Created on: Jul 15, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_SCHED_H_
#define LIBC_SCHED_H_

#include "__fc_define_time_t.h"
#include "__fc_define_timespec.h"
#include "__fc_define_pid_t.h"

#include "errno.h"

#define SCHED_FIFO     0
#define SCHED_RR       1
#define SCHED_SPORADIC 2
#define SCHED_OTHER    3
#define SCHED_BATCH    4
#define SCHED_IDLE     5

typedef struct sched_param {
    int sched_priority;
    int sched_ss_low_priority;
    struct timespec sched_ss_repl_period;
    struct timespec sched_ss_init_budget;
    int sched_ss_max_repl;
} sched_param;

/*@
requires \valid(param);
assigns errno, \result \from pid, policy, *param;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param);

/*@
assigns \result \from pid;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sched_getscheduler(pid_t pid);

/*@
requires \valid(param);
assigns errno, \result \from pid, *param;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sched_setparam(pid_t pid, const struct sched_param *param);

/*@
requires \valid(param);
assigns errno, \result, *param \from pid;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sched_getparam(pid_t pid, struct sched_param *param);

/*@
assigns errno, \result \from policy;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sched_get_priority_min(int policy);

/*@
assigns errno, \result \from policy;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sched_get_priority_max(int policy);

/*@
requires \valid(interval);
assigns errno, \result, *interval \from pid;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sched_rr_get_interval(pid_t pid, struct timespec *interval);

/*@
assigns errno, \result \from \nothing;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sched_yield(void);

/* GNU Extensions */

#define CPU_SETSIZE (sizeof(cpu_set_t)*8)
#define CPU_ALLOC(cpus) (malloc(CPU_ALLOC_SIZE(cpus)))
#define CPU_FREE(set) (free((set)))
#define CPU_ALLOC_SIZE(cpus) ((cpus)/8 + ((cpus)%8 != 0))

#define CPU_ZERO(set) (*(set) = 0)
#define CPU_SET(cpu,set) (*(set) |= (1 << (cpu)))
#define CPU_CLR(cpu,set) (*(set) &= ~(1 << (cpu)))
#define CPU_ISSET(cpu,set) (*(set) & (1 << (cpu)))
#define CPU_COUNT(set) ((((((((*(set)) - ((*(set)) >> 1) & 0x5555555555555555) & 0x3333333333333333) + ((((*(set)) - ((*(set)) >> 1) & 0x5555555555555555) >> 2) & 0x3333333333333333)) + (((((*(set)) - ((*(set)) >> 1) & 0x5555555555555555) & 0x3333333333333333) + ((((*(set)) - ((*(set)) >> 1) & 0x5555555555555555) >> 2) & 0x3333333333333333)) >> 4)) & 0x0f0f0f0f0f0f0f0f) * 0x0101010101010101)>>56)  //this macro counts the number of 1s in the cpu set, using a very dense algorithm. Sorry!
#define CPU_AND(dest,src1,src2) (*(dest) = (*(src1)) & (*(src2)))
#define CPU_OR(dest,src1,src2) (*(dest) = (*(src1)) | (*(src2)))
#define CPU_XOR(dest,src1,src2) (*(dest) = (*(src1)) ^ (*(src2)))
#define CPU_EQUAL(set1,set2) ((*(set1)) == (*(set2)))

//FIXME how to make sized macros?
#define CPU_ZERO_S(size,set) (*(set) = 0)
#define CPU_SET_S(cpu,size,set) (*(set) |= (1 << (cpu)))
#define CPU_CLR_S(cpu,size,set) (*(set) &= ~(1 << (cpu)))
#define CPU_ISSET_S(cpu,size,set) (*(set) & (1 << (cpu)))
#define CPU_COUNT_S(size,set) ((((((((*(set)) - ((*(set)) >> 1) & 0x5555555555555555) & 0x3333333333333333) + ((((*(set)) - ((*(set)) >> 1) & 0x5555555555555555) >> 2) & 0x3333333333333333)) + (((((*(set)) - ((*(set)) >> 1) & 0x5555555555555555) & 0x3333333333333333) + ((((*(set)) - ((*(set)) >> 1) & 0x5555555555555555) >> 2) & 0x3333333333333333)) >> 4)) & 0x0f0f0f0f0f0f0f0f) * 0x0101010101010101)>>56)
#define CPU_AND_S(size1,dest,size2,src1,size3,src2) (*(dest) = (*(src1)) & (*(src2)))
#define CPU_OR_S(size1,dest,size2,src1,size3,src2) (*(dest) = (*(src1)) | (*(src2)))
#define CPU_XOR_S(size1,dest,size2,src1,size3,src2) (*(dest) = (*(src1)) ^ (*(src2)))
#define CPU_EQUAL_S(size1,set1,size2,set2) ((*(set1)) == (*(set2)))

#define CLONE_CHILD_CLEARTID (1 << 0)
#define CLONE_CHILD_SETTID   (1 << 1)
#define CLONE_FILES          (1 << 2)
#define CLONE_FS             (1 << 3)
#define CLONE_IO             (1 << 4)
#define CLONE_NEWCGROUP      (1 << 5)
#define CLONE_NEWIPC         (1 << 6)
#define CLONE_NEWNET         (1 << 7)
#define CLONE_NEWNS          (1 << 8)
#define CLONE_NEWPID         (1 << 9)
#define CLONE_NEWUSER        (1 << 10)
#define CLONE_NEWUTS         (1 << 11)
#define CLONE_PARENT         (1 << 12)
#define CLONE_PARENT_SETTID  (1 << 13)
#define CLONE_PID            (1 << 14)
#define CLONE_PTRACE         (1 << 15)
#define CLONE_SETTLS         (1 << 16)
#define CLONE_SIGHAND        (1 << 17)
#define CLONE_STOPPED        (1 << 18)
#define CLONE_SYSVSEM        (1 << 19)
#define CLONE_THREAD         (1 << 20)
#define CLONE_UNTRACED       (1 << 21)
#define CLONE_VFORK          (1 << 22)
#define CLONE_VM             (1 << 23)
#define CSIGNAL              (1 << 24)

#define SCHED_RESET_ON_FORK 0x40000000

typedef unsigned long cpu_set_t;

/*@
requires \valid(cpuset);
requires cpusetsize >= sizeof(cpu_set_t);
assigns errno, \result, *cpuset \from pid, cpusetsize;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sched_getaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *cpuset);

/*@
requires \valid(cpuset);
requires cpusetsize >= sizeof(cpu_set_t);
assigns errno, \result \from pid, cpusetsize, *cpuset;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sched_setaffinity(pid_t pid, size_t cpusetsize, const cpu_set_t *cpuset);

/*@
requires fn != \null;
requires child_stack != \null;
ensures \result >= -1;
*/
int clone(int (*fn)(void *), void *child_stack, int flags, void *arg, ...);

/*@
assigns \result, errno;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setns(int fd, int nstype);

/*@
assigns \result, errno;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int unshare(int flags);

/*@
assigns \result, errno;
ensures \result >= -1;
ensures \result == -1 ? errno == ENOSYS : errno == \old(errno);
*/
int sched_getcpu(void);

#endif /* LIBC_SCHED_H_ */
