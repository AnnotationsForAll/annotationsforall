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

#ifndef __FC_SOCKET_H__
#define __FC_SOCKET_H__

#include "../__fc_machdep.h"
#include "../__fc_define_restrict.h"
#include "../__fc_define_sa_family_t.h"
#include "../__fc_define_sockaddr.h"
#include "../__fc_define_ssize_t.h"
#include "../__fc_define_timespec.h"
#include "__gt_fc_define_socklen_t.h"
#include "../__fc_define_iovec.h"
#include "stat.h"

struct sockaddr_storage {
  sa_family_t   ss_family;
};

struct cmsghdr {
  socklen_t  cmsg_len;
  int        cmsg_level;
  int        cmsg_type;
};

#define SCM_RIGHTS 0

struct msghdr {
  void          *msg_name;
  socklen_t      msg_namelen;
  struct iovec  *msg_iov;
  int            msg_iovlen;
  void          *msg_control;
  socklen_t      msg_controllen;
  int            msg_flags;
};

/* Socket types. */
#define SOCK_STREAM 1
#define SOCK_DGRAM  2
#define SOCK_RAW    3
#define SOCK_RDM    4
#define SOCK_SEQPACKET  5

/* Message types. */
#define MSG_CMSG_CLOEXEC (1 << 0)
#define MSG_DONTWAIT     (1 << 1)
#define MSG_ERRQUEUE     (1 << 2)
#define MSG_OOB          (1 << 3)
#define MSG_PEEK         (1 << 4)
#define MSG_TRUNC        (1 << 5)
#define MSG_WAITALL      (1 << 6)
#define MSG_WAITFORONE   (1 << 7)
#define MSG_CONFIRM      (1 << 8)
#define MSG_DONTROUTE    (1 << 9)
#define MSG_EOR          (1 << 10)
#define MSG_MORE         (1 << 11)
#define MSG_NOSIGNAL     (1 << 12)

/* Supported address families. */
#define AF_UNSPEC       0
#define AF_UNIX         1
#define AF_LOCAL        1
#define AF_INET         2
#define AF_IMPLINK      3
#define AF_PUP          4
#define AF_CHAOS        5
#define AF_NS           6
#define AF_ISO          7
#define AF_OSI          AF_ISO
#define AF_ECMA         8
#define AF_DATAKIT      9
#define AF_CCITT        10
#define AF_SNA          11
#define AF_DECnet       12
#define AF_DLI          13
#define AF_LAT          14
#define AF_HYLINK       15
#define AF_APPLETALK    16
#define AF_NETBIOS      17
#define AF_INET6        18
#define AF_MAX          32

#define PF_UNSPEC       AF_UNSPEC
#define PF_UNIX         AF_UNIX
#define PF_LOCAL        AF_LOCAL
#define PF_INET         AF_INET
#define PF_IMPLINK      AF_IMPLINK
#define PF_PUP          AF_PUP
#define PF_CHAOS        AF_CHAOS
#define PF_NS           AF_NS
#define PF_ISO          AF_ISO
#define PF_OSI          AF_OSI
#define PF_ECMA         AF_ECMA
#define PF_DATAKIT      AF_DATAKIT
#define PF_CCITT        AF_CCITT
#define PF_SNA          AF_SNA
#define PF_DECnet       AF_DECnet
#define PF_DLI          AF_DLI
#define PF_LAT          AF_LAT
#define PF_HYLINK       AF_HYLINK
#define PF_APPLETALK    AF_APPLETALK
#define PF_NETBIOS      AF_NETBIOS
#define PF_MAX          AF_MAX

#define SOL_SOCKET      0xffff

#define SO_DEBUG        0x0001
#define SO_ACCEPTCONN   0x0002
#define SO_REUSEADDR    0x0004
#define SO_KEEPALIVE    0x0008
#define SO_DONTROUTE    0x0010
#define SO_BROADCAST    0x0020
#define SO_USELOOPBACK  0x0040
#define SO_LINGER       0x0080
#define SO_OOBINLINE    0x0100
#define SO_DONTLINGER   (unsigned int)(~SO_LINGER)
#define SO_PEERCRED 0x0200

#define SO_ERROR        0x1000

#define SOMAXCONN 0xFF

/*@
requires address != \null ==> \valid(address);
requires address_len != \null ==> \valid(address_len);
requires address == \null <==> address_len == \null;
assigns \result, *address, *address_len \from socket;
ensures \result >= -1;
*/
int accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);

/*@
requires \valid(address);
assigns \result \from socket, *address, address_len;
ensures \result == -1 || \result == 0;
*/
int bind(int socket, const struct sockaddr *address, socklen_t address_len);

/*@
requires \valid(address);
assigns \result \from socket, *address, address_len;
ensures \result == -1 || \result == 0;
*/
int connect(int socket, const struct sockaddr *address, socklen_t address_len);

/*@
requires \valid(address);
requires \valid(address_len);
assigns \result, *address, *address_len \from socket, *address_len;
ensures \result == -1 || \result == 0;
*/
int getpeername(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);

/*@
requires \valid(address_len);
requires \valid(address);
assigns \result, *address, *address_len \from socket, *address_len;
ensures \result == -1 || \result == 0;
*/
int getsockname(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);

/*@
requires \valid(option_len);
requires \valid((char *)option_value);
assigns \result \from socket, level, option_name, option_value, *option_len;
ensures \result == -1 || \result == 0;
*/
int getsockopt(int socket, int level, int option_name, void *restrict option_value, socklen_t *restrict option_len);

/*@
assigns \result \from socket, backlog;
ensures \result == -1 || \result == 0;
*/
int listen(int socket, int backlog);

/*@
requires \valid(((char*)buffer)+(0 .. length-1));
assigns ((char*)buffer)[0 .. length-1] \from socket, length, flags;
ensures -1 <= \result <= length;
*/
ssize_t recv(int socket, void * buffer, size_t length, int flags);

/*@
requires \valid(((char*)buffer)+(0 .. length-1));
requires address != \null ==> \valid(address);
requires address_len != \null ==> \valid(address_len);
requires address == \null <==> address_len == \null;
assigns ((char*)buffer)[0 .. length-1] \from socket, length, flags, *address, *address_len;
ensures -1 <= \result <= length;
*/
ssize_t recvfrom(int socket, void *restrict buffer, size_t length, int flags, struct sockaddr *restrict address, socklen_t *restrict address_len);

/*@ requires \valid(&((char *)hdr->msg_control)[0..hdr->msg_controllen-1]);
  @ requires \valid(&(hdr->msg_iov[0..hdr->msg_iovlen-1]));
  @ requires hdr->msg_name == 0
      || \valid(&((char *)hdr->msg_name)[0..hdr->msg_namelen-1]);
  @ assigns ((char *) hdr->msg_name)[0..hdr->msg_namelen-1];
  @ assigns hdr->msg_namelen;
  @ assigns ((char *) hdr->msg_iov[0..hdr->msg_iovlen-1].iov_base)[0..];
  @ assigns ((char *) hdr->msg_control)[0..];
  @ assigns hdr->msg_controllen;
  @ assigns hdr->msg_flags;
*/
ssize_t recvmsg(int sockfd, struct msghdr *hdr, int flags);

/*@
requires \valid(((char*)buffer)+(0..length-1));
assigns \result, ((char*)buffer)[0..length-1] \from socket, length, flags;
ensures -1 <= \result <= length;
*/
ssize_t send(int socket, const void *buffer, size_t length, int flags);

/*@ //TODO
assigns \result, *message \from socket, *message, flags;
ensures -1 <= \result;
*/
ssize_t sendmsg(int socket, const struct msghdr *message, int flags);

/*@
requires \valid(((char*)buffer)+(0 .. length-1));
requires \valid(dest_addr);
assigns \result, ((char*)buffer)[0 .. length-1] \from socket, length, flags, *dest_addr, dest_len;
ensures -1 <= \result <= length;
*/
ssize_t sendto(int socket, const void *buffer, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len);

/*@
requires \valid((char *)option_value);
assigns \result \from socket, level, option_name, option_value, option_len;
ensures \result == -1 || \result == 0;
*/
int setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);

/*@
assigns \result \from socket, how;
ensures \result == -1 || \result == 0;
*/
int shutdown(int socket, int how);

/*@
assigns \result \from domain, type, protocol;
ensures \result >= -1;
*/
int socket(int domain, int type, int protocol);

/*@
assigns \result \from s;
ensures -1 <= \result <= 1;
*/
int sockatmark(int s);

/*@
requires \valid(socket_vector+(0..1));
assigns \result, socket_vector[0..1] \from domain, type, protocol;
ensures \result == -1 || \result == 0;
ensures \result == 0 ==> (socket_vector[0] >= 0 && socket_vector[1] >= 0);
*/
int socketpair(int domain, int type, int protocol, int socket_vector[2]);

/* GNU Extensions */

#define SO_SNDBUF 0x0400
#define SO_RCVBUF 0x0800
#define SO_STYLE 0x2000
#define SO_TYPE 0x4000

#define SOCK_NONBLOCK 1
#define SOCK_CLOEXEC  2

#define SO_EE_ORIGIN_NONE    0
#define SO_EE_ORIGIN_LOCAL   1
#define SO_EE_ORIGIN_ICMP    2
#define SO_EE_ORIGIN_ICMP6   3

#define SO_EE_OFFENDER(so_ee) __gt_fc_so_ee_offender(so_ee)

#define SHUT_RD   0
#define SHUT_WR   1
#define SHUT_RDWR 2

struct sock_extended_err {
    uint32_t ee_errno;
    uint8_t ee_origin;
    uint8_t ee_type;
    uint8_t ee_code;
    uint8_t ee_pad;
    uint32_t ee_info;
    uint32_t ee_data;
};

struct mmsghdr {
    struct msghdr msg_hdr;
    unsigned int  msg_len;
};

struct linger {
    int l_onoff;
    int l_linger;
};

struct osockaddr {
    unsigned short int sa_family;
    unsigned char sa_data[14];
};

/*@
requires address != \null ==> \valid(address);
requires address_len != \null ==> \valid(address_len);
requires address == \null <==> address_len == \null;
assigns \result, *address, *address_len \from socket, flags;
ensures \result >= -1;
*/
int accept4(int socket, struct sockaddr *address, socklen_t *address_len, int flags);

/*@
requires \valid(msgvec+(0..vlen-1));
requires timeout != \null ==> \valid_read(timeout);
assigns \result, msgvec[0..vlen-1];
ensures -1 <= \result <= vlen;
*/
int recvmmsg(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, unsigned int flags, struct timespec *timeout);

/*@
requires \valid(msgvec+(0..vlen-1));
assigns \result, msgvec[0..vlen-1];
ensures -1 <= \result <= vlen;
*/
int sendmmsg(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, unsigned int flags);

#endif
