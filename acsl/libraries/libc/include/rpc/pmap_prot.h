/*
 * pmap_prot.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_PMAP_PROT_H_
#define LIBC_RPC_PMAP_PROT_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "types.h"
#include "xdr.h"

#define PMAPPORT         ((u_short)111)
#define PMAPPROG         ((u_long)100000)
#define PMAPVERS         ((u_long)2)
#define PMAPVERS_PROTO   ((u_long)2)
#define PMAPVERS_ORIG    ((u_long)1)
#define PMAPPROC_NULL    ((u_long)0)
#define PMAPPROC_SET     ((u_long)1)
#define PMAPPROC_UNSET   ((u_long)2)
#define PMAPPROC_GETPORT ((u_long)3)
#define PMAPPROC_DUMP    ((u_long)4)
#define PMAPPROC_CALLIT  ((u_long)5)

struct pmap {
    long unsigned pm_prog;
    long unsigned pm_vers;
    long unsigned pm_prot;
    long unsigned pm_port;
};

struct pmaplist {
    struct pmap pml_map;
    struct pmaplist *pml_next;
};

bool_t xdr_pmap(XDR *xdrs, struct pmap *regs);
bool_t xdr_pmaplist(XDR *xdrs, struct pmaplist **rp);

#endif /* LIBC_RPC_PMAP_PROT_H_ */
