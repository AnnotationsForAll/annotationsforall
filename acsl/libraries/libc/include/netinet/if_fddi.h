/*
 * if_fddi.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETINET_IF_FDDI_H_
#define LIBC_NETINET_IF_FDDI_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

/*
 TODO: Some of this might be public, kernel-independent interface, and some might be kernel-dependent.
 The kernel-dependent bits need to be enumerated, sorted out, and made machdep-specific.
 */

#define FDDI_K_ALEN      6
#define FDDI_K_8022_HLEN 16
#define FDDI_K_SNAP_HLEN 21
#define FDDI_K_8022_ZLEN 16
#define FDDI_K_SNAP_ZLEN 21
#define FDDI_K_8022_DLEN 4475
#define FDDI_K_SNAP_DLEN 4470
#define FDDI_K_LLC_ZLEN  13
#define FDDI_K_LLC_LEN   4491
#define FDDI_K_OUI_LEN   3

#define FDDI_FC_K_VOID                 0x00
#define FDDI_FC_K_NON_RESTRICTED_TOKEN 0x80
#define FDDI_FC_K_RESTRICTED_TOKEN     0xC0
#define FDDI_FC_K_SMT_MIN              0x41
#define FDDI_FC_K_SMT_MAX              0x4F
#define FDDI_FC_K_MAC_MIN              0xC1
#define FDDI_FC_K_MAC_MAX              0xCF
#define FDDI_FC_K_ASYNC_LLC_MIN        0x50
#define FDDI_FC_K_ASYNC_LLC_DEF        0x54
#define FDDI_FC_K_ASYNC_LLC_MAX        0x5F
#define FDDI_FC_K_SYNC_LLC_MIN         0xD0
#define FDDI_FC_K_SYNC_LLC_MAX         0xD7
#define FDDI_FC_K_IMPLEMENTOR_MIN      0x60
#define FDDI_FC_K_IMPLEMENTOR_MAX      0x6F
#define FDDI_FC_K_RESERVED_MIN         0x70
#define FDDI_FC_K_RESERVED_MAX         0x7F

#define FDDI_EXTENDED_SAP 0xAA
#define FDDI_UI_CMD       0x03

struct fddi_8022_1_hdr {
    u_int8_t dsap;
    u_int8_t ssap;
    u_int8_t ctrl;
};

struct fddi_8022_2_hdr {
    u_int8_t dsap;
    u_int8_t ssap;
    u_int8_t ctrl_1;
    u_int8_t ctrl_2;
};

struct fddi_snap_hdr {
    u_int8_t dsap;
    u_int8_t ssap;
    u_int8_t ctrl;
    u_int8_t oui[FDDI_K_OUI_LEN];
    u_int16_t ethertype;
};

struct fddihdr {
    u_int8_t fc;
    u_int8_t daddr[FDDI_K_ALEN];
    u_int8_t saddr[FDDI_K_ALEN];
    union {
        struct fddi_8022_1_hdr llc_8022_1;
        struct fddi_8022_2_hdr llc_8022_2;
        struct fddi_snap_hdr llc_snap;
    } hdr;
};

struct fddi_header {
    u_int8_t fddi_fc;
    u_int8_t fddi_dhost[FDDI_K_ALEN];
    u_int8_t fddi_shost[FDDI_K_ALEN];
};

#endif /* LIBC_NETINET_IF_FDDI_H_ */
