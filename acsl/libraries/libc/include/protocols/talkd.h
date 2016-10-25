/*
 * talkd.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_PROTOCOLS_TALKD_H_
#define LIBC_PROTOCOLS_TALKD_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../sys/socket.h"

#define TALK_VERSION 1

#define LEAVE_INVITE 0
#define LOOK_UP      1
#define DELETE       2
#define ANNOUNCE     3

#define SUCCESS           0
#define NOT_HERE          1
#define FAILED            2
#define MACHINE_UNKNOWN   3
#define PERMISSION_DENIED 4
#define UNKNOWN_REQUEST   5
#define BADVERSION        6
#define BADADDR           7
#define BADCTLADDR        8

#define MAX_LIFE  60
#define RING_WAIT 30
#define NAME_SIZE 12
#define TTY_SIZE  16

typedef struct {
    u_char vers;
    u_char type;
    u_char answer;
    u_char pad;
    u_int32_t id_num;
    struct osockaddr addr;
    struct osockaddr ctl_addr;
    int32_t pid;
    char l_name[NAME_SIZE];
    char r_name[NAME_SIZE];
    char r_tty[TTY_SIZE];
} CTL_MSG;

typedef struct {
    u_char vers;
    u_char type;
    u_char answer;
    u_char pad;
    u_int32_t id_num;
    struct osockaddr addr;
} CTL_RESPONSE;

#endif /* LIBC_PROTOCOLS_TALKD_H_ */
