/*
 * __fc_define_timeval.h
 *
 *  Created on: Jul 12, 2016
 *      Author: jrobbins
 */

#ifndef LIBC___FC_DEFINE_TIMEVAL_H_
#define LIBC___FC_DEFINE_TIMEVAL_H_

#include "__fc_define_time_t.h"
#include "__fc_define_suseconds_t.h"

struct timeval {
  time_t         tv_sec;
  suseconds_t    tv_usec;
};

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

#endif /* LIBC___FC_DEFINE_TIMEVAL_H_ */
