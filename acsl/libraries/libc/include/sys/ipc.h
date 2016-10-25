/*
 * ipc.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_IPC_H_
#define LIBC_SYS_IPC_H_

#include "types.h"
#include "errno.h"

struct ipc_perm {
    uid_t uid;
    gid_t gid;
    uid_t cuid;
    gid_t cgid;
    mode_t mode;
};

#define IPC_CREAT 1
#define IPC_EXCL 2
#define IPC_NOWAIT 4

#define IPC_PRIVATE 0

#define IPC_RMID 1
#define IPC_SET 2
#define IPC_STAT 4

/*@
requires \valid(path);
assigns \result, errno \from path[..], id;
ensures \result == (key_t)-1 ? errno != 0 : errno == \old(errno);
*/
key_t ftok(const char *path, int id);

#endif /* LIBC_SYS_IPC_H_ */
