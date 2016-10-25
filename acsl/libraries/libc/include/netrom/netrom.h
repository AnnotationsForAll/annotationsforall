/*
 * netrom.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETROM_NETROM_H_
#define LIBC_NETROM_NETROM_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../netax25/ax25.h"
#include "../sys/ioctl.h"

#define SOL_NETROM 259

#define NETROM_T1     1
#define NETROM_T2     2
#define NETROM_N2     3
#define NETROM_PACLEN 5
#define NETROM_T4     6
#define NETROM_IDLE   7

#define NETROM_KILL 99

#define NETROM_NEIGH 0
#define NETROM_NODE  1

#define SIOCNRGETPARMS (SIOCPROTOPRIVATE+0)
#define SIOCNRSETPARMS (SIOCPROTOPRIVATE+1)
#define SIOCNRDECOBS   (SIOCPROTOPRIVATE+2)
#define SIOCNRRTCTL    (SIOCPROTOPRIVATE+3)
#define SIOCNRCTLCON   (SIOCPROTOPRIVATE+4)

struct nr_route_struct {
    int type;
    ax25_address callsign;
    char device[16];
    unsigned int quality;
    char mnemonic[7];
    ax25_address neighbour;
    unsigned int obs_count;
    unsigned int ndigis;
    ax25_address digipeaters[AX25_MAX_DIGIS];
};

struct nr_parms_struct {
    unsigned int quality;
    unsigned int obs_count;
    unsigned int ttl;
    unsigned int timeout;
    unsigned int ack_delay;
    unsigned int busy_delay;
    unsigned int tries;
    unsigned int window;
    unsigned int paclen;
};

struct nr_ctl_struct {
    unsigned char index;
    unsigned char id;
    unsigned int cmd;
    unsigned long arg;
};

#endif /* LIBC_NETROM_NETROM_H_ */
