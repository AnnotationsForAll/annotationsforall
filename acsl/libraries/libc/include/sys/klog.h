/*
 * klog.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_KLOG_H_
#define LIBC_SYS_KLOG_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.
// Note that this is the glibc interface for the Linux syscall 'syslog'. This is ENTIRELY UNRELATED to the POSIX syslog functionality!

#include "../errno.h"

/*@
behavior read_type:
    assumes (type == 2 || type == 3 || type == 4);
    requires \valid(bufp+(0..len-1));
    assigns \result, errno, bufp[0..len-1];
behavior non_read_type:
    assumes !(type == 2 || type == 3 || type == 4);
    assigns \result, errno;
complete behaviors; disjoint behaviors;
*/
int klogctl(int type, char *bufp, int len);

#endif /* LIBC_SYS_KLOG_H_ */
