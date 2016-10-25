/*
 * vtimes.h
 *
 *  Created on: Jul 12, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_VTIMES_H_
#define LIBC_SYS_VTIMES_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../errno.h"
#include "time.h"

#define VTIMES_UNITS_PER_SECOND 60

struct vtimes {
    struct timeval vm_utime;
    struct timeval vm_stime;
    long int vm_idsrss;
    long int vm_ixrss;
    long int vm_maxrss;
    long int vm_majflt;
    long int vm_minflt;
    long int vm_nswap;
    long int vm_inblk;
    long int vm_oublk;
};

/*@
requires current != \null ==> \valid(current);
requires child != \null ==> \valid(child);
assigns *current, *child, errno \from \nothing;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int vtimes (struct vtimes *current, struct vtimes *child);

#endif /* LIBC_SYS_VTIMES_H_ */
