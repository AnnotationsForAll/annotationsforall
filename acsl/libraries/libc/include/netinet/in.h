/**************************************************************************/
/*                                                                        */
/*  This file is part of Frama-C.                                         */
/*                                                                        */
/*  Copyright (C) 2007-2015                                               */
/*    CEA (Commissariat à l'énergie atomique et aux énergies              */
/*         alternatives)                                                  */
/*                                                                        */
/*  you can redistribute it and/or modify it under the terms of the GNU   */
/*  Lesser General Public License as published by the Free Software       */
/*  Foundation, version 2.1.                                              */
/*                                                                        */
/*  It is distributed in the hope that it will be useful,                 */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/*  GNU Lesser General Public License for more details.                   */
/*                                                                        */
/*  See the GNU Lesser General Public License version 2.1                 */
/*  for more details (enclosed in the file licenses/LGPLv2.1).            */
/*                                                                        */
/**************************************************************************/

#ifndef __FC_NETINET_IN_H__
#define __FC_NETINET_IN_H__

#include "../__gt_fc_define_alternative_types.h"
#include "../sys/socket.h"
#include "errno.h"

#define INADDR_ANY       0
#define INADDR_BROADCAST 0XFFFFFFFFUL

#define IN6ADDR_ANY       0
#define IN6ADDR_BROADCAST 0XFFFFFFFFFFFFFFFFULL

#define INET_ADDRSTRLEN  16
#define INET6_ADDRSTRLEN 46

#define INADDR_UNSPEC_GROUP    ((in_addr_t) 0xe0000000)
#define INADDR_ALLHOSTS_GROUP  ((in_addr_t) 0xe0000001)
#define INADDR_ALLRTRS_GROUP   ((in_addr_t) 0xe0000002)
#define INADDR_MAX_LOCAL_GROUP ((in_addr_t) 0xe00000ff)

#define IPPROTO_IP       0
#define IPPROTO_HOPOPTS  1
#define IPPROTO_ICMP     2
#define IPPROTO_IGMP     3
#define IPPROTO_IPIP     4
#define IPPROTO_TCP      5
#define IPPROTO_EGP      6
#define IPPROTO_PUP      7
#define IPPROTO_UDP      8
#define IPPROTO_IDP      9
#define IPPROTO_TP       10
#define IPPROTO_DCCP     11
#define IPPROTO_IPV6     12
#define IPPROTO_ROUTING  13
#define IPPROTO_FRAGMENT 14
#define IPPROTO_RSVP     15
#define IPPROTO_GRE      16
#define IPPROTO_ESP      17
#define IPPROTO_AH       18
#define IPPROTO_ICMPV6   19
#define IPPROTO_NONE     20
#define IPPROTO_DSTOPTS  21
#define IPPROTO_MTP      22
#define IPPROTO_ENCAP    23
#define IPPROTO_PIM      24
#define IPPROTO_COMP     25
#define IPPROTO_SCTP     26
#define IPPROTO_UDPLITE  27
#define IPPROTO_RAW      28
#define IPPROTO_MAX      29

#define        IP_TOS      1
#define        IP_TTL      2
#define        IP_HDRINCL  3
#define        IP_OPTIONS  4
#define        IP_RECVOPTS 5

#define IP_RETOPTS                7
#define IP_MULTICAST_IF           32
#define IP_MULTICAST_TTL          33
#define IP_MULTICAST_LOOP         34
#define IP_ADD_MEMBERSHIP         35
#define IP_DROP_MEMBERSHIP        36
#define IP_UNBLOCK_SOURCE         37
#define IP_BLOCK_SOURCE           38
#define IP_ADD_SOURCE_MEMBERSHIP  39
#define IP_DROP_SOURCE_MEMBERSHIP 40
#define IP_MSFILTER               41
#define IP_RECVRETOPTS            IP_RETOPTS

#define IP_ROUTER_ALERT 5
#define IP_PKTINFO      8
#define IP_PKTOPTIONS   9
#define IP_PMTUDISC     10
#define IP_MTU_DISCOVER 10
#define IP_RECVERR      11
#define IP_RECVTTL      12
#define IP_RECVTOS      13
#define IP_MTU          14
#define IP_FREEBIND     15
#define IP_IPSEC_POLICY 16
#define IP_XFRM_POLICY  17
#define IP_PASSSEC      18
#define IP_TRANSPARENT  19

#define IP_ORIGDSTADDR     20
#define IP_RECVORIGDSTADDR IP_ORIGDSTADDR

#define IP_MINTTL       21

#define IP_PMTUDISC_DONT  0
#define IP_PMTUDISC_WANT  1
#define IP_PMTUDISC_DO    2
#define IP_PMTUDISC_PROBE 3

#define SOL_IP 0

#define IP_DEFAULT_MULTICAST_TTL  1
#define IP_DEFAULT_MULTICAST_LOOP 1
#define IP_MAX_MEMBERSHIPS        20

#define IPV6_ADDRFORM       1
#define IPV6_2292PKTINFO    2
#define IPV6_2292HOPOPTS    3
#define IPV6_2292DSTOPTS    4
#define IPV6_2292RTHDR      5
#define IPV6_2292PKTOPTIONS 6
#define IPV6_CHECKSUM       7
#define IPV6_2292HOPLIMIT   8

#define SCM_SRCRT IPV6_RXSRCRT

#define IPV6_NEXTHOP        9
#define IPV6_AUTHHDR        10
#define IPV6_UNICAST_HOPS   16
#define IPV6_MULTICAST_IF   17
#define IPV6_MULTICAST_HOPS 18
#define IPV6_MULTICAST_LOOP 19
#define IPV6_JOIN_GROUP     20
#define IPV6_LEAVE_GROUP    21
#define IPV6_ROUTER_ALERT   22
#define IPV6_MTU_DISCOVER   23
#define IPV6_MTU            24
#define IPV6_RECVERR        25
#define IPV6_V6ONLY         26
#define IPV6_JOIN_ANYCAST   27
#define IPV6_LEAVE_ANYCAST  28
#define IPV6_IPSEC_POLICY   34
#define IPV6_XFRM_POLICY    35

#define IPV6_RECVPKTINFO    49
#define IPV6_PKTINFO        50
#define IPV6_RECVHOPLIMIT   51
#define IPV6_HOPLIMIT       52
#define IPV6_RECVHOPOPTS    53
#define IPV6_HOPOPTS        54
#define IPV6_RTHDRDSTOPTS   55
#define IPV6_RECVRTHDR      56
#define IPV6_RTHDR          57
#define IPV6_RECVDSTOPTS    58
#define IPV6_DSTOPTS        59

#define IPV6_RECVTCLASS 66
#define IPV6_TCLASS     67

#define IPV6_ADD_MEMBERSHIP  IPV6_JOIN_GROUP
#define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP
#define IPV6_RXHOPOPTS       IPV6_HOPOPTS
#define IPV6_RXDSTOPTS       IPV6_DSTOPTS

#define IPV6_PMTUDISC_DONT  0
#define IPV6_PMTUDISC_WANT  1
#define IPV6_PMTUDISC_DO    2
#define IPV6_PMTUDISC_PROBE 3

#define SOL_IPV6   41
#define SOL_ICMPV6 58

#define IPV6_RTHDR_LOOSE  0
#define IPV6_RTHDR_STRICT 1

#define IPV6_RTHDR_TYPE_0 0

#define MCAST_JOIN_GROUP         42
#define MCAST_BLOCK_SOURCE       43
#define MCAST_UNBLOCK_SOURCE     44
#define MCAST_LEAVE_GROUP        45
#define MCAST_JOIN_SOURCE_GROUP  46
#define MCAST_LEAVE_SOURCE_GROUP 47
#define MCAST_MSFILTER           48
#define IP_MULTICAST_ALL         49
#define IP_UNICAST_IF            50

#define MCAST_EXCLUDE 0
#define MCAST_INCLUDE 1

#define s6_addr   __gt_fc_u.addr8
#define s6_addr16 __gt_fc_u.addr16
#define s6_addr32 __gt_fc_u.addr32

#define IPPORT_ECHO         7
#define IPPORT_DISCARD      9
#define IPPORT_SYSTAT       11
#define IPPORT_DAYTIME      13
#define IPPORT_NETSTAT      15
#define IPPORT_FTP          21
#define IPPORT_TELNET       23
#define IPPORT_SMTP         25
#define IPPORT_TIMESERVER   37
#define IPPORT_NAMESERVER   42
#define IPPORT_WHOIS        43
#define IPPORT_MTP          57
#define IPPORT_TFTP         69
#define IPPORT_RJE          77
#define IPPORT_FINGER       79
#define IPPORT_TTYLINK      87
#define IPPORT_SUPDUP       95
#define IPPORT_EXECSERVER   512
#define IPPORT_LOGINSERVER  13
#define IPPORT_CMDSERVER    514
#define IPPORT_EFSSERVER    520
#define IPPORT_BIFFUDP      512
#define IPPORT_WHOSERVER    513
#define IPPORT_ROUTESERVER  520
#define IPPORT_RESERVED     1024
#define IPPORT_USERRESERVED 5000

#define GROUP_FILTER_SIZE(numsrc) (sizeof (struct group_filter) \
                   - sizeof (struct sockaddr_storage)         \
                   + ((numsrc)                    \
                      * sizeof (struct sockaddr_storage)))

#define IN_CLASSA(a)     ((((in_addr_t)(a)) & 0x80000000) == 0)
#define IN_CLASSA_NET    0xff000000
#define IN_CLASSA_NSHIFT 24
#define IN_CLASSA_HOST   (0xffffffff & ~IN_CLASSA_NET)
#define IN_CLASSA_MAX    128

#define IN_CLASSB(a)     ((((in_addr_t)(a)) & 0xc0000000) == 0x80000000)
#define IN_CLASSB_NET    0xffff0000
#define IN_CLASSB_NSHIFT 16
#define IN_CLASSB_HOST   (0xffffffff & ~IN_CLASSB_NET)
#define IN_CLASSB_MAX    65536

#define IN_CLASSC(a)     ((((in_addr_t)(a)) & 0xe0000000) == 0xc0000000)
#define IN_CLASSC_NET    0xffffff00
#define IN_CLASSC_NSHIFT 8
#define IN_CLASSC_HOST   (0xffffffff & ~IN_CLASSC_NET)

#define IN_CLASSD(a)    ((((in_addr_t)(a)) & 0xf0000000) == 0xe0000000)
#define IN_MULTICAST(a) IN_CLASSD(a)

#define IN_EXPERIMENTAL(a) ((((in_addr_t)(a)) & 0xe0000000) == 0xe0000000)
#define IN_BADCLASS(a)     ((((in_addr_t)(a)) & 0xf0000000) == 0xf0000000)

# define IN6_IS_ADDR_UNSPECIFIED(a) \
    (((const uint32_t *) (a))[0] == 0                     \
     && ((const uint32_t *) (a))[1] == 0                      \
     && ((const uint32_t *) (a))[2] == 0                      \
     && ((const uint32_t *) (a))[3] == 0)

# define IN6_IS_ADDR_LOOPBACK(a) \
    (((const uint32_t *) (a))[0] == 0                     \
     && ((const uint32_t *) (a))[1] == 0                      \
     && ((const uint32_t *) (a))[2] == 0                      \
     && ((const uint32_t *) (a))[3] == htonl (1))

# define IN6_IS_ADDR_LINKLOCAL(a) \
    ((((const uint32_t *) (a))[0] & htonl (0xffc00000))           \
     == htonl (0xfe800000))

# define IN6_IS_ADDR_SITELOCAL(a) \
    ((((const uint32_t *) (a))[0] & htonl (0xffc00000))           \
     == htonl (0xfec00000))

# define IN6_IS_ADDR_V4MAPPED(a) \
    ((((const uint32_t *) (a))[0] == 0)                   \
     && (((const uint32_t *) (a))[1] == 0)                    \
     && (((const uint32_t *) (a))[2] == htonl (0xffff)))

# define IN6_IS_ADDR_V4COMPAT(a) \
    ((((const uint32_t *) (a))[0] == 0)                   \
     && (((const uint32_t *) (a))[1] == 0)                    \
     && (((const uint32_t *) (a))[2] == 0)                    \
     && (ntohl (((const uint32_t *) (a))[3]) > 1))

# define IN6_ARE_ADDR_EQUAL(a,b) \
    ((((const uint32_t *) (a))[0] == ((const uint32_t *) (b))[0])         \
     && (((const uint32_t *) (a))[1] == ((const uint32_t *) (b))[1])      \
     && (((const uint32_t *) (a))[2] == ((const uint32_t *) (b))[2])      \
     && (((const uint32_t *) (a))[3] == ((const uint32_t *) (b))[3]))

#define IN6_IS_ADDR_MULTICAST(a) (((const uint8_t *) (a))[0] == 0xff)

typedef uint16_t in_port_t;
typedef uint32_t in_addr_t;

struct in_addr {
    in_addr_t s_addr;
};

struct sockaddr_in {
    sa_family_t sin_family;
    in_port_t sin_port;
    struct in_addr sin_addr;
};

struct in6_addr {
    union {
        uint8_t addr8[16];
        uint16_t addr16[8];
        uint32_t addr32[4];
    } __gt_fc_u;
};

struct sockaddr_in6 {
    sa_family_t sin6_family;
    in_port_t sin6_port;
    uint32_t sin6_flowinfo;
    struct in6_addr sin6_addr;
    uint32_t sin6_scope_id;
};

struct ipv6_mreq {
    struct in6_addr ipv6mr_multiaddr;
    unsigned ipv6mr_interface;
};

struct in6_pktinfo {
    struct in6_addr ipi6_addr;
    int ipi6_ifindex;
};

struct ip_opts {
    struct in_addr ip_dst;
    char ip_opts[40];
};

struct ip_mreqn {
    struct in_addr imr_multiaddr;
    struct in_addr imr_address;
    int imr_ifindex;
};

struct in_pktinfo {
    int ipi_ifindex;
    struct in_addr ipi_spec_dst;
    struct in_addr ipi_addr;
};

struct group_filter {
    uint32_t gf_interface;
    struct sockaddr_storage gf_group;
    uint32_t gf_fmode;
    uint32_t gf_numsrc;
    struct sockaddr_storage gf_slist[1];
};

struct group_req {
    uint32_t gr_interface;
    struct sockaddr_storage gr_group;
};

struct group_source_req {
    uint32_t gsr_interface;
    struct sockaddr_storage gsr_group;
    struct sockaddr_storage gsr_source;
};

struct ip_mreq {
    struct in_addr imr_multiaddr;
    struct in_addr imr_interface;
};

struct ip_mreq_source {
    struct in_addr imr_multiaddr;
    struct in_addr imr_interface;
    struct in_addr imr_sourceaddr;
};

struct ip_msfilter {
    struct in_addr imsf_multiaddr;
    struct in_addr imsf_interface;
    uint32_t imsf_fmode;
    uint32_t imsf_numsrc;
    struct in_addr imsf_slist[1];
};

struct ip6_mtuinfo {
    struct sockaddr_in6 ip6m_addr;
    uint32_t ip6m_mtu;
};

const struct in6_addr in6addr_any = { { 0 } };
const struct in6_addr in6addr_loopback = { { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF } };

/*@ assigns \result \from arg ; */
uint32_t htonl(uint32_t arg);
/*@ assigns \result \from arg ; */
uint16_t htons(uint16_t arg);
/*@ assigns \result \from arg ; */
uint32_t ntohl(uint32_t arg);
/*@ assigns \result \from arg ; */
uint16_t ntohs(uint16_t arg);

/* GNU Extensions */

#define INADDR_LOOPBACK 0X7F000001UL
#define INADDR_NONE -1

#define IPPORT_RESERVED 1024
#define IPPORT_USERRESERVED 5000

/*
The following macros are for the TLV (Type-Length-Value) data type, which isn't a struct, but has a defined format.
This is better than casting TLVs to a private struct, because Frama-C isn't very good at casting.
*/

#define __GT_FC_TLV_TYPE(tlv) ((tlv)[0])
#define __GT_FC_TLV_SIZE(tlv) ((tlv)[1])
#define __GT_FC_TLV_DATA(tlv) (&(tlv)[2])
#define __GT_FC_TLV_SIZEOF(tlv) (sizeof(uint8_t) * (2 + __GT_FC_TLV_SIZE(tlv)))

/*@
axiomatic HopToHopOptions {
    logic int inet6_option_size(int nbytes);
    logic int inet6_option_room(struct cmsghdr * cmsg) reads *cmsg;

    axiom inet6_option_size_gt_0: \forall int i; inet6_option_size(i) > 0;
    axiom inet6_option_size_inc: \forall int i; \forall int j; i > j ==> inet6_option_size(i) >= inet6_option_size(j);
    axiom inet6_option_size_neg: \forall int i; i < 0 ==> inet6_option_size(i) == inet6_option_size((int)0);

    axiom inet6_option_room_gt_0: \forall struct cmsghdr * cmsg; inet6_option_room(cmsg) >= 0;
}
*/

/*@
requires sin != \null ==> \valid(sin);
assigns \result, *sin;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> sin != \null ==> 512 <= sin->sin_port <= 1023;
*/
int bindresvport(int sockfd, struct sockaddr_in *sin);

/*@
requires sin != \null ==> \valid(sin);
assigns \result, *sin;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> sin != \null ==> 512 <= sin->sin6_port <= 1023;
*/
int bindresvport6(int sockfd, struct sockaddr_in6 *sin);

/*@
assigns \result \from nbytes;
ensures \result >= nbytes;
ensures \result == inet6_option_size(nbytes);
*/
int inet6_option_space(int nbytes);

/*@
requires \valid(cmsgp);
requires \valid(((char*)bp)+(0..inet6_option_size((int)0)-1));
assigns \result, *cmsgp, ((char*)bp)[0..inet6_option_size((int)0)-1];
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> \valid(*cmsgp);
ensures \result == 0 ==> \forall int i; \block_length((char*)bp) == inet6_option_size(i) ==> inet6_option_room(*cmsgp) == i;
*/
int inet6_option_init(void *bp, struct cmsghdr **cmsgp, int type);

/*@
requires \valid(cmsg);
requires \valid_read(typep+(0..( __GT_FC_TLV_SIZEOF(typep) )-1));
requires inet6_option_room(cmsg) >= __GT_FC_TLV_SIZE(typep);
requires 2 <= __GT_FC_TLV_TYPE(typep) <= 255;
requires 0 <= __GT_FC_TLV_SIZE(typep) <= 255;
assigns \result, *cmsg;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> inet6_option_room(cmsg) == \old(inet6_option_room(cmsg)) - __GT_FC_TLV_SIZE(typep);
ensures \result == -1 ==> inet6_option_room(cmsg) == \old(inet6_option_room(cmsg));
*/
int inet6_option_append(struct cmsghdr *cmsg, const uint8_t *typep, int multx, int plusy);

/*@
requires \valid(cmsg);
requires inet6_option_room(cmsg) >= datalen;
assigns \result, *cmsg;
ensures \result != \null ==> \valid(\result+(0..( __GT_FC_TLV_SIZEOF(\result) )-1));
ensures \result != \null ==> inet6_option_room(cmsg) == \old(inet6_option_room(cmsg)) - datalen;
ensures \result == \null ==> inet6_option_room(cmsg) == \old(inet6_option_room(cmsg));
*/
uint8_t *inet6_option_alloc(struct cmsghdr *cmsg, int datalen, int multx, int plusy);

/*@
requires \valid(cmsg);
requires \valid(tptrp);
assigns \result, *tptrp;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> \valid((*tptrp)+(0..( __GT_FC_TLV_SIZEOF(*tptrp) )-1));
*/
int inet6_option_next(const struct cmsghdr *cmsg, uint8_t **tptrp);

/*@
requires \valid(cmsg);
requires \valid(tptrp);
assigns \result, *tptrp;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> \valid((*tptrp)+(0..( __GT_FC_TLV_SIZEOF(*tptrp) )-1));
ensures \result == 0 ==> __GT_FC_TLV_TYPE(*tptrp) == type;
*/
int inet6_option_find(const struct cmsghdr *cmsg, uint8_t **tptrp, int type);

/*@
axiomatic HopToHopOptionsNew {
    logic boolean inet6_opt_is_open(void *extbuf) reads ((char*)extbuf)[0..];
    logic int inet6_opt_min_size;
    logic int inet6_opt_room_used(void *extbuf) reads ((char*)extbuf)[0..];
    logic int inet6_opt_size(socklen_t n);

    axiom inet6_opt_min_size_gt_0: inet6_opt_min_size > 0;
    axiom inet6_opt_min_size_mul_8: inet6_opt_min_size % 8 == 0;
    axiom inet6_opt_min_size_fits: inet6_opt_min_size == (socklen_t) inet6_opt_min_size;

    axiom inet6_opt_room_gt_0: \forall void *extbuf; inet6_opt_room_used(extbuf) >= 0;
    axiom inet6_opt_room_fits: \forall void *extbuf; inet6_opt_room_used(extbuf) == (socklen_t) inet6_opt_room_used(extbuf);

    axiom inet6_opt_size_gt_0: \forall socklen_t i; inet6_opt_size(i) > 0;
    axiom inet6_opt_size_inc: \forall socklen_t i; \forall socklen_t j; i > j ==> inet6_opt_size(i) >= inet6_opt_size(j);
    axiom inet6_opt_size_neg: \forall socklen_t i; i < 0 ==> inet6_opt_size(i) == inet6_opt_size((socklen_t)0);
}
*/

/*@
requires extbuf != \null ==> extlen >= inet6_opt_min_size ==> extlen % 8 == 0 ==> \valid(((char*)extbuf)+(0..extlen-1));
assigns \result, ((char*)extbuf)[0..extlen-1];
ensures \result == -1 || \result == inet6_opt_min_size;
ensures extbuf != \null ==> extlen < inet6_opt_min_size || extlen % 8 != 0 ==> \result == -1;
ensures extbuf == \null ==> \result == inet6_opt_min_size;
ensures extbuf != \null ==> \result != -1 ==> inet6_opt_is_open(extbuf);
ensures extbuf != \null ==> \result != -1 ==> inet6_opt_room_used(extbuf) == extlen;
*/
int inet6_opt_init(void *extbuf, socklen_t extlen);

/*@
requires extbuf != \null ==> \valid(((char*)extbuf)+(0..extlen-1));
requires extbuf != \null ==> \valid(databufp);
requires extbuf != \null ==> inet6_opt_is_open(extbuf);
assigns \result, ((char*)extbuf)[0..extlen-1], ((char*)*databufp)[0..len-1];
ensures extbuf != \null ==> inet6_opt_is_open(extbuf);
ensures extbuf != \null ==> \result != -1 ==> inet6_opt_room_used(extbuf) == \old(inet6_opt_room_used(extbuf)) + inet6_opt_size(len);
ensures extbuf != \null ==> \result == -1 ==> inet6_opt_room_used(extbuf) == \old(inet6_opt_room_used(extbuf));
ensures extbuf == \null ==> \result == inet6_opt_min_size + inet6_opt_size(len);
ensures extbuf != \null ==> \result == -1 || \result == inet6_opt_room_used(extbuf);
ensures extbuf != \null ==> \result != -1 ==> \valid(((char*)*databufp)+(0..len-1));
*/
int inet6_opt_append(void *extbuf, socklen_t extlen, int offset, uint8_t type, socklen_t len, uint8_t align, void **databufp);

/*@
requires extbuf != \null ==> \valid(((char*)extbuf)+(0..extlen-1));
requires extbuf != \null ==> inet6_opt_is_open(extbuf);
assigns \result, ((char*)extbuf)[0..extlen-1];
ensures extbuf != \null ==> inet6_opt_is_open(extbuf);
ensures extbuf != \null ==> \result != -1 ==> inet6_opt_room_used(extbuf) >= \old(inet6_opt_room_used(extbuf));
ensures extbuf != \null ==> \result == -1 ==> inet6_opt_room_used(extbuf) == \old(inet6_opt_room_used(extbuf));
ensures extbuf == \null ==> \result >= inet6_opt_min_size;
ensures extbuf != \null ==> \result == -1 || \result == inet6_opt_room_used(extbuf);
*/
int inet6_opt_finish(void *extbuf, socklen_t extlen, int offset);

/*@
requires \valid(((char*)databuf)+offset+(0..vallen-1));
requires \valid(((char*)val)+(0..vallen-1));
assigns \result, (((char*)databuf)+offset)[0..vallen-1];
ensures \result == offset + vallen;
*/
int inet6_opt_set_val(void *databuf, int offset, void *val, socklen_t vallen);

/*@
requires inet6_opt_is_open(extbuf);
requires \valid(((char*)extbuf)+(0..extlen-1));
requires \valid(typep);
requires \valid(lenp);
requires \valid(databufp);
assigns \result,  ((char*)extbuf)[0..extlen-1], *typep, *lenp, *databufp;
ensures \result >= -1;
ensures \result != -1 ==> \valid(((char*)*databufp)+(0..*lenp-1));
ensures inet6_opt_is_open(extbuf);
ensures inet6_opt_room_used(extbuf) == \old(inet6_opt_room_used(extbuf));
*/
int inet6_opt_next(void *extbuf, socklen_t extlen, int offset, uint8_t *typep, socklen_t *lenp, void **databufp);

/*@
requires inet6_opt_is_open(extbuf);
requires \valid(((char*)extbuf)+(0..extlen-1));
requires \valid(lenp);
requires \valid(databufp);
assigns \result,  ((char*)extbuf)[0..extlen-1], *lenp, *databufp;
ensures \result >= -1;
ensures \result != -1 ==> \valid(((char*)*databufp)+(0..*lenp-1));
ensures inet6_opt_is_open(extbuf);
ensures inet6_opt_room_used(extbuf) == \old(inet6_opt_room_used(extbuf));
*/
int inet6_opt_find(void *extbuf, socklen_t extlen, int offset, uint8_t type, socklen_t *lenp, void **databufp);

/*@
requires \valid(((char*)databuf)+offset+(0..vallen-1));
requires \valid(((char*)val)+(0..vallen-1));
assigns \result, (((char*)val))[0..vallen-1];
ensures \result == offset + vallen;
*/
int inet6_opt_get_val(void *databuf, int offset, void *val, socklen_t vallen);

/*@
axiomatic RoutingHeader {
    logic int inet6_rth_space(int type, int segments);
    logic boolean inet6_rth_is_open(void *bp) reads ((char*)bp)[0..];
    logic int inet6_rth_segs(void *bp) reads ((char*)bp)[0..];

    axiom inet6_rth_space_gt_0: \forall int i; \forall int j; inet6_rth_space(i, j) > 0;
}
*/

/*@
assigns \result;
ensures \result != 0 ==> \result == inet6_rth_space(type, segments);
*/
socklen_t inet6_rth_space(int type, int segments);

/*@
requires \valid(((char*)bp)+(0..bp_len-1));
requires bp_len >= inet6_rth_space(type, segments);
assigns \result, ((char*)bp)[0..bp_len-1];
ensures \result != \null ==> \result == bp;
ensures \result != \null ==> inet6_rth_is_open(bp);
ensures \result != \null ==> inet6_rth_segs(bp) == segments;
*/
void *inet6_rth_init(void *bp, socklen_t bp_len, int type, int segments);

/*@
requires inet6_rth_is_open(bp);
requires \valid_read(addr);
assigns \result, ((char*)bp)[0..];
ensures inet6_rth_is_open(bp);
ensures inet6_rth_segs(bp) == \old(inet6_rth_segs(bp));
ensures \result == 0 || \result == -1;
*/
int inet6_rth_add(void *bp, const struct in6_addr *addr);

/*@
requires inet6_rth_is_open(in);
requires inet6_rth_is_open(out);
assigns \result, ((char*)out)[0..];
ensures inet6_rth_is_open(out);
ensures inet6_rth_segs(out) == \old(inet6_rth_segs(out));
ensures \result == 0 || \result == -1;
*/
int inet6_rth_reverse(const void *in, void *out);

/*@
requires inet6_rth_is_open(bp);
assigns \result;
ensures \result == inet6_rth_segs(bp);
*/
int inet6_rth_segments(const void *bp);

/*@
requires inet6_rth_is_open(bp);
assigns \result;
ensures \result != \null ==> \valid(\result);
*/
struct in6_addr *inet6_rth_getaddr(const void *bp, int index);

/*@
requires \valid(numsrc);
requires \valid(slist+(0..*numsrc-1));
requires \valid(fmode);
assigns errno, \result, *fmode, *numsrc, slist[0..*numsrc-1];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int getipv4sourcefilter(int s, struct in_addr interface_addr, struct in_addr group, uint32_t *fmode, uint32_t *numsrc, struct in_addr *slist);

/*@
requires \valid(slist+(0..numsrc-1));
assigns errno, \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setipv4sourcefilter(int s, struct in_addr interface_addr, struct in_addr group, uint32_t fmode, uint32_t numsrc, const struct in_addr *slist);

/*@
requires \valid(numsrc);
requires \valid(slist+(0..*numsrc-1));
requires \valid(fmode);
requires \valid(group+(0..grouplen-1));
assigns errno, \result, *fmode, *numsrc, slist[0..*numsrc-1];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int getsourcefilter(int s, uint32_t interface_addr, const struct sockaddr *group, socklen_t grouplen, uint32_t *fmode, uint32_t *numsrc, struct sockaddr_storage *slist);

/*@
requires \valid(slist+(0..numsrc-1));
requires \valid(group+(0..grouplen-1));
assigns errno, \result;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setsourcefilter(int s, uint32_t interface_addr, const struct sockaddr *group, socklen_t grouplen, uint32_t fmode, uint32_t numsrc, const struct sockaddr_storage *slist);

#endif
