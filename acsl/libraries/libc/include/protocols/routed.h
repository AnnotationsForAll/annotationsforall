/*
 * routed.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_PROTOCOLS_ROUTED_H_
#define LIBC_PROTOCOLS_ROUTED_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_sockaddr.h"

#define RIPVERSION 1

#define RIPCMD_REQUEST  1
#define RIPCMD_RESPONSE 2
#define RIPCMD_TRACEON  3
#define RIPCMD_TRACEOFF 4

#define RIPCMD_MAX 5

#define rip_nets      ripun.ru_nets
#define rip_tracefile ripun.ru_tracefile

#define HOPCNT_INFINITY 16
#define MAXPACKETSIZE   512

#define TIMER_RATE 30

#define SUPPLY_INTERVAL 30
#define MIN_WAITTIME    2
#define MAX_WAITTIME    5

#define EXPIRE_TIME  180
#define GARBAGE_TIME 240

struct netinfo {
    struct sockaddr rip_dst;
    int rip_metric;
};

struct rip {
    u_char rip_cmd;
    u_char rip_vers;
    u_char rip_res1[2];
    union {
        struct netinfo ru_nets[1];
        char ru_tracefile[1];
    } ripun;
};

char *ripcmds[RIPCMD_MAX] = { "#0", "REQUEST", "RESPONSE", "TRACEON", "TRACEOFF" };

#endif /* LIBC_PROTOCOLS_ROUTED_H_ */
