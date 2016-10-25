/*
 * ether.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETINET_ETHER_H_
#define LIBC_NETINET_ETHER_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "if_ether.h"
#include "../__fc_string_axiomatic.h"

#define __GT_FC_MAX_HOSTNAME    255
#define __GT_FC_MAX_MAC_ADDRESS 16

/*@
requires \valid_read(addr);
assigns \result \from *addr;
ensures valid_string(\result);
ensures 0 <= strlen(\result) <= __GT_FC_MAX_MAC_ADDRESS;
*/
char *ether_ntoa(const struct ether_addr *addr);

/*@
requires valid_read_string(asc);
assigns \result \from asc[0..strlen(asc)];
ensures \valid(\result);
*/
struct ether_addr *ether_aton(const char *asc);

/*@
requires \valid(hostname+(0..( __GT_FC_MAX_HOSTNAME )-1));
requires \valid_read(addr);
assigns \result, hostname[0..( __GT_FC_MAX_HOSTNAME )-1];
ensures valid_string(hostname);
ensures \result == 0 ==> 0 <= strlen(hostname) <= 255;
*/
int ether_ntohost(char *hostname, const struct ether_addr *addr);

/*@
requires valid_read_string(hostname);
requires \valid(addr);
assigns \result, *addr;
ensures \result != 0 ==> *addr == \old(*addr);
*/
int ether_hostton(const char *hostname, struct ether_addr *addr);

/*@
requires valid_read_string(line);
requires \valid(addr);
requires \valid(hostname+(0..( __GT_FC_MAX_HOSTNAME )-1));
assigns \result, *addr, hostname[0..( __GT_FC_MAX_HOSTNAME )-1];
ensures \result != 0 ==> *addr == \old(*addr);
ensures valid_string(hostname);
ensures \result == 0 ==> 0 <= strlen(hostname) <= 255;
*/
int ether_line(const char *line, struct ether_addr *addr, char *hostname);

/*@
requires \valid_read(addr);
requires \valid(buf+(0..( __GT_FC_MAX_MAC_ADDRESS )-1));
assigns \result, buf[0..( __GT_FC_MAX_MAC_ADDRESS )-1] \from *addr;
ensures \result == buf;
ensures valid_string(\result);
ensures 0 <= strlen(\result) <= __GT_FC_MAX_MAC_ADDRESS;
*/
char *ether_ntoa_r(const struct ether_addr *addr, char *buf);

/*@
requires valid_read_string(asc);
requires \valid(addr);
assigns \result \from asc[0..strlen(asc)];
ensures \result == addr;
*/
struct ether_addr *ether_aton_r(const char *asc, struct ether_addr *addr);

#endif /* LIBC_NETINET_ETHER_H_ */
