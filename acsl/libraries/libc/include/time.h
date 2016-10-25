/**************************************************************************/
/*                                                                        */
/*  This file is part of Frama-C.                                         */
/*                                                                        */
/*  Copyright (C) 2007-2014                                               */
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

#ifndef __GT__FC_TIME_H
#define __GT__FC_TIME_H
#include "__fc_define_null.h"
#include "__fc_define_size_t.h"
#include "features.h"
#include "__gt_fc_define_locale_t.h"
#include "__fc_define_time_t.h"
#include "__fc_string_axiomatic.h"
#include "__fc_define_pid_t.h"
#include "sys/types.h"
#include "sys/times.h"
#include "sys/timex.h"
#include "signal.h"
#include "errno.h"

/*@
    // Helper predicates
    predicate valid_time_string{L}(char *s) =
        \valid(s)
        && valid_string(s)
        && 25 <= strlen(s) <= 40    // Range for years of char len 4 - 19
        ;
        // Is of the form "Sun Sep 16 01:03:52 1973\n\0"
        // generated from algorithm equivalent to "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n"
        // However the algorithm also seems to imply it cannot be greater than 25 by defining: static char result[26]
        // TODO: values in string from form above
        // XXX: glibc uses a larger buffer, allowing strlen(s) >= 25, and sets errno in the case of int overflow
 */

__BEGIN_DECLS

#define CLOCKS_PER_SEC ((clock_t) 1000000)

struct tm {
    int tm_sec;   // seconds after the minute [0, 60]
    int tm_min;   // minutes after the hour [0, 59]
    int tm_hour;  // hours since midnight [0, 23]
    int tm_mday;  // day of the month [1, 31]
    int tm_mon;   // months since January [0, 11]
    int tm_year;  // years since 1900
    int tm_wday;  // days since Sunday [0, 6]
    int tm_yday;  // days since January 1 [0, 365]
    int tm_isdst; // Daylight Saving Time flag
    /* GNU Exntension Members */
    long tm_gmtoff;
    const char *tm_zone;
};

/*@
    // 7.23.1.4
    predicate valid_tm{L}(struct tm *timeptr) =
            (0 <= timeptr->tm_sec <= 60)
        &&  (0 <= timeptr->tm_min <= 59)
        &&  (0 <= timeptr->tm_hour <= 23)
        &&  (1 <= timeptr->tm_mday <= 31)
        &&  (0 <= timeptr->tm_mon <= 11)
        // timeptr->tm_year unbounded
        &&  (0 <= timeptr->tm_wday <= 6)
        &&  (0 <= timeptr->tm_yday <= 365)
        // timeptr->tm_min unbounded - semantics are for zero, positive, or negative
        ;
 */

#include "__fc_define_timespec.h"

struct itimerspec {
  struct timespec  it_interval;
  struct timespec  it_value;
};

#define CLOCK_REALTIME           0
#define CLOCK_MONOTONIC          1
#define CLOCK_PROCESS_CPUTIME_ID 2
#define CLOCK_THREAD_CPUTIME_ID  3
#define CLOCK_MONOTONIC_RAW      4
#define CLOCK_REALTIME_COARSE    5
#define CLOCK_MONOTONIC_COARSE   6
#define CLOCK_BOOTTIME           7
#define CLOCK_REALTIME_ALARM     8
#define CLOCK_BOOTTIME_ALARM     9
#define CLOCK_TAI                10

#define TIMER_ABSTIME (1 << 0)

//@ ghost volatile unsigned int __fc_time __attribute__((FRAMA_C_MODEL));

/*@ assigns \result \from __fc_time; */
clock_t clock(void);

/*@ assigns \result \from time1, time0; */
double difftime(time_t time1, time_t time0);

/*@ assigns *timeptr, \result \from *timeptr; */
time_t mktime(struct tm *timeptr);

/*@
  assigns *timer, \result \from __fc_time;
  behavior null:
    assumes timer == \null;
    assigns \result \from __fc_time;
  behavior not_null:
    assumes timer != \null;
    requires \valid(timer);
    assigns *timer, \result \from __fc_time;
    ensures \initialized(timer);
    ensures \result == *timer;
  complete behaviors;
  disjoint behaviors;
*/
time_t time(time_t *timer);

// static memory for asctime
// must hold strings formatted by %.3s %.3s%3d %.2d:%.2d:%.2d %d\n
// max length of a 64 bit signed integer is 19
static char __gt_fc_asctime_result[3 + 1 + 3 + 3 + 1 + 2 + 1 + 2 + 1 + 2+ 1 + 19 + 1 + 1];  // = 41

/*@
    requires \valid(timeptr);
    requires valid_tm(timeptr);
    assigns \result, __gt_fc_asctime_result[0..], __FC_errno;
    behavior success:
        assumes int_representable: (int)(timeptr->tm_year + 1900) == (timeptr->tm_year + 1900);
        ensures valid_time_string(\result);
        ensures \result == __gt_fc_asctime_result;
        ensures errno_unchanged: __FC_errno == \old(__FC_errno);
    behavior failure:
        assumes not_int_representable: (int)(timeptr->tm_year + 1900) != (timeptr->tm_year + 1900);
        ensures \result == \null;
        // errno set
    disjoint behaviors success, failure;
    complete behaviors success, failure;
 */
char *asctime(const struct tm *timeptr);

struct tm __fc_time_tm;
struct tm * const  __p_fc_time_tm = &__fc_time_tm;

/*@
    // ctime is equivalent to asctime(localtime(timer)): __fc_time_tm is updated with the result of localtime
    requires \valid(timer);
    assigns \result, __gt_fc_asctime_result[0..], __FC_errno, __fc_time_tm;
    ensures (valid_time_string(\result) && (\result == __gt_fc_asctime_result) && (__FC_errno == \old(__FC_errno)))
        || (\result == \null);
    ensures if_year_representable: (\result == \null) ==>
        ((int)(__fc_time_tm.tm_year + 1900) != (__fc_time_tm.tm_year + 1900));
    ensures if_year_not_representable: (valid_time_string(\result) && (\result == __gt_fc_asctime_result) && (__FC_errno == \old(__FC_errno))) ==>
        ((int)(__fc_time_tm.tm_year + 1900) == (__fc_time_tm.tm_year + 1900));
    // Undefined when localtime returns null
 */
char *ctime(const time_t *timer);

/*@ assigns \result \from __p_fc_time_tm;
  assigns __fc_time_tm \from *timer;
  ensures \result == &__fc_time_tm || \result == \null ;
*/
struct tm *gmtime(const time_t *timer);

/*@ assigns \result \from __p_fc_time_tm;
  assigns __fc_time_tm \from *timer;
  ensures \result == &__fc_time_tm || \result == \null;
*/
struct tm *localtime(const time_t *timer);

/*@
    requires \valid(s+(0 .. maxsize-1));
    assigns s[0 .. maxsize-1];
    ensures (\result == 0) ||
             (\result == strlen(s));
 */
size_t strftime(char * restrict s,
        size_t maxsize,
        const char * restrict format,
        const struct tm * restrict timeptr);

/* POSIX */

char *asctime_r(const struct tm *restrict tm, char *restrict buf);

/*@
requires res != \null ==> \valid(res);
assigns \result, *res, errno \from clock_id;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int clock_getres(clockid_t clock_id, struct timespec *res);

/*@
requires \valid(tp);
assigns \result, *tp, errno \from clock_id;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int clock_gettime(clockid_t clock_id, struct timespec *tp);

/*@
requires \valid(tp);
assigns \result \from *tp, clock_id;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int clock_settime(clockid_t clock_id, const struct timespec *tp);

/*@
requires \valid(rqtp);
requires rmtp != \null ==> \valid(rmtp);
assigns \result, *rmtp, errno \from *rqtp, clock_id, flags;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
ensures \result == 0 ==> (rmtp->tv_sec*1000000000+rmtp->tv_nsec >= rqtp->tv_sec*1000000000+rqtp->tv_nsec);
*/
int clock_nanosleep(clockid_t clock_id, int flags, const struct timespec *rqtp, struct timespec *rmtp);

/*@
requires \valid(string);
assigns \result \from string[..];
ensures \result != \null ==> \valid(\result);
*/
struct tm *getdate(const char *string);

/*@
requires \valid(rqtp);
requires rmtp != \null ==> \valid(rmtp);
assigns \result, *rmtp, errno \from *rqtp;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
ensures \result == 0 ==> (rmtp->tv_sec*1000000000+rmtp->tv_nsec >= rqtp->tv_sec*1000000000+rqtp->tv_nsec);
*/
int nanosleep(const struct timespec *rqtp, struct timespec *rmtp);

/*@
requires \valid(s+(0 .. maxsize-1));
assigns s[0 .. maxsize-1];
ensures (\result == 0) || (\result == strlen(s));
*/
size_t strftime_l(char *restrict s, size_t maxsize, const char *restrict format, const struct tm *restrict timeptr, locale_t locale);

/*@
requires \valid(s);
assigns s[..];
ensures \result != \null ==> \valid(\result);
*/
char *strptime(const char *restrict s, const char *restrict format, struct tm *restrict tm);

/*@
requires \valid(timerid);
requires evp != \null ==> \valid(evp);
assigns \result, *timerid, errno \from clockid, *evp;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int timer_create(clockid_t clockid, struct sigevent *restrict evp, timer_t *restrict timerid);

/*@
assigns \result, errno \from timerid;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int timer_delete(timer_t timerid);

/*@
assigns \result, errno \from timerid;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int timer_getoverrun(timer_t timerid);

/*@
requires \valid(value);
assigns \result, *value, errno \from timerid;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int timer_gettime(timer_t timerid, struct itimerspec *value);

/*@
requires \valid(value);
requires ovalue != \null ==> \valid(ovalue);
assigns \result, *ovalue, errno \from timerid, *value;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int timer_settime(timer_t timerid, int flags, const struct itimerspec *restrict value, struct itimerspec *restrict ovalue);

extern int daylight;
extern long timezone;
extern char *tzname[2];

/*@
assigns tzname[0..1], timezone, daylight \from \nothing;
ensures \valid(tzname+(0..1));
ensures \valid(tzname[0]) && \valid(tzname[1]);
*/
void tzset(void);

// The TIME_* macros and timespec_get are ISO C11, not C99.

#define TIME_UTC 1

/*@
requires \valid(ts);
assigns *ts;
ensures \result == 0 || \result == base;
*/
int timespec_get (struct timespec *ts, int base);

/* GNU Extensions */

// the macro __isleap is public. It is a part of SunOS/Solaris.
#define __isleap(year) ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))

extern int getdate_err;

/*@
requires \valid(newtime);
assigns \result \from *newtime;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int stime (const time_t *newtime);

/*@
assigns *timeptr, \result \from *timeptr;
*/
time_t timegm(struct tm *timeptr);

/*@
assigns *timeptr, \result \from *timeptr;
*/
time_t timelocal(struct tm *timeptr);

/*@
requires \valid_read(timer);
requires \valid(result);
assigns \result, *result \from *timer;
ensures \result != \null ==> \result == result;
*/
struct tm *gmtime_r(const time_t *restrict timer, struct tm *restrict result);

/*@
requires \valid_read(timer);
requires \valid(result);
assigns \result, *result \from *timer;
ensures \result != \null ==> \result == result;
*/
struct tm *localtime_r(const time_t *restrict timer, struct tm *restrict result);

/*@
requires \valid(clock_id);
assigns \result, *clock_id;
ensures \result >= 0;
*/
int clock_getcpuclockid (pid_t pid, clockid_t *clock_id);

/*@
requires \valid_read(timer);
requires \valid(buf+(0..25));
assigns \result, buf[0..25] \from *timer;
ensures \result != \null ==> \result == buf;
ensures \result != \null ==> valid_string(buf);
*/
char *ctime_r (const time_t *restrict timer, char *restrict buf);

/*@
assigns \result \from year;
ensures __isleap(year) ? \result == 366 : \result == 365;
*/
int dysize (int year);

/*@
requires valid_read_string(string);
requires \valid(resbufp);
assigns \result, *resbufp \from string[0..strlen(string)];
ensures 0 <= \result <= 8;
*/
int getdate_r (const char *restrict string, struct tm *restrict resbufp);

/*@
requires \valid(s);
assigns s[..];
ensures \result != \null ==> \valid(\result);
*/
char *strptime_l(const char *restrict s, const char *restrict fmt, struct tm *tp, locale_t  loc);

__END_DECLS

#endif
