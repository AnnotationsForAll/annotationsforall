/**************************************************************************/
/*                                                                        */
/*  This file is part of Frama-C.                                         */
/*                                                                        */
/*  Copyright (C) 2007-2015                                               */
/*    CEA (Commissariat à l'énergie atomique et aux énergies              */
/*         alternatives)                                                  */
/*                                                                        */
/*  you can redistribute it and/or modify it under the terms of the GNU   */
/*  Lesser General Public License as published by the Free Software       */
/*  Foundation, version 2.1.                                              */
/*                                                                        */
/*  It is distributed in the hope that it will be useful,                 */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/*  GNU Lesser General Public License for more details.                   */
/*                                                                        */
/*  See the GNU Lesser General Public License version 2.1                 */
/*  for more details (enclosed in the file licenses/LGPLv2.1).            */
/*                                                                        */
/**************************************************************************/

#ifndef __FC_SYS_TIME_H__
#define __FC_SYS_TIME_H__

#include "../__fc_define_fd_set_t.h"
#include "../__fc_define_timespec.h"
#include "../__fc_define_timeval.h"
#include "../errno.h"
#include "timex.h"

/* Abstract representation of the current time. */
 //@ ghost volatile unsigned int __fc_time __attribute__((FRAMA_C_MODEL));
 //@ ghost extern int __fc_tz __attribute__((FRAMA_C_MODEL));

/*@
requires \valid(times+(0..1));
requires \valid(path);
assigns \result, errno \from path[..], times[0..1];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int utimes(const char *path, const struct timeval * times);

/*@ behavior tv_and_tz_null:
  @   assumes tv == \null && tz == \null;
  @   assigns \nothing;
  @
  @ behavior tv_not_null:
  @   assumes tv != \null && tz == \null;
  @   assigns tv->tv_sec \from __fc_time;
  @   assigns tv->tv_usec \from __fc_time;
  @   ensures \initialized(&tv->tv_sec) && \initialized(&tv->tv_usec);
  @
  @ behavior tz_not_null:
  @   assumes tv == \null && tz != \null;
  @   assigns *tz \from __fc_tz;
  @   ensures \initialized(tz);
  @
  @ behavior tv_and_tz_not_null:
  @   assumes tv != \null && tz != \null;
  @   assigns tv->tv_sec \from __fc_time;
  @   assigns tv->tv_usec \from __fc_time;
  @   assigns *tz \from __fc_tz;
  @   ensures \initialized(&tv->tv_sec) && \initialized(&tv->tv_usec);
  @   ensures \initialized(&tz);
  @
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
int gettimeofday(struct timeval *tv, struct timezone *tz);

/*@ assigns \result,__fc_time,__fc_tz 
  @            \from      tv->tv_sec, tv->tv_usec,
  @                       tz->tz_dsttime, tz->tz_minuteswest; 
  @*/
int settimeofday(const struct timeval *tv, const struct timezone *tz);

/* BSD Extensions */

#define timerclear(tvp)     ((tvp)->tv_sec = (tvp)->tv_usec = 0)
#define timerisset(tvp)     ((tvp)->tv_sec || (tvp)->tv_usec)
#define timercmp(tvp, uvp, cmp)                                   \
    (((tvp)->tv_sec == (uvp)->tv_sec) ?                           \
        ((tvp)->tv_usec cmp (uvp)->tv_usec) :                     \
        ((tvp)->tv_sec cmp (uvp)->tv_sec))
#define timeradd(tvp, uvp, vvp)                                   \
    do {                                                          \
        (vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;            \
        (vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec;         \
        if ((vvp)->tv_usec >= 1000000) {                          \
            (vvp)->tv_sec++;                                      \
            (vvp)->tv_usec -= 1000000;                            \
        }                                                         \
    } while (0)
#define timersub(tvp, uvp, vvp)                                   \
    do {                                                          \
        (vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;            \
        (vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;         \
        if ((vvp)->tv_usec < 0) {                                 \
            (vvp)->tv_sec--;                                      \
            (vvp)->tv_usec += 1000000;                            \
        }                                                         \
    } while (0)

# define TIMEVAL_TO_TIMESPEC(tv, ts) {                                   \
    (ts)->tv_sec = (tv)->tv_sec;                                    \
    (ts)->tv_nsec = (tv)->tv_usec * 1000;                           \
}
# define TIMESPEC_TO_TIMEVAL(tv, ts) {                                   \
    (tv)->tv_sec = (ts)->tv_sec;                                    \
    (tv)->tv_usec = (ts)->tv_nsec / 1000;                           \
}

struct itimerval {
    struct timeval it_interval;
    struct timeval it_value;
};

/*@
requires \valid(times+(0..1));
requires \valid(path);
assigns \result, errno \from path[..], times[0..1];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int lutimes(const char *path, const struct timeval * times);

/*@
requires \valid(delta);
requires olddelta != \null ==> \valid(olddelta);
assigns \result, *olddelta, errno \from *delta;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int adjtime (const struct timeval *delta, struct timeval *olddelta);

/*@
requires which == ITIMER_REAL || which == ITIMER_VIRTUAL || which == ITIMER_PROF;
requires \valid(new);
requires old != \null ==> \valid(old);
assigns \result, errno, *old \from *new, which;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setitimer (int which, const struct itimerval *new, struct itimerval *old);

/*@
requires which == ITIMER_REAL || which == ITIMER_VIRTUAL || which == ITIMER_PROF;
requires \valid(old);
assigns \result, errno, *old \from which;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int getitimer (int which, struct itimerval *old);

/*@
requires \valid(times+(0..1));
assigns \result, errno \from fd, times[0..1];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int futimes (int fd, const struct timeval times[2]);

/*@
requires \valid(times+(0..1));
requires \valid(path);
assigns \result, errno \from path[..], times[0..1];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int futimesat (int fd, const char *path, const struct timeval times[2]);

#endif
