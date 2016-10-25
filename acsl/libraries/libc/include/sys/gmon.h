/*
 * gmon.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_GMON_H_
#define LIBC_SYS_GMON_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"

#define HISTFRACTION 2
#define HASHFRACTION 2
#define ARCDENSITY   3
#define MINARCS      50
#define MAXARCS      (1 << 20)

#define GMON_PROF_ON    0
#define GMON_PROF_BUSY  1
#define GMON_PROF_ERROR 2
#define GMON_PROF_OFF   3

#define GPROF_STATE     0
#define GPROF_COUNT     1
#define GPROF_FROMS     2
#define GPROF_TOS       3
#define GPROF_GMONPARAM 4

#define ROUNDDOWN(x,y)  (((x)/(y))*(y))
#define ROUNDUP(x,y)    ((((x)+(y)-1)/(y))*(y))

typedef unsigned short HISTCOUNTER;
typedef u_long ARCINDEX;

struct tostruct {
    u_long selfpc;
    long count;
    ARCINDEX link;
};

struct rawarc {
    u_long raw_frompc;
    u_long raw_selfpc;
    long raw_count;
};

struct gmonparam {
    long int state;
    u_short *kcount;
    u_long kcountsize;
    ARCINDEX *froms;
    u_long fromssize;
    struct tostruct *tos;
    u_long tossize;
    long tolimit;
    u_long lowpc;
    u_long highpc;
    u_long textsize;
    u_long hashfraction;
    long log_hashfraction;
};

/*@
assigns \nothing;
*/
void moncontrol(int mode);

/*@
assigns \nothing;
*/
void monstartup(u_long lowpc, u_long highpc);

#endif /* LIBC_SYS_GMON_H_ */
