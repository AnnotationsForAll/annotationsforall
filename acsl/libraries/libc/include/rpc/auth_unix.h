/*
 * auth_unix.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_AUTH_UNIX_H_
#define LIBC_RPC_AUTH_UNIX_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_uid_and_gid.h"
#include "types.h"
#include "auth.h"
#include "xdr.h"

#define MAX_MACHINE_NAME 255

#define NGRPS 16

struct authunix_parms {
    u_long aup_time;
    char *aup_machname;
    uid_t aup_uid;
    gid_t aup_gid;
    u_int aup_len;
    gid_t *aup_gids;
};

struct short_hand_verf {
    struct opaque_auth new_cred;
};

bool_t xdr_authunix_parms(XDR *xdrs, struct authunix_parms *p);

#endif /* LIBC_RPC_AUTH_UNIX_H_ */
