/*
 * rwhod.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_PROTOCOLS_RWHOD_H_
#define LIBC_PROTOCOLS_RWHOD_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../paths.h" // Old versions used to define _PATH_RWHODIR here; it is now in <paths.h>.

#define WHODVERSION 1
#define WHODTYPE_STATUS 1

struct outmp {
    char out_line[8];
    char out_name[8];
    int32_t out_time;
};

struct whod {
    char wd_vers;
    char wd_type;
    char wd_pad[2];
    int wd_sendtime;
    int wd_recvtime;
    char wd_hostname[32];
    int wd_loadav[3];
    int wd_boottime;
    struct whoent {
        struct outmp we_utmp;
        int we_idle;
    } wd_we[1024 / sizeof(struct whoent)];
};

#endif /* LIBC_PROTOCOLS_RWHOD_H_ */
