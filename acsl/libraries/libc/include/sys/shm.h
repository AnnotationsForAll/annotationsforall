/*
 * shm.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_SHM_H_
#define LIBC_SYS_SHM_H_

#include "ipc.h"
#include "../__fc_define_pid_t.h"
#include "../__fc_define_size_t.h"
#include "../__fc_define_time_t.h"
#include "errno.h"

#define SHM_RDONLY 1
#define SHM_RND    2
#define SHM_REMAP  3
#define SHM_EXEC   4

#define SHM_R 1
#define SHM_W 2

#define SHM_LOCK   1
#define SHM_UNLOCK 2

#define SHM_STAT 13
#define SHM_INFO 14

#define SHM_DEST      01000
#define SHM_LOCKED    02000
#define SHM_HUGETLB   04000
#define SHM_NORESERVE 010000

#define SHMLBA 1

typedef unsigned short shmatt_t;

struct shmid_ds {
    struct ipc_perm shm_perm;
    size_t shm_segsz;
    pid_t shm_lpid;
    pid_t shm_cpid;
    shmatt_t shm_nattch;
    time_t shm_atime;
    time_t shm_dtime;
    time_t shm_ctime;
};

struct shminfo {
    unsigned long shmmax;
    unsigned long shmmin;
    unsigned long shmmni;
    unsigned long shmseg;
    unsigned long shmall;
};

struct shm_info {
    int used_ids;
    unsigned long shm_tot;
    unsigned long shm_rss;
    unsigned long shm_swp;
    unsigned long swap_attempts;
    unsigned long swap_successes;
};

/*@
requires (char*)shmaddr != \null ==> \valid((char*)shmaddr);
assigns \result, errno \from shmid, shmaddr, shmflg;
ensures (char*)\result == (char*)-1 ? errno != 0 : errno == \old(errno);
ensures (char*)\result != (char*)-1 ==> \valid((char*)\result);
*/
void *shmat(int shmid, const void *shmaddr, int shmflg);

/*@
requires \valid(buf);
assigns \result, *buf, errno \from shmid, cmd, *buf;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int shmctl(int shmid, int cmd, struct shmid_ds *buf);

/*@
requires \valid((char*)shmaddr);
assigns \result, errno \from \nothing;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int shmdt(const void *shmaddr);

/*@
assigns \result, errno \from key, size, shmflg;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int shmget(key_t key, size_t size, int shmflg);

#endif /* LIBC_SYS_SHM_H_ */
