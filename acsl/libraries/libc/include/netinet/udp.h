/*
 * udp.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETINET_UDP_H_
#define LIBC_NETINET_UDP_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"

#define UDP_CORK         1
#define UDP_ENCAP        100
#define UDP_NO_CHECK6_TX 101
#define UDP_NO_CHECK6_RX 102

#define UDP_ENCAP_ESPINUDP_NON_IKE 1
#define UDP_ENCAP_ESPINUDP         2
#define UDP_ENCAP_L2TPINUDP        3

#define SOL_UDP 17

struct udphdr {
    union {
        struct {
            u_int16_t uh_sport;
            u_int16_t uh_dport;
            u_int16_t uh_ulen;
            u_int16_t uh_sum;
        };
        struct {
            u_int16_t source;
            u_int16_t dest;
            u_int16_t len;
            u_int16_t check;
        };
    };
};

#endif /* LIBC_NETINET_UDP_H_ */
