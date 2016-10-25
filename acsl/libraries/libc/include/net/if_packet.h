/*
 * if_packet.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NET_IF_PACKET_H_
#define LIBC_NET_IF_PACKET_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_sa_family_t.h"

struct sockaddr_pkt {
    sa_family_t spkt_family;
    unsigned char spkt_device[14];
    unsigned short spkt_protocol;
};

#endif /* LIBC_NET_IF_PACKET_H_ */
