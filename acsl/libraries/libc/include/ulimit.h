/*
 * ulimit.h
 *
 *  Created on: Jul 12, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_ULIMIT_H_
#define LIBC_ULIMIT_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "errno.h"

// Possible cmd values.
#define GETFSIZE 1
#define SETFSIZE 2

// glibc's names for the cmd values.
#define UL_GETFSIZE GETFSIZE
#define UL_SETFSIZE SETFSIZE

/*@
requires cmd == GETFSIZE || cmd == SETFSIZE;
assigns errno, \result \from cmd;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
behavior get:
    assumes cmd == GETFSIZE;
    ensures \result >= 0 || \result == -1;
behavior set:
    assumes cmd == SETFSIZE;
    ensures \result == 0 || \result == -1;
complete behaviors; disjoint behaviors;
*/
long int ulimit (int cmd, ...);

#endif /* LIBC_ULIMIT_H_ */
