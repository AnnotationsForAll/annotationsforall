/*
 * timeb.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_TIMEB_H_
#define LIBC_SYS_TIMEB_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_time_t.h"

struct timeb {
    time_t time;
    unsigned short int millitm;
    short int timezone;
    short int dstflag;
};

/*@
requires \valid(timebuf);
assigns \result, *timebuf;
ensures \result == 0;
*/
int ftime(struct timeb *timebuf);

#endif /* LIBC_SYS_TIMEB_H_ */
