/*
 * iucv.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETIUCV_IUCV_H_
#define LIBC_NETIUCV_IUCV_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_sa_family_t.h"

struct sockaddr_iucv {
    sa_family_t siucv_family;
    unsigned short siucv_port;
    unsigned int siucv_addr;
    char siucv_nodeid[8];
    char siucv_user_id[8];
    char siucv_name[8];
};

#endif /* LIBC_NETIUCV_IUCV_H_ */
