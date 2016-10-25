/*
 * if_shaper.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NET_IF_SHAPER_H_
#define LIBC_NET_IF_SHAPER_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../sys/param.h"

#define SHAPER_QLEN 10

#define SHAPER_LATENCY (5 * HZ)
#define SHAPER_MAXSLIP 2
#define SHAPER_BURST   (HZ / 50)

#define SHAPER_SET_DEV   0x0001
#define SHAPER_SET_SPEED 0x0002
#define SHAPER_GET_DEV   0x0003
#define SHAPER_GET_SPEED 0x0004

#define ss_speed ss_u.ssu_speed
#define ss_name  ss_u.ssu_name

struct shaperconf {
    u_int16_t ss_cmd;
    union {
        char ssu_name[14];
        u_int32_t ssu_speed;
    } ss_u;
};

#endif /* LIBC_NET_IF_SHAPER_H_ */
