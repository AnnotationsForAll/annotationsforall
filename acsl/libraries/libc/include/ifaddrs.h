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

#ifndef FC_IFADDRS
#define FC_IFADDRS

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "features.h"
#include "__fc_define_sockaddr.h"
#include "__gt_fc_define_ifa_macros.h"
#include "__fc_string_axiomatic.h"
#include "errno.h"

__BEGIN_DECLS

struct ifaddrs {
    struct ifaddrs *ifa_next;
    char *ifa_name;
    unsigned int ifa_flags;
    struct sockaddr *ifa_addr;
    struct sockaddr *ifa_netmask;
    union {
        struct sockaddr *ifu_broadaddr;
        struct sockaddr *ifu_dstaddr;
    } ifa_ifu;
    void *ifa_data;
};

struct ifmaddrs {
    struct ifmaddrs *ifma_next;
    struct sockaddr *ifma_name;
    struct sockaddr *ifma_addr;
    struct sockaddr *ifma_lladdr;
};

#define __gt_fc_valid_ifa(ifap) (\valid(ifap) && valid_ifa_next(ifap) && valid_ifa_name(ifap) && valid_ifa_addr(ifap) && valid_ifa_netmask(ifap) && valid_ifa_ifu(ifap))
#define __gt_fc_valid_ifma(ifmap) (\valid(ifmap) && valid_ifma_next(ifmap) && valid_ifma_name(ifmap) && valid_ifma_addr(ifmap) && valid_ifma_lladdr(ifmap))


/*@
axiomatic IFAddrs {
    logic boolean valid_ifa_next(struct ifaddrs * ifap) reads ifap->ifa_next;
    logic boolean valid_ifa_name(struct ifaddrs * ifap) reads ifap->ifa_name;
    logic boolean valid_ifa_addr(struct ifaddrs * ifap) reads ifap->ifa_addr;
    logic boolean valid_ifa_netmask(struct ifaddrs * ifap) reads ifap->ifa_netmask;
    logic boolean valid_ifa_ifu(struct ifaddrs * ifap) reads ifap->ifa_ifu;

    axiom define_valid_ifa_next: \forall struct ifaddrs * ifap; valid_ifa_next(ifap) ==> ifap->ifa_next != \null ==> __gt_fc_valid_ifa(ifap->ifa_next);
    axiom define_valid_ifa_name: \forall struct ifaddrs * ifap; valid_ifa_name(ifap) ==> valid_string(ifap->ifa_name);
    axiom define_valid_ifa_addr: \forall struct ifaddrs * ifap; valid_ifa_addr(ifap) ==> ifap->ifa_addr != \null ==> \valid(ifap->ifa_addr);
    axiom define_valid_ifa_netmask: \forall struct ifaddrs * ifap; valid_ifa_netmask(ifap) ==> ifap->ifa_netmask != \null ==> \valid(ifap->ifa_netmask);
    axiom define_valid_ifa_ifu: \forall struct ifaddrs * ifap; valid_ifa_netmask(ifap) ==> \valid(ifap->ifa_ifu.ifu_broadaddr) && \valid(ifap->ifa_ifu.ifu_dstaddr);
}
*/

/*@
axiomatic IFMulticastAddrs {
    logic boolean valid_ifma_next(struct ifmaddrs * ifmap) reads ifmap->ifma_next;
    logic boolean valid_ifma_name(struct ifmaddrs * ifmap) reads ifmap->ifma_name;
    logic boolean valid_ifma_addr(struct ifmaddrs * ifmap) reads ifmap->ifma_addr;
    logic boolean valid_ifma_lladdr(struct ifmaddrs * ifmap) reads ifmap->ifma_lladdr;

    axiom define_valid_ifma_next: \forall struct ifmaddrs * ifmap; valid_ifma_next(ifmap) ==> ifmap->ifma_next != \null ==> __gt_fc_valid_ifma(ifmap->ifma_next);
    axiom define_valid_ifma_name: \forall struct ifmaddrs * ifmap; valid_ifma_name(ifmap) ==> \valid(ifmap->ifma_name);
    axiom define_valid_ifma_addr: \forall struct ifmaddrs * ifmap; valid_ifma_addr(ifmap) ==> \valid(ifmap->ifma_addr);
    axiom define_valid_ifma_lladdr: \forall struct ifmaddrs * ifmap; valid_ifma_lladdr(ifmap) ==> ifmap->ifma_lladdr != \null ==> \valid(ifmap->ifma_lladdr);
}
*/

/*@
requires \valid(ifap);
assigns errno, \result, *ifap;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
ensures \result == 0 ==> __gt_fc_valid_ifa(*ifap);
*/
int getifaddrs(struct ifaddrs ** ifap);

/*@
requires __gt_fc_valid_ifa(ifap);
assigns *ifap;
*/
void freeifaddrs(struct ifaddrs * ifap);

/*@
requires \valid(ifmap);
assigns errno, \result, *ifmap;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
ensures \result == 0 ==> __gt_fc_valid_ifma(*ifmap);
*/
int getifmaddrs(struct ifmaddrs ** ifmap);

/*@
requires __gt_fc_valid_ifma(ifmap);
assigns *ifmap;
*/
void freeifmaddrs(struct ifmaddrs * ifmap);

__END_DECLS

#endif
