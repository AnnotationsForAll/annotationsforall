/*
 * eventfd.h
 *
 *  Created on: Jul 14, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_EVENTFD_H_
#define LIBC_SYS_EVENTFD_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"

#include "../errno.h"

#define EFD_CLOEXEC   (1 << 0)
#define EFD_NONBLOCK  (1 << 1)
#define EFD_SEMAPHORE (1 << 2)

typedef uint64_t eventfd_t;

/*@
assigns errno, \result;
ensures \result >= 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int eventfd(unsigned int initval, int flags);

/*@
requires \valid(value);
assigns errno, \result, *value;
ensures \result == -1 || \result == 0;
ensures \result == -1 ==> *value == \old(*value);
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int eventfd_read(int fd, eventfd_t *value);

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int eventfd_write(int fd, eventfd_t value);

#endif /* LIBC_SYS_EVENTFD_H_ */
