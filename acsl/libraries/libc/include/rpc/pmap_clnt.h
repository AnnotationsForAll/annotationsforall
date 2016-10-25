/*
 * pmap_clnt.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_PMAP_CLNT_H_
#define LIBC_RPC_PMAP_CLNT_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_timeval.h"
#include "../__gt_fc_define_caddr_t.h"
#include "../netinet/in.h"
#include "types.h"
#include "clnt.h"
#include "pmap_prot.h"

typedef bool_t (*resultproc_t)(caddr_t resp, struct sockaddr_in *raddr);

extern bool_t pmap_set(const u_long program, const u_long vers, int protocol, u_short port);
extern bool_t pmap_unset(const u_long program, const u_long vers);
extern struct pmaplist *pmap_getmaps(struct sockaddr_in *address);
extern enum clnt_stat pmap_rmtcall(struct sockaddr_in *addr, const u_long prog, const u_long vers, const u_long proc, xdrproc_t xdrargs, caddr_t argsp, xdrproc_t xdrres, caddr_t resp, struct timeval tout, u_long *port_ptr);
extern enum clnt_stat clnt_broadcast(const u_long prog, const u_long vers, const u_long proc, xdrproc_t xargs, caddr_t argsp, xdrproc_t xresults, caddr_t resultsp, resultproc_t eachresult);
extern u_short pmap_getport(struct sockaddr_in *address, const u_long program, const u_long version, u_int protocol);

#endif /* LIBC_RPC_PMAP_CLNT_H_ */
