/*
 * pmap_rmt.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_PMAP_RMT_H_
#define LIBC_RPC_PMAP_RMT_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__gt_fc_define_caddr_t.h"
#include "types.h"
#include "xdr.h"

struct rmtcallargs {
    u_long prog, vers, proc, arglen;
    caddr_t args_ptr;
    xdrproc_t xdr_args;
};

struct rmtcallres {
    u_long *port_ptr;
    u_long resultslen;
    caddr_t results_ptr;
    xdrproc_t xdr_results;
};

bool_t xdr_rmtcall_args(XDR *xdrs, struct rmtcallargs *crp);
bool_t xdr_rmtcallres(XDR *xdrs, struct rmtcallres *crp);

#endif /* LIBC_RPC_PMAP_RMT_H_ */
