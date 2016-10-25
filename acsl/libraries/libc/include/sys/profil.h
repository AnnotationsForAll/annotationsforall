/*
 * profil.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_PROFIL_H_
#define LIBC_SYS_PROFIL_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_size_t.h"
#include "../__fc_define_timeval.h"

#include "../errno.h"

/*
This header is only documented in the HP-UX documentation, but it is included in glibc, probably for compatibility.
It is unknown if the glibc semantics differ from HP-UX's.
*/

#define PROF_USHORT 0
#define PROF_UINT   (1 << 0)
#define PROF_FAST   (1 << 1)

struct prof {
    void *pr_base;
    size_t pr_size;
    size_t pr_off;
    unsigned long int pr_scale;
};

/*@
requires \valid_read(profp+(0..profcnt-1));
requires tvp != \null ==> \valid(tvp);
assigns errno, \result, *tvp;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sprofil(struct prof *profp, int profcnt, struct timeval *tvp, unsigned int flags);

#endif /* LIBC_SYS_PROFIL_H_ */
