/*
 * times.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_TIMES_H_
#define LIBC_SYS_TIMES_H_

#include "../__gt_fc_define_clock_t.h"
#include "../__gt_fc_define_sysconf.h"

struct tms {
    clock_t tms_utime;
    clock_t tms_stime;
    clock_t tms_cutime;
    clock_t tms_cstime;
};

/*@
requires \valid(buffer);
assigns \result, *buffer \from \nothing;
*/
clock_t times(struct tms *buffer);

/* GNU Extensions */

#define CLK_TCK ((clock_t) sysconf(_SC_CLK_TCK))

#endif /* LIBC_SYS_TIMES_H_ */
