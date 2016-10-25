/*
 * capability.h
 *
 *  Created on: Jul 14, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_CAPABILITY_H_
#define LIBC_SYS_CAPABILITY_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

/*
The contents of this header are unclear. two libcs, klibc and Bionic, have this header, but not glibc.
There is also a library, libcap, which adds this header, but includes different functions.
They parallel Linux system calls, but it is unknown what form of wrapping is done around the system call.
*/

#include "../__gt_fc_define_alternative_types.h"

#define _LINUX_CAPABILITY_VERSION_1  0x19980330
#define _LINUX_CAPABILITY_U32S_1     1
#define _LINUX_CAPABILITY_VERSION_2  0x20071026
#define _LINUX_CAPABILITY_U32S_2     2
#define _LINUX_CAPABILITY_VERSION_3  0x20080522
#define _LINUX_CAPABILITY_U32S_3     2

typedef struct __user_cap_header_struct {
    uint32_t version;
    int pid;
}*cap_user_header_t;

typedef struct __user_cap_data_struct {
    uint32_t effective;
    uint32_t permitted;
    uint32_t inheritable;
}*cap_user_data_t;

int capget(cap_user_header_t hdrp, cap_user_data_t datap);
int capset(cap_user_header_t hdrp, const cap_user_data_t datap);

#endif /* LIBC_SYS_CAPABILITY_H_ */
