/*
 * timex.h
 *
 *  Created on: Jul 12, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_TIMEX_H_
#define LIBC_SYS_TIMEX_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_timeval.h"
#include "../__gt_fc_define_clock_t.h"
#include "errno.h"

#define TIME_OK     0
#define TIME_INS    1
#define TIME_DEL    2
#define TIME_OOP    3
#define TIME_WAIT   4
#define TIME_ERROR  5
#define TIME_BAD    TIME_ERROR

#define MAXTC 6

#define ADJ_OFFSET            0x0001
#define ADJ_FREQUENCY         0x0002
#define ADJ_MAXERROR          0x0004
#define ADJ_ESTERROR          0x0008
#define ADJ_STATUS            0x0010
#define ADJ_TIMECONST         0x0020
#define ADJ_TAI               0x0080
#define ADJ_SETOFFSET         0x0100
#define ADJ_MICRO             0x1000
#define ADJ_NANO              0x2000
#define ADJ_TICK              0x4000
#define ADJ_OFFSET_SINGLESHOT 0x8001
#define ADJ_OFFSET_SS_READ    0xa001

#define MOD_OFFSET    ADJ_OFFSET
#define MOD_FREQUENCY ADJ_FREQUENCY
#define MOD_MAXERROR  ADJ_MAXERROR
#define MOD_ESTERROR  ADJ_ESTERROR
#define MOD_STATUS    ADJ_STATUS
#define MOD_TIMECONST ADJ_TIMECONST
#define MOD_CLKB      ADJ_TICK
#define MOD_CLKA      ADJ_OFFSET_SINGLESHOT
#define MOD_TAI       ADJ_TAI
#define MOD_MICRO     ADJ_MICRO
#define MOD_NANO      ADJ_NANO

#define STA_PLL     0x0001
#define STA_PPSFREQ 0x0002
#define STA_PPSTIME 0x0004
#define STA_FLL     0x0008

#define STA_INS       0x0010
#define STA_DEL       0x0020
#define STA_UNSYNC    0x0040
#define STA_FREQHOLD  0x0080

#define STA_PPSSIGNAL 0x0100
#define STA_PPSJITTER 0x0200
#define STA_PPSWANDER 0x0400
#define STA_PPSERROR  0x0800

#define STA_CLOCKERR 0x1000
#define STA_NANO     0x2000
#define STA_MODE     0x4000
#define STA_CLK      0x8000

#define STA_RONLY (STA_PPSSIGNAL | STA_PPSJITTER | STA_PPSWANDER | STA_PPSERROR | STA_CLOCKERR | STA_NANO | STA_MODE | STA_CLK)

struct ntptimeval {
    struct timeval time;
    long int maxerror;
    long int esterror;
};

struct timex {
    unsigned int modes;
    long int offset;
    long int frequency;
    long int maxerror;
    long int esterror;
    int status;
    long int constant;
    long int precision;
    long int tolerance;
    struct timeval time;
    long int tick;
    long int ppsfreq;
    long int jitter;
    int shift;
    long int stabil;
    long int jitcnt;
    long int calcnt;
    long int errcnt;
    long int stbcnt;
};

/*@
requires \valid(tptr);
assigns errno, *tptr;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int adjtimex (struct timex *tptr);

/*@
requires \valid(tptr);
assigns errno, *tptr;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int ntp_gettime (struct ntptimeval *tptr);

/*@
requires \valid(tptr);
assigns errno, *tptr;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int ntp_adjtime (struct timex *tptr);

// This following function is undocumented, but some programs use it.
int clock_adjtime(clockid_t clock_id, struct timex *utx);

#endif /* LIBC_SYS_TIMEX_H_ */
