/*
 * timed.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_PROTOCOLS_TIMED_H_
#define LIBC_PROTOCOLS_TIMED_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_timeval.h"

#define TSPVERSION     1
#define ANYADDR        NULL
#define MAXHOSTNAMELEN 64

#define tsp_time   tsp_u.tspu_time
#define tsp_hopcnt tsp_u.tspu_hopcnt

#define TSP_ANY        0
#define TSP_ADJTIME    1
#define TSP_ACK        2
#define TSP_MASTERREQ  3
#define TSP_MASTERACK  4
#define TSP_SETTIME    5
#define TSP_MASTERUP   6
#define TSP_SLAVEUP    7
#define TSP_ELECTION   8
#define TSP_ACCEPT     9
#define TSP_REFUSE     10
#define TSP_CONFLICT   11
#define TSP_RESOLVE    12
#define TSP_QUIT       13
#define TSP_DATE       14
#define TSP_DATEREQ    15
#define TSP_DATEACK    16
#define TSP_TRACEON    17
#define TSP_TRACEOFF   18
#define TSP_MSITE      19
#define TSP_MSITEREQ   20
#define TSP_TEST       21
#define TSP_SETDATE    22
#define TSP_SETDATEREQ 23
#define TSP_LOOP       24
#define TSPTYPENUMBER  25

struct tsp {
    u_char tsp_type;
    u_char tsp_vers;
    u_short tsp_seq;
    union {
        struct timeval tspu_time;
        char tspu_hopcnt;
    } tsp_u;
    char tsp_name[MAXHOSTNAMELEN];
};

char *tsptype[TSPTYPENUMBER] = { "ANY", "ADJTIME", "ACK", "MASTERREQ", "MASTERACK", "SETTIME", "MASTERUP", "SLAVEUP", "ELECTION", "ACCEPT", "REFUSE", "CONFLICT", "RESOLVE", "QUIT", "DATE", "DATEREQ", "DATEACK", "TRACEON", "TRACEOFF", "MSITE", "MSITEREQ", "TEST", "SETDATE", "SETDATEREQ", "LOOP" };

#endif /* LIBC_PROTOCOLS_TIMED_H_ */
