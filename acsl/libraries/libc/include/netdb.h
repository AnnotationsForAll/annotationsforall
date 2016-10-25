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

#ifndef __FC_NETDB
#define __FC_NETDB
#include "features.h"
#include "__fc_define_timespec.h"
#include "__fc_define_size_t.h"
#include "__gt_fc_argv_axiomatic.h"
#include "signal.h"
#include "netinet/in.h"
#include "inttypes.h"
#include "rpc/netdb.h"

__BEGIN_DECLS

struct hostent
{
  char *h_name;
  char **h_aliases;
  int h_addrtype;
  int h_length;
  char **h_addr_list;
};

#define h_addr h_addr_list[0]

struct netent
{
  char *n_name;
  char **n_aliases;
  int n_addrtype;
  uint32_t n_net;
};
struct protoent
{
  char *p_name;
  char **p_aliases;
  int p_proto;
};
struct servent
{
  char *s_name;
  char **s_aliases;
  int s_port;
  char *s_proto;
};

#define IPPORT_RESERVED 1024

extern int __gt_fc_h_errno;
#define h_errno __gt_fc_h_errno

# define HOST_NOT_FOUND 1
# define TRY_AGAIN      2
# define NO_RECOVERY    3
# define NO_DATA        4

#define SCOPE_DELIMITER '%'

struct addrinfo
{
  int ai_flags;
  int ai_family;
  int ai_socktype;
  int ai_protocol;
  socklen_t ai_addrlen;
  struct sockaddr *ai_addr;
  char *ai_canonname;
  struct addrinfo *ai_next;
};

# define AI_PASSIVE      0x0001
# define AI_CANONNAME    0x0002
# define AI_NUMERICHOST  0x0004
# define AI_NUMERICSERV  0x0400
# define AI_V4MAPPED     0x0008
# define AI_ALL          0x0010
# define AI_ADDRCONFIG   0x0020
# define NI_NUMERICHOST  1
# define NI_NUMERICSERV  2
# define NI_NOFQDN       4
# define NI_NAMEREQD     8
# define NI_DGRAM        16
# define NI_NUMERICSCOPE 32
# define EAI_BADFLAGS    -1
# define EAI_NONAME      -2
# define EAI_AGAIN       -3
# define EAI_FAIL        -4
# define EAI_FAMILY      -6
# define EAI_SOCKTYPE    -7
# define EAI_SERVICE     -8
# define EAI_MEMORY      -10
# define EAI_SYSTEM      -11
# define EAI_OVERFLOW    -12

/*@
assigns \nothing;
*/
void endhostent(void);

/*@
assigns \result \from \nothing;
ensures \result != \null ==> \valid(\result);
*/
struct hostent *gethostent(void);

/*@
assigns \nothing;
*/
void sethostent(int stayopen);

/*@
assigns \nothing;
*/
void endnetent(void);

/*@
assigns \result \from net, type;
ensures \result != \null ==> \valid(\result);
*/
struct netent *getnetbyaddr(uint32_t net, int type);

/*@
requires \valid(name);
assigns \result \from name[..];
ensures \result != \null ==> \valid(\result);
*/
struct netent *getnetbyname(const char *name);

/*@
assigns \result \from \nothing;
ensures \result != \null ==> \valid(\result);
*/
struct netent *getnetent(void);

/*@
assigns \nothing;
*/
void setnetent(int stayopen);

/*@
assigns \nothing;
*/
void endprotoent(void);

/*@
requires \valid(name);
assigns \result \from name[..];
ensures \result != \null ==> \valid(\result);
*/
struct protoent *getprotobyname(const char *name);

/*@
assigns \result \from proto;
ensures \result != \null ==> \valid(\result);
*/
struct protoent *getprotobynumber(int proto);

/*@
assigns \result \from \nothing;
ensures \result != \null ==> \valid(\result);
*/
struct protoent *getprotoent(void);

/*@
assigns \nothing;
*/
void setprotoent(int stayopen);

/*@
assigns \nothing;
*/
void endservent(void);

/*@
requires \valid(name) && \valid(proto);
assigns \result \from name[..], proto[..];
ensures \result != \null ==> \valid(\result);
*/
struct servent *getservbyname(const char *name, const char *proto);

/*@
requires \valid(proto);
assigns \result \from proto[..];
ensures \result != \null ==> \valid(\result);
*/
struct servent *getservbyport(int port, const char *proto);

/*@
assigns \result \from \nothing;
ensures \result != \null ==> \valid(\result);
*/
struct servent *getservent(void);

/*@
assigns \nothing;
*/
void setservent(int stayopen);

/*@
axiomatic AddrInfoOpen {
    logic boolean is_addrinfo_open{L}(struct addrinfo * info) reads *info;
}
*/

/*@
requires is_addrinfo_open(ai);
assigns *ai \from \nothing;
ensures !is_addrinfo_open(ai);
*/
void freeaddrinfo(struct addrinfo *ai);

/*@
requires \valid(nodename) || \valid(servname);
requires nodename != \null ==> \valid(nodename);
requires servname != \null ==> \valid(servname);
requires hints != \null ==> \valid(hints);
requires \valid(res);
assigns \result, *res \from nodename[..], servname[..], *hints;
ensures *res != \null ==> \valid(*res);
ensures *res != \null ==> is_addrinfo_open(*res);
ensures \result == 0 ? \valid(*res) : *res == \null;
*/
int getaddrinfo(const char *restrict nodename, const char *restrict servname, const struct addrinfo *restrict hints, struct addrinfo **restrict res);

/*@
assigns \result \from ecode;
ensures \valid(\result);
*/
const char *gai_strerror(int ecode);

/*@
requires \valid(sa);
requires node != \null && nodelen != 0 ==> \valid(service+(0..nodelen-1));
requires service != \null && servicelen != 0 ==> \valid(service+(0..servicelen-1));
assigns \result, node[0..nodelen-1], service[0..servicelen-1] \from *sa, salen, flags;
*/
int getnameinfo(const struct sockaddr *restrict sa, socklen_t salen, char *restrict node, socklen_t nodelen, char *restrict service, socklen_t servicelen, int flags);

/* GNU Extensions */

#define GAI_WAIT   0
#define GAI_NOWAIT 1


struct gaicb {
    const char *ar_name;
    const char *ar_service;
    const struct addrinfo *ar_request;
    struct addrinfo *ar_result;
};

/*@
requires \valid(name);
assigns h_errno, \result \from name[0..];
ensures \result != \null ==> \valid(\result);
ensures \result == \null ? h_errno != 0 : h_errno == \old(h_errno);
*/
struct hostent * gethostbyname(const char *name);

/*@
requires \valid(name);
assigns h_errno, \result \from name[0..], af;
ensures \result != \null ==> \valid(\result);
ensures \result == \null ? h_errno != 0 : h_errno == \old(h_errno);
*/
struct hostent * gethostbyname2(const char *name, int af);

/*@
requires \valid(((char*)addr)+(0..length-1));
assigns h_errno, \result \from ((char*)addr)[0..length-1], length, format;
ensures \result != \null ==> \valid(\result);
ensures \result == \null ? h_errno != 0 : h_errno == \old(h_errno);
*/
struct hostent * gethostbyaddr(const void *addr, socklen_t length, int format);

/*@
requires \valid(name);
requires \valid(result_buf);
requires \valid(buf+(0..buflen));
requires \valid(result);
requires \valid(h_errnop);
assigns *result_buf, *result, buf[0..buflen], *h_errnop \from name[0..];
ensures *result != \null ==> \valid(*result);
ensures \result == 0 <==> *result != \null;
ensures *result == \null ? *h_errnop != 0 : *h_errnop == \old(*h_errnop);
*/
int gethostbyname_r(const char *restrict name, struct hostent *restrict result_buf, char *restrict buf, size_t buflen, struct hostent **restrict result, int *restrict h_errnop);

/*@
requires \valid(name);
requires \valid(result_buf);
requires \valid(buf+(0..buflen));
requires \valid(result);
requires \valid(h_errnop);
assigns *result_buf, *result, buf[0..buflen], *h_errnop \from name[0..], af;
ensures *result != \null ==> \valid(*result);
ensures \result == 0 <==> *result != \null;
ensures *result == \null ? *h_errnop != 0 : *h_errnop == \old(*h_errnop);
*/
int gethostbyname2_r(const char *name, int af, struct hostent *restrict result_buf, char *restrict buf, size_t buflen, struct hostent **restrict result, int *restrict h_errnop);

/*@
requires \valid(((char*)addr)+(0..length-1));
requires \valid(result_buf);
requires \valid(buf+(0..buflen));
requires \valid(result);
requires \valid(h_errnop);
assigns *result_buf, *result, buf[0..buflen], *h_errnop \from ((char*)addr)[0..length-1], format;
ensures *result != \null ==> \valid(*result);
ensures \result == 0 <==> *result != \null;
ensures *result == \null ? *h_errnop != 0 : *h_errnop == \old(*h_errnop);
*/
int gethostbyaddr_r(const void *addr, socklen_t length, int format, struct hostent *restrict result_buf, char *restrict buf, size_t buflen, struct hostent **restrict result, int *restrict h_errnop);

/*@
requires netgroup != \null ==> \valid(netgroup);
requires host != \null ==> \valid(host);
requires user != \null ==> \valid(user);
requires domain != \null ==> \valid(domain);
assigns \result \from netgroup[0..], host[0..], user[0..], domain[0..];
ensures \result == 1 || \result == 0;
*/
int innetgr (const char *netgroup, const char *host, const char *user, const char *domain);

/*@
axiomatic AsyncAddrInfo {
    logic boolean is_getaddrinfo_a_in_progress(struct gaicb ** list, int nitems) reads list[0..nitems-1];
}
*/

/*@
requires \valid(list+(0..nitems-1));
requires sevp != \null ==> \valid(sevp);
requires \forall int i; 0 <= i < nitems ==> list[i] != \null ==> \valid(list[i]);
requires \forall int i; 0 <= i < nitems ==> list[i] != \null ==> \valid(list[i]->ar_name) || \valid(list[i]->ar_service);
requires \forall int i; 0 <= i < nitems ==> list[i] != \null ==> list[i]->ar_name != \null ==> \valid(list[i]->ar_name);
requires \forall int i; 0 <= i < nitems ==> list[i] != \null ==> list[i]->ar_service != \null ==> \valid(list[i]->ar_service);
requires \forall int i; 0 <= i < nitems ==> list[i] != \null ==> list[i]->ar_request != \null ==> \valid(list[i]->ar_request);
assigns \result, list[0..nitems-1]->ar_result;
ensures \result == 0 ==> \forall int i; 0 <= i < nitems ==> list[i] != \null ==> list[i]->ar_result != \null ==> \valid(list[i]->ar_result);
ensures \result == 0 ==> is_getaddrinfo_a_in_progress((struct gaicb **) list, nitems);
*/
int getaddrinfo_a(int mode, struct gaicb *list[], int nitems, struct sigevent *sevp);

/*@
requires \valid(list+(0..nitems-1));
requires is_getaddrinfo_a_in_progress((struct gaicb **) list, nitems);
requires timeout != \null ==> \valid_read(timeout);
assigns \result;
*/
int gai_suspend(const struct gaicb * const list[], int nitems, const struct timespec *timeout);

/*@
requires \valid_read(req);
assigns \result;
ensures \result == 0 ==> \valid(req->ar_result);
*/
int gai_error(struct gaicb *req);

/*@
requires req != \null ==> \valid_read(req);
assigns \result;
*/
int gai_cancel(struct gaicb *req);

/*@
axiomatic DynAllocHostent {
    logic boolean is_dyn_alloc_hostent_open(struct hostent * ip) reads *ip;
}
*/

/*@
requires \valid_read(name);
requires \valid(error_num);
assigns \result, *error_num;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> \valid(\result->h_name);
ensures \result != \null ==> \exists size_t i; 0 <= i ==> argv_count_pred(\result->h_aliases, i);
ensures \result != \null ==> \exists size_t i; 0 <= i ==> argv_count_pred(\result->h_addr_list, i);
ensures \result != \null ==> \forall size_t i; 0 <= i < argv_count(\result->h_addr_list) ==> \valid(\result->h_addr_list[i]+(0..\result->h_length-1));
ensures \result != \null ==> is_dyn_alloc_hostent_open(\result);
*/
struct hostent *getipnodebyname(const char *name, int af, int flags, int *error_num);

/*@
requires \valid_read(((char*)addr)+(0..len-1));
requires \valid(error_num);
assigns \result, *error_num;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> \valid(\result->h_name);
ensures \result != \null ==> \exists size_t i; 0 <= i ==> argv_count_pred(\result->h_aliases, i);
ensures \result != \null ==> \exists size_t i; 0 <= i ==> argv_count_pred(\result->h_addr_list, i);
ensures \result != \null ==> \forall size_t i; 0 <= i < argv_count(\result->h_addr_list) ==> \valid(\result->h_addr_list[i]+(0..\result->h_length-1));
ensures \result != \null ==> is_dyn_alloc_hostent_open(\result);
*/
struct hostent *getipnodebyaddr(const void *addr, size_t len, int af, int *error_num);

/*@
requires \valid(ip);
requires is_dyn_alloc_hostent_open(ip);
assigns *ip;
ensures !is_dyn_alloc_hostent_open(ip);
*/
void freehostent(struct hostent *ip);

/*@
requires \valid_read(s);
assigns \nothing;
*/
void herror(const char *s);

/*@
assigns \result;
ensures \result != \null && \valid_read(\result);
*/
const char *hstrerror(int err);

/*@
requires \valid(ahost);
requires \valid_read(*ahost);
requires \valid_read(locuser);
requires \valid_read(remuser);
requires \valid_read(cmd);
requires fd2p != \null ==> \valid(fd2p);
assigns \result, *ahost, *fd2p;
ensures \result >= -1;
ensures \result == -1 ? *ahost == \old(*ahost) : \valid_read(*ahost);
ensures fd2p != \null ==> \result != -1 ==> *fd2p >= 0;
*/
int rcmd(char **ahost, unsigned short inport, const char *locuser, const char *remuser, const char *cmd, int *fd2p);

/*@
requires \valid(port);
assigns \result, *port;
ensures \result >= -1;
ensures \result == -1 ? *port == \old(*port) : *port >= 0;
*/
int rresvport(int *port);

/*@
requires \valid_read(ruser);
requires \valid_read(luser);
assigns \result;
ensures \result == 0 || \result == -1;
*/
int iruserok(uint32_t raddr, int superuser, const char *ruser, const char *luser);

/*@
requires \valid_read(ruser);
requires \valid_read(luser);
requires \valid_read(rhost);
assigns \result;
ensures \result == 0 || \result == -1;
*/
int ruserok(const char *rhost, int superuser, const char *ruser, const char *luser);

/*@
requires \valid(ahost);
requires \valid_read(*ahost);
requires \valid_read(locuser);
requires \valid_read(remuser);
requires \valid_read(cmd);
requires fd2p != \null ==> \valid(fd2p);
assigns \result, *ahost, *fd2p;
ensures \result >= -1;
ensures \result == -1 ? *ahost == \old(*ahost) : \valid_read(*ahost);
ensures fd2p != \null ==> \result != -1 ==> *fd2p >= 0;
*/
int rcmd_af(char **ahost, unsigned short inport, const char *locuser, const char *remuser, const char *cmd, int *fd2p, sa_family_t af);

/*@
requires \valid(port);
assigns \result, *port;
ensures \result >= -1;
ensures \result == -1 ? *port == \old(*port) : *port >= 0;
*/
int rresvport_af(int *port, sa_family_t af);

/*@
requires \valid_read(ruser);
requires \valid_read(luser);
assigns \result;
ensures \result == 0 || \result == -1;
*/
int iruserok_af(const void *raddr, int superuser, const char *ruser, const char *luser, sa_family_t af);

/*@
requires \valid_read(ruser);
requires \valid_read(luser);
requires \valid_read(rhost);
assigns \result;
ensures \result == 0 || \result == -1;
*/
int ruserok_af(const char *rhost, int superuser, const char *ruser, const char *luser, sa_family_t af);

/*@
requires \valid(ahost);
requires \valid_read(*ahost);
requires \valid_read(user);
requires \valid_read(passwd);
requires \valid_read(cmd);
requires fd2p != \null ==> \valid(fd2p);
assigns \result, *ahost, *fd2p;
ensures \result >= -1;
ensures \result == -1 ? *ahost == \old(*ahost) : \valid_read(*ahost);
ensures fd2p != \null ==> \result != -1 ==> *fd2p >= 0;
*/
int rexec(char **ahost, int inport, const char *user, const char *passwd, const char *cmd, int *fd2p);

/*@
requires \valid(ahost);
requires \valid_read(*ahost);
requires \valid_read(user);
requires \valid_read(passwd);
requires \valid_read(cmd);
requires fd2p != \null ==> \valid(fd2p);
assigns \result, *ahost, *fd2p;
ensures \result >= -1;
ensures \result == -1 ? *ahost == \old(*ahost) : \valid_read(*ahost);
ensures fd2p != \null ==> \result != -1 ==> *fd2p >= 0;
*/
int rexec_af(char **ahost, int inport, const char *user, const char *passwd, const char *cmd, int *fd2p, sa_family_t af);

/*@
requires \valid_read(netgroup);
assigns \result;
*/
int setnetgrent(const char *netgroup);

/*@
assigns \nothing;
*/
void endnetgrent(void);

/*@
requires \valid(host);
requires \valid(user);
requires \valid(domain);
assigns \result, *host, *user, *domain;
ensures \result == 1 || \result == 0;
ensures \result == 0 ==> *host != \null ==> \valid(*host);
ensures \result == 0 ==> *user != \null ==> \valid(*user);
ensures \result == 0 ==> *domain != \null ==> \valid(*domain);
*/
int getnetgrent(char **host, char **user, char **domain);

/*@
requires \valid(host);
requires \valid(user);
requires \valid(domain);
requires \valid(buf+(0..buflen-1));
assigns \result, *host, *user, *domain, buf[0..buflen-1];
ensures \result == 0 ==> *host != \null ==> \valid(*host);
ensures \result == 0 ==> *user != \null ==> \valid(*user);
ensures \result == 0 ==> *domain != \null ==> \valid(*domain);
*/
int getnetgrent_r(char **host, char **user, char **domain, char *buf, size_t buflen);

/*@
requires \valid(result_buf);
requires \valid(buf+(0..buflen-1));
requires \valid(result);
requires \valid(h_errnop);
assigns \result, *result_buf, buf[0..buflen-1], *result, *h_errnop;
ensures \result == *h_errnop;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ==> *result == \null;
*/
int getnetent_r(struct netent *result_buf, char *buf, size_t buflen, struct netent **result, int *h_errnop);

/*@
requires \valid(result_buf);
requires \valid(buf+(0..buflen-1));
requires \valid(result);
requires \valid(h_errnop);
assigns \result, *result_buf, buf[0..buflen-1], *result, *h_errnop;
ensures \result == *h_errnop;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ==> *result == \null;
*/
int getnetbyaddr_r(uint32_t net, int type, struct netent *restrict result_buf, char *restrict buf, size_t buflen, struct netent **restrict result, int *restrict h_errnop);

/*@
requires \valid_read(name);
requires \valid(result_buf);
requires \valid(buf+(0..buflen-1));
requires \valid(result);
requires \valid(h_errnop);
assigns \result, *result_buf, buf[0..buflen-1], *result, *h_errnop;
ensures \result == *h_errnop;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ==> *result == \null;
*/
int getnetbyname_r(const char *restrict name, struct netent *restrict result_buf, char *restrict buf, size_t buflen, struct netent **restrict result, int *restrict h_errnop);

/*@
requires \valid(result_buf);
requires \valid(buf+(0..buflen-1));
requires \valid(result);
assigns \result, *result_buf, buf[0..buflen-1], *result;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ==> *result == \null;
*/
int getprotoent_r(struct protoent *restrict result_buf, char *restrict buf, size_t buflen, struct protoent **restrict result);

/*@
requires \valid_read(name);
requires \valid(result_buf);
requires \valid(buf+(0..buflen-1));
requires \valid(result);
assigns \result, *result_buf, buf[0..buflen-1], *result;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ==> *result == \null;
*/
int getprotobyname_r(const char *restrict name, struct protoent *restrict result_buf, char *restrict buf, size_t buflen, struct protoent **restrict result);

/*@
requires \valid(result_buf);
requires \valid(buf+(0..buflen-1));
requires \valid(result);
assigns \result, *result_buf, buf[0..buflen-1], *result;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ==> *result == \null;
*/
int getprotobynumber_r(int proto, struct protoent *restrict result_buf, char *restrict buf, size_t buflen, struct protoent **restrict result);

/*@
requires \valid(result_buf);
requires \valid(buf+(0..buflen-1));
requires \valid(result);
assigns \result, *result_buf, buf[0..buflen-1], *result;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ==> *result == \null;
*/
int getservent_r(struct servent *restrict result_buf, char *restrict buf, size_t buflen, struct servent **restrict result);

/*@
requires \valid_read(name);
requires \valid_read(proto);
requires \valid(result_buf);
requires \valid(buf+(0..buflen-1));
requires \valid(result);
assigns \result, *result_buf, buf[0..buflen-1], *result;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ==> *result == \null;
*/
int getservbyname_r(const char *restrict name, const char *restrict proto, struct servent *restrict result_buf, char *restrict buf, size_t buflen, struct servent **restrict result);

/*@
requires \valid_read(proto);
requires \valid(result_buf);
requires \valid(buf+(0..buflen-1));
requires \valid(result);
assigns \result, *result_buf, buf[0..buflen-1], *result;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ==> *result == \null;
*/
int getservbyport_r(int port, const char *restrict proto, struct servent *restrict result_buf, char *restrict buf, size_t buflen, struct servent **restrict result);

__END_DECLS

#endif

