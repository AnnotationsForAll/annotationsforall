/*
 * ec.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETECONET_EC_H_
#define LIBC_NETECONET_EC_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_sa_family_t.h"

#define ECTYPE_PACKET_RECEIVED 0
#define ECTYPE_TRANSMIT_STATUS 0x10

#define ECTYPE_TRANSMIT_OK            1
#define ECTYPE_TRANSMIT_NOT_LISTENING 2
#define ECTYPE_TRANSMIT_NET_ERROR     3
#define ECTYPE_TRANSMIT_NO_CLOCK      4
#define ECTYPE_TRANSMIT_LINE_JAMMED   5
#define ECTYPE_TRANSMIT_NOT_PRESENT   6

struct ec_addr {
    unsigned char station;
    unsigned char net;
};

struct sockaddr_ec {
    sa_family_t sec_family;
    unsigned char port;
    unsigned char cb;
    unsigned char type;
    struct ec_addr addr;
    unsigned long cookie;
};

#endif /* LIBC_NETECONET_EC_H_ */
