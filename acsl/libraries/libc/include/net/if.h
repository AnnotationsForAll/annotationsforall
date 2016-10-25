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

#ifndef FC_NET_IF
#define FC_NET_IF

#include "../sys/socket.h"
#include "../__fc_string_axiomatic.h"
#include "../__gt_fc_define_ifa_macros.h"

#define IF_NAMESIZE 255

#define IFF_UP          (1 << 0)
#define IFF_BROADCAST   (1 << 1)
#define IFF_DEBUG       (1 << 2)
#define IFF_LOOPBACK    (1 << 3)
#define IFF_POINTOPOINT (1 << 4)
#define IFF_NOTRAILERS  (1 << 5)
#define IFF_RUNNING     (1 << 6)
#define IFF_NOARP       (1 << 7)
#define IFF_PROMISC     (1 << 8)
#define IFF_ALLMULTI    (1 << 9)
#define IFF_MASTER      (1 << 10)
#define IFF_SLAVE       (1 << 11)
#define IFF_MULTICAST   (1 << 12)
#define IFF_PORTSEL     (1 << 13)
#define IFF_AUTOMEDIA   (1 << 14)
#define IFF_DYNAMIC     (1 << 15)
#define IFF_LOWER_UP    (1 << 16)
#define IFF_DORMANT     (1 << 17)
#define IFF_ECHO        (1 << 18)

#define IFF_VOLATILE    (IFF_LOOPBACK|IFF_POINTOPOINT|IFF_BROADCAST|IFF_ECHO|IFF_MASTER|IFF_SLAVE|IFF_RUNNING|IFF_LOWER_UP|IFF_DORMANT)

#define ifr_name      ifr_ifrn.ifrn_name
#define ifr_hwaddr    ifr_ifru.ifru_hwaddr
#define ifr_addr      ifr_ifru.ifru_addr
#define ifr_dstaddr   ifr_ifru.ifru_dstaddr
#define ifr_broadaddr ifr_ifru.ifru_broadaddr
#define ifr_netmask   ifr_ifru.ifru_netmask
#define ifr_flags     ifr_ifru.ifru_flags
#define ifr_metric    ifr_ifru.ifru_ivalue
#define ifr_mtu       ifr_ifru.ifru_mtu
#define ifr_map       ifr_ifru.ifru_map
#define ifr_slave     ifr_ifru.ifru_slave
#define ifr_data      ifr_ifru.ifru_data
#define ifr_ifindex   ifr_ifru.ifru_ivalue
#define ifr_bandwidth ifr_ifru.ifru_ivalue
#define ifr_qlen      ifr_ifru.ifru_ivalue
#define ifr_newname   ifr_ifru.ifru_newname

#define ifc_buf ifc_ifcu.ifcu_buf
#define ifc_req ifc_ifcu.ifcu_req

#define IFHWADDRLEN 6
#define IFNAMSIZ    IF_NAMESIZE

// struct iface is an opaque structure type, not usually defined by glibc. But we need to make sure frama-c doesn't have an issue with this.
struct iface {
    void* __gt_fc_dummy;
};

struct ifaddr {
    struct sockaddr ifa_addr;
    union {
        struct sockaddr ifu_broadaddr;
        struct sockaddr ifu_dstaddr;
    } ifa_ifu;
    struct iface *ifa_ifp;
    struct ifaddr *ifa_next;
};

struct ifmap {
    unsigned long int mem_start;
    unsigned long int mem_end;
    unsigned short int base_addr;
    unsigned char irq;
    unsigned char dma;
    unsigned char port;
};

struct ifreq {
    union {
        char ifrn_name[IFNAMSIZ];
    } ifr_ifrn;
    union {
        struct sockaddr ifru_addr;
        struct sockaddr ifru_dstaddr;
        struct sockaddr ifru_broadaddr;
        struct sockaddr ifru_netmask;
        struct sockaddr ifru_hwaddr;
        short int ifru_flags;
        int ifru_ivalue;
        int ifru_mtu;
        struct ifmap ifru_map;
        char ifru_slave[IFNAMSIZ];
        char ifru_newname[IFNAMSIZ];
        char * ifru_data;
    } ifr_ifru;
};

struct ifconf {
    int ifc_len;
    union {
        char *ifcu_buf;
        struct ifreq *ifcu_req;
    } ifc_ifcu;
};

struct if_nameindex {
    unsigned if_index;
    char *if_name;
};

/*@
axiomatic IsIfOpen {
    logic boolean if_is_open{L}(struct if_nameindex * ni) reads *ni;
}
*/

/*@
requires \valid(name);
assigns \result \from name[..];
ensures \result >= 0;
*/
unsigned if_nametoindex(const char * name);

/*@
requires \valid(name+(0 .. IF_NAMESIZE-1));
assigns \result \from index, name[..];
ensures \result == \null || \result == name;
*/
char *if_indextoname(unsigned index, char *name);

/*@
assigns \result \from \nothing;
ensures \valid(\result) || \result == \null;
ensures \result != \null ==> \exists integer i; \valid(\result+i) && \result[i].if_index == 0 && \result[i].if_name == \null;
ensures \result != \null ==> (\valid(\result) && if_is_open(\result));
*/
struct if_nameindex *if_nameindex(void);

/*@
requires if_is_open(ni);
assigns *ni \from *ni;
ensures !if_is_open(ni);
*/
void if_freenameindex(struct if_nameindex *ni);

#endif
