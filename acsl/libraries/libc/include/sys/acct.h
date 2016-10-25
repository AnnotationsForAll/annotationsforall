/*
 * acct.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_ACCT_H_
#define LIBC_SYS_ACCT_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../endian.h"


#include "../__fc_string_axiomatic.h"
#include "errno.h"

#define ACCT_COMM 16

#define AHZ 100

#if BYTE_ORDER == BIG_ENDIAN
# define ACCT_BYTEORDER 0x80
#else
# define ACCT_BYTEORDER 0x00
#endif

#define AFORK (1 << 0)
#define ASU   (1 << 1)
#define ACORE (1 << 2)
#define AXSIG (1 << 3)

typedef u_int16_t comp_t;

struct acct {
    char ac_flag;
    u_int16_t ac_uid;
    u_int16_t ac_gid;
    u_int16_t ac_tty;
    u_int32_t ac_btime;
    comp_t ac_utime;
    comp_t ac_stime;
    comp_t ac_etime;
    comp_t ac_mem;
    comp_t ac_io;
    comp_t ac_rw;
    comp_t ac_minflt;
    comp_t ac_majflt;
    comp_t ac_swaps;
    u_int32_t ac_exitcode;
    char ac_comm[ACCT_COMM + 1];
    char ac_pad[10];
};

struct acct_v3 {
    char ac_flag;
    char ac_version;
    u_int16_t ac_tty;
    u_int32_t ac_exitcode;
    u_int32_t ac_uid;
    u_int32_t ac_gid;
    u_int32_t ac_pid;
    u_int32_t ac_ppid;
    u_int32_t ac_btime;
    float ac_etime;
    comp_t ac_utime;
    comp_t ac_stime;
    comp_t ac_mem;
    comp_t ac_io;
    comp_t ac_rw;
    comp_t ac_minflt;
    comp_t ac_majflt;
    comp_t ac_swaps;
    char ac_comm[ACCT_COMM];
};

/*@
requires valid_read_string_or_null(filename);
assigns \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int acct(const char *filename);

#endif /* LIBC_SYS_ACCT_H_ */
