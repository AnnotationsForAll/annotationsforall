/*
 * igmp.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETINET_IGMP_H_
#define LIBC_NETINET_IGMP_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "in.h"

#define IGMP_MINLEN 8

#define IGMP_MEMBERSHIP_QUERY     0x11
#define IGMP_V1_MEMBERSHIP_REPORT 0x12
#define IGMP_V2_MEMBERSHIP_REPORT 0x16
#define IGMP_V2_LEAVE_GROUP       0x17

#define IGMP_DVMRP 0x13
#define IGMP_PIM   0x14
#define IGMP_TRACE 0x15

#define IGMP_MTRACE_RESP 0x1e
#define IGMP_MTRACE      0x1f

#define IGMP_MAX_HOST_REPORT_DELAY 10

#define IGMP_TIMER_SCALE 10

#define IGMP_DELAYING_MEMBER  1
#define IGMP_IDLE_MEMBER      2
#define IGMP_LAZY_MEMBER      3
#define IGMP_SLEEPING_MEMBER  4
#define IGMP_AWAKENING_MEMBER 5

#define IGMP_v1_ROUTER 1
#define IGMP_v2_ROUTER 2

#define IGMP_HOST_MEMBERSHIP_QUERY      IGMP_MEMBERSHIP_QUERY
#define IGMP_HOST_MEMBERSHIP_REPORT     IGMP_V1_MEMBERSHIP_REPORT
#define IGMP_HOST_NEW_MEMBERSHIP_REPORT IGMP_V2_MEMBERSHIP_REPORT
#define IGMP_HOST_LEAVE_MESSAGE         IGMP_V2_LEAVE_GROUP

struct igmp {
    u_int8_t igmp_type;
    u_int8_t igmp_code;
    u_int16_t igmp_cksum;
    struct in_addr igmp_group;
};

#endif /* LIBC_NETINET_IGMP_H_ */
