/*
 * if_ether.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETINET_IF_ETHER_H_
#define LIBC_NETINET_IF_ETHER_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../net/ethernet.h"
#include "../net/if_arp.h"

#define arp_hrd ea_hdr.ar_hrd
#define arp_pro ea_hdr.ar_pro
#define arp_hln ea_hdr.ar_hln
#define arp_pln ea_hdr.ar_pln
#define arp_op  ea_hdr.ar_op

#define ETHER_MAP_IP_MULTICAST(ipaddr, enaddr) \
{ \
    (enaddr)[0] = 0x01; \
    (enaddr)[1] = 0x00; \
    (enaddr)[2] = 0x5e; \
    (enaddr)[3] = ((u_int8_t *)ipaddr)[1] & 0x7f; \
    (enaddr)[4] = ((u_int8_t *)ipaddr)[2]; \
    (enaddr)[5] = ((u_int8_t *)ipaddr)[3]; \
}

struct ether_arp {
    struct arphdr ea_hdr;
    u_int8_t arp_sha[ETH_ALEN];
    u_int8_t arp_spa[4];
    u_int8_t arp_tha[ETH_ALEN];
    u_int8_t arp_tpa[4];
};

#endif /* LIBC_NETINET_IF_ETHER_H_ */
