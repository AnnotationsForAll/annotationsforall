/*
 * ash.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETASH_ASH_H_
#define LIBC_NETASH_ASH_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_sa_family_t.h"

#define ASH_CHANNEL_ANY      0
#define ASH_CHANNEL_CONTROL  1
#define ASH_CHANNEL_REALTIME 2

struct sockaddr_ash {
    sa_family_t sash_family;
    int sash_ifindex;
    unsigned char sash_channel;
    unsigned int sash_plen;
    unsigned char sash_prefix[16];
};

#endif /* LIBC_NETASH_ASH_H_ */
