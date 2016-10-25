/*
 * msg.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_MSG_H_
#define LIBC_SYS_MSG_H_

#include "ipc.h"
#include "../__fc_define_pid_t.h"
#include "../__fc_define_size_t.h"
#include "../__fc_define_ssize_t.h"
#include "../__fc_define_time_t.h"
#include "errno.h"

typedef unsigned short msgqnum_t;
typedef unsigned short msglen_t;

#define MSG_NOERROR (1 << 0)
#define MSG_EXCEPT  (1 << 1)
#define MSG_COPY    (1 << 2)

#define MSG_STAT 11
#define MSG_INFO 12

typedef struct msqid_ds {
    struct ipc_perm msg_perm;
    msgqnum_t msg_qnum;
    msglen_t msg_qbytes;
    pid_t msg_lspid;
    pid_t msg_lrpid;
    time_t msg_stime;
    time_t msg_rtime;
    time_t msg_ctime;
    /* GNU Exntension Members */
    msglen_t msg_cbytes;
} msqid_ds;

struct msginfo {
    int msgpool;
    int msgmap;
    int msgmax;
    int msgmnb;
    int msgmni;
    int msgssz;
    int msgtql;
    unsigned short int msgseg;
};

struct msgbuf {
    long mtype;
    char mtext[1];
};

/*@
requires \valid(buf);
assigns \result, *buf, errno \from msqid, cmd, *buf;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int msgctl(int msqid, int cmd, struct msqid_ds *buf);

/*@
assigns \result, errno \from key, msgflg;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int msgget(key_t key, int msgflg);

/*@
requires \valid(((char*)msgp)+(0..msgsz-1));
assigns \result, ((char*)msgp)[0..msgsz-1], errno \from msqid, msgsz, msgtyp, msgflg;
ensures -1 <= \result <= msgsz;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);

/*@
requires \valid(((char*)msgp)+(0..msgsz-1));
assigns \result, errno \from ((char*)msgp)[0..msgsz-1], msqid, msgsz, msgflg;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);

#endif /* LIBC_SYS_MSG_H_ */
