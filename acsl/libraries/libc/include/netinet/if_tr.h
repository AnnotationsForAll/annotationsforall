/*
 * if_tr.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETINET_IF_TR_H_
#define LIBC_NETINET_IF_TR_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"

#define TR_ALEN   6
#define TR_HLEN   (sizeof (struct trh_hdr) + sizeof (struct trllc))
#define AC        0x10
#define LLC_FRAME 0x40

#define EXTENDED_SAP 0xAA
#define UI_CMD       0x03

#define TR_RII                   0x80
#define TR_RCF_DIR_BIT           0x80
#define TR_RCF_LEN_MASK          0x1f00
#define TR_RCF_BROADCAST         0x8000
#define TR_RCF_LIMITED_BROADCAST 0xC000
#define TR_RCF_FRAME2K           0x20
#define TR_RCF_BROADCAST_MASK    0xC000
#define TR_MAXRIFLEN             18

struct trh_hdr {
    u_int8_t ac;
    u_int8_t fc;
    u_int8_t daddr[TR_ALEN];
    u_int8_t saddr[TR_ALEN];
    u_int16_t rcf;
    u_int16_t rseg[8];
};

struct trllc {
    u_int8_t dsap;
    u_int8_t ssap;
    u_int8_t llc;
    u_int8_t protid[3];
    u_int16_t ethertype;
};

struct tr_statistics {
    unsigned long rx_packets;
    unsigned long tx_packets;
    unsigned long rx_bytes;
    unsigned long tx_bytes;
    unsigned long rx_errors;
    unsigned long tx_errors;
    unsigned long rx_dropped;
    unsigned long tx_dropped;
    unsigned long multicast;
    unsigned long transmit_collision;
    unsigned long line_errors;
    unsigned long internal_errors;
    unsigned long burst_errors;
    unsigned long A_C_errors;
    unsigned long abort_delimiters;
    unsigned long lost_frames;
    unsigned long recv_congest_count;
    unsigned long frame_copied_errors;
    unsigned long frequency_errors;
    unsigned long token_errors;
    unsigned long dummy1;
};

struct trn_hdr {
    u_int8_t trn_ac;
    u_int8_t trn_fc;
    u_int8_t trn_dhost[TR_ALEN];
    u_int8_t trn_shost[TR_ALEN];
    u_int16_t trn_rcf;
    u_int16_t trn_rseg[8];
};

#endif /* LIBC_NETINET_IF_TR_H_ */
