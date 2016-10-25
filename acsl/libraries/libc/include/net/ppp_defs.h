/*
 * ppp_defs.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NET_PPP_DEFS_H_
#define LIBC_NET_PPP_DEFS_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_time_t.h"
#include "../__gt_fc_define_alternative_types.h"

/*
TODO: Some of this might be public, kernel-independent interface, and some might be kernel-dependent.
The kernel-dependent bits need to be enumerated, sorted out, and made machdep-specific.
*/

#define PPP_HDRLEN  4
#define PPP_FCSLEN  2
#define PPP_MRU     1500

#define PPP_ADDRESS(p)  (((uint8_t *)(p))[0])
#define PPP_CONTROL(p)  (((uint8_t *)(p))[1])
#define PPP_PROTOCOL(p) ((((uint8_t *)(p))[2] << 8) + ((uint8_t *)(p))[3])

#define PPP_ALLSTATIONS 0xff
#define PPP_UI          0x03
#define PPP_FLAG        0x7e
#define PPP_ESCAPE      0x7d
#define PPP_TRANS       0x20

#define PPP_IP         0x21
#define PPP_AT         0x29
#define PPP_IPX        0x2b
#define PPP_VJC_COMP   0x2d
#define PPP_VJC_UNCOMP 0x2f
#define PPP_MP         0x3d
#define PPP_IPV6       0x57
#define PPP_COMPFRAG   0xfb
#define PPP_COMP       0xfd
#define PPP_MPLS_UC    0x0281
#define PPP_MPLS_MC    0x0283
#define PPP_IPCP       0x8021
#define PPP_ATCP       0x8029
#define PPP_IPXCP      0x802b
#define PPP_IPV6CP     0x8057
#define PPP_CCPFRAG    0x80fb
#define PPP_CCP        0x80fd
#define PPP_MPLSCP     0x80fd
#define PPP_LCP        0xc021
#define PPP_PAP        0xc023
#define PPP_LQR        0xc025
#define PPP_CHAP       0xc223
#define PPP_CBCP       0xc029

#define PPP_INITFCS 0xffff
#define PPP_GOODFCS 0xf0b8

typedef uint32_t ext_accm[8];

enum NPmode {
  NPMODE_PASS,
  NPMODE_DROP,
  NPMODE_ERROR,
  NPMODE_QUEUE
};

struct pppstat {
  uint32_t ppp_discards;
  uint32_t ppp_ibytes;
  uint32_t ppp_ioctects;
  uint32_t ppp_ipackets;
  uint32_t ppp_ierrors;
  uint32_t ppp_ilqrs;
  uint32_t ppp_obytes;
  uint32_t ppp_ooctects;
  uint32_t ppp_opackets;
  uint32_t ppp_oerrors;
  uint32_t ppp_olqrs;
};

struct vjstat {
  uint32_t vjs_packets;
  uint32_t vjs_compressed;
  uint32_t vjs_searches;
  uint32_t vjs_misses;
  uint32_t vjs_uncompressedin;
  uint32_t vjs_compressedin;
  uint32_t vjs_errorin;
  uint32_t vjs_tossed;
};

struct compstat {
  uint32_t unc_bytes;
  uint32_t unc_packets;
  uint32_t comp_bytes;
  uint32_t comp_packets;
  uint32_t inc_bytes;
  uint32_t inc_packets;
  uint32_t in_count;
  uint32_t bytes_out;
  double ratio;
};

struct ppp_stats {
  struct pppstat p;
  struct vjstat vj;
};

struct ppp_comp_stats {
  struct compstat c;
  struct compstat d;
};

struct ppp_idle {
  time_t xmit_idle;
  time_t recv_idle;
};

#endif /* LIBC_NET_PPP_DEFS_H_ */
