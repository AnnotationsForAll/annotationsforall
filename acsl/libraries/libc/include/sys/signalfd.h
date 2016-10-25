/*
 * signalfd.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_SIGNALFD_H_
#define LIBC_SYS_SIGNALFD_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_sigset_t.h"

#include "../errno.h"

#define SFD_NONBLOCK (1 << 0)
#define SFD_CLOEXEC  (1 << 1)

struct signalfd_siginfo {
    uint32_t ssi_signo;
    int32_t ssi_errno;
    int32_t ssi_code;
    uint32_t ssi_pid;
    uint32_t ssi_uid;
    int32_t ssi_fd;
    uint32_t ssi_tid;
    uint32_t ssi_band;
    uint32_t ssi_overrun;
    uint32_t ssi_trapno;
    int32_t ssi_status;
    int32_t ssi_int;
    uint64_t ssi_ptr;
    uint64_t ssi_utime;
    uint64_t ssi_stime;
    uint64_t ssi_addr;
    uint8_t pad[48];
};

/*@
requires \valid_read(mask);
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int signalfd(int fd, const sigset_t *mask, int flags);

#endif /* LIBC_SYS_SIGNALFD_H_ */
