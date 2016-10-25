/*
 * if_ppp.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NET_IF_PPP_H_
#define LIBC_NET_IF_PPP_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../sys/ioctl.h"
#include "if.h"
#include "ppp_defs.h"

#define PPP_MTU      1500
#define PPP_MAXMRU   65000
#define PPP_VERSION  "2.2.0"
#define PPP_MAGIC    0x5002
#define PROTO_IPX    0x002b
#define PROTO_DNA_RT 0x0027

#define SC_COMP_PROT    0x00000001
#define SC_COMP_AC      0x00000002
#define SC_COMP_TCP     0x00000004
#define SC_NO_TCP_CCID  0x00000008
#define SC_REJ_COMP_AC  0x00000010
#define SC_REJ_COMP_TCP 0x00000020
#define SC_CCP_OPEN     0x00000040
#define SC_CCP_UP       0x00000080
#define SC_ENABLE_IP    0x00000100
#define SC_COMP_RUN     0x00001000
#define SC_DECOMP_RUN   0x00002000
#define SC_DEBUG        0x00010000
#define SC_LOG_INPKT    0x00020000
#define SC_LOG_OUTPKT   0x00040000
#define SC_LOG_RAWIN    0x00080000
#define SC_LOG_FLUSH    0x00100000
#define SC_MASK         0x0fE0ffff

#define SC_ESCAPED   0x80000000
#define SC_FLUSH     0x40000000
#define SC_VJ_RESET  0x20000000
#define SC_XMIT_BUSY 0x10000000
#define SC_RCV_ODDP  0x08000000
#define SC_RCV_EVNP  0x04000000
#define SC_RCV_B7_1  0x02000000
#define SC_RCV_B7_0  0x01000000
#define SC_DC_FERROR 0x00800000
#define SC_DC_ERROR  0x00400000

#define ifr__name b.ifr_ifrn.ifrn_name
#define stats_ptr b.ifr_ifru.ifru_data

#define PPPIOCGFLAGS     _IOR('t', 90, int)
#define PPPIOCSFLAGS     _IOW('t', 89, int)
#define PPPIOCGASYNCMAP  _IOR('t', 88, int)
#define PPPIOCSASYNCMAP  _IOW('t', 87, int)
#define PPPIOCGUNIT      _IOR('t', 86, int)
#define PPPIOCGRASYNCMAP _IOR('t', 85, int)
#define PPPIOCSRASYNCMAP _IOW('t', 84, int)
#define PPPIOCGMRU       _IOR('t', 83, int)
#define PPPIOCSMRU       _IOW('t', 82, int)
#define PPPIOCSMAXCID    _IOW('t', 81, int)
#define PPPIOCGXASYNCMAP _IOR('t', 80, ext_accm)
#define PPPIOCSXASYNCMAP _IOW('t', 79, ext_accm)
#define PPPIOCXFERUNIT   _IO('t', 78)
#define PPPIOCSCOMPRESS  _IOW('t', 77, struct ppp_option_data)
#define PPPIOCGNPMODE    _IOWR('t', 76, struct npioctl)
#define PPPIOCSNPMODE    _IOW('t', 75, struct npioctl)
#define PPPIOCGDEBUG     _IOR('t', 65, int)
#define PPPIOCSDEBUG     _IOW('t', 64, int)
#define PPPIOCGIDLE      _IOR('t', 63, struct ppp_idle)

#define SIOCGPPPSTATS  (SIOCDEVPRIVATE + 0)
#define SIOCGPPPVER    (SIOCDEVPRIVATE + 1)
#define SIOCGPPPCSTATS (SIOCDEVPRIVATE + 2)

#define ifr_mtu ifr_ifru.ifru_metric

struct npioctl {
    int protocol;
    enum NPmode mode;
};

struct ppp_option_data {
    u_int8_t *ptr;
    u_int32_t length;
    int transmit;
};

struct ifpppstatsreq {
    struct ifreq b;
    struct ppp_stats stats;
};

struct ifpppcstatsreq {
    struct ifreq b;
    struct ppp_comp_stats stats;
};

#endif /* LIBC_NET_IF_PPP_H_ */
