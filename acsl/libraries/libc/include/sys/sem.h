/*
 * sem.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_SEM_H_
#define LIBC_SYS_SEM_H_

#include "ipc.h"
#include "../__fc_define_pid_t.h"
#include "../__fc_define_size_t.h"
#include "../__fc_define_time_t.h"
#include "../__fc_define_timespec.h"
#include "errno.h"

#define SEM_UNDO 1
#define SEM_STAT 2
#define SEM_INFO 3

#define GETNCNT 1
#define GETPID 2
#define GETVAL 3
#define GETALL 4
#define GETZCNT 5
#define SETVAL 6
#define SETALL 7

struct semid_ds {
    struct ipc_perm ipc_perm;
    unsigned short sem_nsems;
    time_t sem_otime;
    time_t sem_ctime;
};

struct __gt_fc_semaphore {
    unsigned short semval;
    pid_t sempid;
    unsigned short semncnt;
    unsigned short semzcnt;
};

struct sembuf {
    unsigned short sem_num;
    short sem_op;
    short sem_flg;
};

struct seminfo {
    int semmap;
    int semmni;
    int semmns;
    int semmnu;
    int semmsl;
    int semopm;
    int semume;
    int semusz;
    int semvmx;
    int semaem;
};

/*@
assigns \result, errno \from semid, semnum, cmd;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int semctl(int semid, int semnum, int cmd, ...);

/*@
assigns \result, errno \from key, nsems, semflg;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int semget(key_t key, int nsems, int semflg);

/*@
requires \valid(sops+(0..nsops-1));
assigns \result, errno \from semid, sops[0..nsops-1], nsops;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int semop(int semid, struct sembuf *sops, size_t nsops);

/* SVID Extensions */

/*@
requires \valid(sops+(0..nsops-1));
requires \valid(timeout);
assigns \result, errno \from semid, sops[0..nsops-1], nsops, *timeout;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int semtimedop (int semid, struct sembuf *sops, size_t nsops, const struct timespec *timeout);

#endif /* LIBC_SYS_SEM_H_ */
