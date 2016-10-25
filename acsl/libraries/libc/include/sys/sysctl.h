/*
 * sysctl.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_SYSCTL_H_
#define LIBC_SYS_SYSCTL_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_size_t.h"
#include "../errno.h"

// TODO: insert defines for all the various sysctl functions of various kernels.

/*@
requires \valid(names+(0..nlen-1));
requires oldval != \null ==> \valid(((char*)oldval)+(0..((*oldlenp)-1)));
requires oldval != \null ==> \valid(oldlenp);
requires newval != \null ==> \valid(((char*)newval)+(0..newlen-1));
assigns \result, errno, ((char*)oldval)[0..((*oldlenp)-1)], *oldlenp \from names[0..nlen-1], *oldlenp, ((char*)newval)[0..newlen-1], newlen;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sysctl (int *names, int nlen, void *oldval, size_t *oldlenp, void *newval, size_t newlen);

#endif /* LIBC_SYS_SYSCTL_H_ */
