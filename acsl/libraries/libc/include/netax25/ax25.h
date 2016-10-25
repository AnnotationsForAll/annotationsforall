/*
 * ax25.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETAX25_AX25_H_
#define LIBC_NETAX25_AX25_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_sa_family_t.h"
#include "../sys/ioctl.h"

#define SOL_AX25    257

#define AX25_WINDOW     1
#define AX25_T1         2
#define AX25_T2         5
#define AX25_T3         4
#define AX25_N2         3
#define AX25_BACKOFF    6
#define AX25_EXTSEQ     7
#define AX25_PIDINCL    8
#define AX25_IDLE       9
#define AX25_PACLEN     10
#define AX25_IPMAXQUEUE 11
#define AX25_IAMDIGI    12
#define AX25_KILL       99

#define SIOCAX25GETUID   (SIOCPROTOPRIVATE)
#define SIOCAX25ADDUID   (SIOCPROTOPRIVATE+1)
#define SIOCAX25DELUID   (SIOCPROTOPRIVATE+2)
#define SIOCAX25NOUID    (SIOCPROTOPRIVATE+3)
#define SIOCAX25BPQADDR  (SIOCPROTOPRIVATE+4)
#define SIOCAX25GETPARMS (SIOCPROTOPRIVATE+5)
#define SIOCAX25SETPARMS (SIOCPROTOPRIVATE+6)
#define SIOCAX25OPTRT    (SIOCPROTOPRIVATE+7)
#define SIOCAX25CTLCON   (SIOCPROTOPRIVATE+8)
#define SIOCAX25GETINFO  (SIOCPROTOPRIVATE+9)
#define SIOCAX25ADDFWD   (SIOCPROTOPRIVATE+10)
#define SIOCAX25DELFWD   (SIOCPROTOPRIVATE+11)

#define AX25_NOUID_DEFAULT 0
#define AX25_NOUID_BLOCK   1
#define AX25_SET_RT_IPMODE 2

#define AX25_DIGI_INBAND 0x01
#define AX25_DIGI_XBAND  0x02

#define AX25_MAX_DIGIS 8

#define AX25_VALUES_IPDEFMODE  0
#define AX25_VALUES_AXDEFMODE  1
#define AX25_VALUES_NETROM     2
#define AX25_VALUES_TEXT       3
#define AX25_VALUES_BACKOFF    4
#define AX25_VALUES_CONMODE    5
#define AX25_VALUES_WINDOW     6
#define AX25_VALUES_EWINDOW    7
#define AX25_VALUES_T1         8
#define AX25_VALUES_T2         9
#define AX25_VALUES_T3         10
#define AX25_VALUES_N2         11
#define AX25_VALUES_DIGI       12
#define AX25_VALUES_IDLE       13
#define AX25_VALUES_PACLEN     14
#define AX25_VALUES_IPMAXQUEUE 15
#define AX25_MAX_VALUES        20

#define sax25_uid sax25_ndigis

typedef struct {
    char ax25_call[7];
} ax25_address;

struct sockaddr_ax25 {
    sa_family_t sax25_family;
    ax25_address sax25_call;
    int sax25_ndigis;
};

struct full_sockaddr_ax25 {
    struct sockaddr_ax25 fsa_ax25;
    ax25_address fsa_digipeater[AX25_MAX_DIGIS];
};

struct ax25_routes_struct {
    ax25_address port_addr;
    ax25_address dest_addr;
    unsigned char digi_count;
    ax25_address digi_addr[AX25_MAX_DIGIS];
};

struct ax25_ctl_struct {
    ax25_address port_addr;
    ax25_address source_addr;
    ax25_address dest_addr;
    unsigned int cmd;
    unsigned long arg;
    unsigned char digi_count;
    ax25_address digi_addr[AX25_MAX_DIGIS];
};

struct ax25_info_struct {
    unsigned int n2, n2count;
    unsigned int t1, t1timer;
    unsigned int t2, t2timer;
    unsigned int t3, t3timer;
    unsigned int idle, idletimer;
    unsigned int state;
    unsigned int rcv_q, snd_q;
};

struct ax25_fwd_struct {
    ax25_address port_from;
    ax25_address port_to;
};

struct ax25_route_opt_struct {
    ax25_address port_addr;
    ax25_address dest_addr;
    int cmd;
    int arg;
};

struct ax25_bpqaddr_struct {
    char dev[16];
    ax25_address addr;
};

struct ax25_parms_struct {
    ax25_address port_addr;
    unsigned short values[AX25_MAX_VALUES];
};

#endif /* LIBC_NETAX25_AX25_H_ */
