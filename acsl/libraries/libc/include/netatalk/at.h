/*
 * at.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETATALK_AT_H_
#define LIBC_NETATALK_AT_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_sa_family_t.h"
#include "../sys/ioctl.h"

/*
TODO: Some of this might be public, kernel-independent interface, and some might be kernel-dependent.
The kernel-dependent bits need to be enumerated, sorted out, and made machdep-specific.
*/

#define ATPORT_FIRST    1
#define ATPORT_RESERVED 128
#define ATPORT_LAST     254
#define ATADDR_ANYNET   ((uint16_t)0)
#define ATADDR_ANYNODE  ((uint8_t)0)
#define ATADDR_ANYPORT  ((uint8_t)0)
#define ATADDR_BCAST    ((uint8_t)255)
#define DDP_MAXSZ       587
#define DDP_MAXHOPS     15

#define SIOCATALKDIFADDR (SIOCPROTOPRIVATE + 0)

struct atalk_addr {
    uint16_t s_net;
    uint8_t s_node;
};

struct sockaddr_at {
    sa_family_t sat_family;
    uint8_t sat_port;
    struct atalk_addr sat_addr;
    char sat_zero[8];
};

struct atalk_netrange {
    uint8_t nr_phase;
    uint16_t nr_firstnet;
    uint16_t nr_lastnet;
};

#define SOL_ATALK 258

#endif /* LIBC_NETATALK_AT_H_ */
