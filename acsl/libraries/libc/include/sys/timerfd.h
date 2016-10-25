/*
 * timerfd.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_TIMERFD_H_
#define LIBC_SYS_TIMERFD_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_clock_t.h"
#include "../time.h"

#include "../errno.h"

#define TFD_CLOEXEC  1
#define TFD_NONBLOCK 2

#define TFD_TIMER_ABSTIME (1 << 0)

/*@
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int timerfd_create(clockid_t clock_id, int flags);

/*@
requires \valid_read(utmr);
requires otmr != \null ==> \valid(otmr);
assigns errno, \result, *otmr;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int timerfd_settime(int ufd, int flags, const struct itimerspec *utmr, struct itimerspec *otmr);

/*@
requires \valid(otmr);
assigns errno, \result, *otmr;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int timerfd_gettime(int ufd, struct itimerspec *otmr);

#endif /* LIBC_SYS_TIMERFD_H_ */
