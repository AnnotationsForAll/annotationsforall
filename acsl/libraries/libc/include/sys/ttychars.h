/*
 * ttychars.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_TTYCHARS_H_
#define LIBC_SYS_TTYCHARS_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "ttydefaults.h"

struct ttychars {
    char tc_erase;
    char tc_kill;
    char tc_intrc;
    char tc_quitc;
    char tc_startc;
    char tc_stopc;
    char tc_eofc;
    char tc_brkc;
    char tc_suspc;
    char tc_dsuspc;
    char tc_rprntc;
    char tc_flushc;
    char tc_werasc;
    char tc_lnextc;
};

#endif /* LIBC_SYS_TTYCHARS_H_ */
