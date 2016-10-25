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

#ifndef FC_ARPA_INET
#define FC_ARPA_INET
#include "../errno.h"
#include "../inttypes.h"
#include "../netinet/in.h"
#include "../__gt_fc_math_axiomatic.h"
#include "../__fc_string_axiomatic.h"
#include "nameser.h"

/*@
requires \valid(arg);
assigns \result \from arg;
*/
in_addr_t inet_addr(const char * arg);
/*@
assigns \result \from arg;
ensures valid_string(\result);
*/
char *inet_ntoa(struct in_addr arg);

/*@
requires (af == AF_INET ==> \valid(((char*)src)+(0..3))) && (af == AF_INET6 ==> \valid(((char*)src)+(0..15)));
requires \valid(dst+(0..size-1));
assigns \result, dst[0..size-1], errno \from af, ((char*)src)[0..], size;
behavior invalid_af:
    assumes af != AF_INET && af != AF_INET6;
    ensures \result == \null;
    ensures errno == EAFNOSUPPORT;
behavior no_space:
    assumes (af == AF_INET || af == AF_INET6) && (af == AF_INET ==> size < INET_ADDRSTRLEN ) && (af == AF_INET6 ==> size < INET6_ADDRSTRLEN );
    ensures \result == \null;
    ensures errno == ENOSPC;
behavior success:
    ensures \result != \null ==> \result == dst;
    ensures \result != \null ==> valid_string(\result);
    ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);

/*@
requires \valid(src);
requires (af == AF_INET ==> \valid(((char*)dst)+(0..3))) && (af == AF_INET6 ==> \valid(((char*)dst)+(0..15)));
assigns \result \from af,src[..];
assigns \result, ((char*)dst)[0..], errno \from af,src[0..];
behavior invalid_af:
    assumes af != AF_INET && af != AF_INET6;
    assigns __FC_errno \from af;
    ensures \result == -1;
    ensures errno == EAFNOSUPPORT;
behavior success:
    ensures \result == -1 || \result == 1 || \result == 0;
    ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int inet_pton(int af, const char *src, void *dst);

/* GNU Extensions */

/*@
requires \valid(src);
requires \valid(dst);
assigns \result \from src[0..];
assigns \result, ((char*)dst)[0..3] \from src[0..];
*/
int inet_aton(const char* src, struct in_addr* dst);

/*@
requires \valid(name);
assigns \result \from name[0..];
*/
uint32_t inet_network(const char* name);

/*@
assigns \result \from net, local;
*/
struct in_addr inet_makeaddr(uint32_t net, uint32_t local);

/*@
assigns \result \from addr;
*/
uint32_t inet_lnaof(struct in_addr addr);

/*@
assigns \result \from addr;
*/
uint32_t inet_netof(struct in_addr addr);

/*@
requires \valid(buf+(0..len-1));
assigns errno, \result, buf[0..len-1] \from net, len;
ensures \result != \null ==> \result == buf;
ensures \result != \null ==> valid_string(buf);
ensures \result == \null ? errno == EMSGSIZE : errno == \old(errno);
*/
char *inet_neta(in_addr_t net, char *buf, size_t len);

/*@
requires \valid(buf+(0..len-1));
requires \valid_read(((char*)cp)+(0..((bits+7)/8)*8-1));
assigns \result, errno, buf[0..len-1] \from ((char*)cp)[0..ceil(bits/8.0)-1], af, len;
ensures \result != \null ==> \result == buf;
ensures \result != \null ==> valid_string(buf);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
char *inet_net_ntop(int af, const void *cp, int bits, char *buf, size_t len);

/*@
requires valid_read_string(cp);
requires \valid(((char*)buf)+(0..len-1));
assigns \result, errno, ((char*)buf)[0..len-1] \from cp[0..strlen(cp)], af, len;
ensures -1 <= \result <= len*8;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int inet_net_pton(int af, const char *cp, void *buf, size_t len);

// The following functions are undocumented, but are used by some applications.

unsigned int inet_nsap_addr(const char *cp, unsigned char *buf, int len);
char *inet_nsap_ntoa(int len, const unsigned char *cp, char *buf);

#endif
