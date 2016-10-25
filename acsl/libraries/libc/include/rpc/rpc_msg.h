/*
 * rpc_msg.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_RPC_MSG_H_
#define LIBC_RPC_RPC_MSG_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__gt_fc_define_caddr_t.h"
#include "types.h"
#include "auth.h"
#include "xdr.h"

#define RPC_MSG_VERSION  ((u_long) 2)
#define RPC_SERVICE_PORT ((u_short) 2048)

#define ar_results ru.AR_results
#define ar_vers    ru.AR_versions

#define rj_vers ru.RJ_versions
#define rj_why  ru.RJ_why

#define rp_acpt ru.RP_ar
#define rp_rjct ru.RP_dr

#define rm_call  ru.RM_cmb
#define rm_reply ru.RM_rmb

#define acpted_rply ru.RM_rmb.ru.RP_ar
#define rjcted_rply ru.RM_rmb.ru.RP_dr

enum msg_type {
    CALL = 0,
    REPLY = 1
};

enum reply_stat {
    MSG_ACCEPTED = 0,
    MSG_DENIED = 1
};

enum accept_stat {
    SUCCESS = 0,
    PROG_UNAVAIL = 1,
    PROG_MISMATCH = 2,
    PROC_UNAVAIL = 3,
    GARBAGE_ARGS = 4,
    SYSTEM_ERR = 5
};

enum reject_stat {
    RPC_MISMATCH = 0,
    AUTH_ERROR = 1
};

struct accepted_reply {
    struct opaque_auth ar_verf;
    enum accept_stat ar_stat;
    union {
        struct {
            u_long low;
            u_long high;
        } AR_versions;
        struct {
            caddr_t where;
            xdrproc_t proc;
        } AR_results;
    } ru;
};

struct rejected_reply {
    enum reject_stat rj_stat;
    union {
        struct {
            u_long low;
            u_long high;
        } RJ_versions;
        enum auth_stat RJ_why;
    } ru;
};

struct reply_body {
    enum reply_stat rp_stat;
    union {
        struct accepted_reply RP_ar;
        struct rejected_reply RP_dr;
    } ru;
};

struct call_body {
    u_long cb_rpcvers;
    u_long cb_prog;
    u_long cb_vers;
    u_long cb_proc;
    struct opaque_auth cb_cred;
    struct opaque_auth cb_verf;
};

struct rpc_msg {
    u_long rm_xid;
    enum msg_type rm_direction;
    union {
        struct call_body RM_cmb;
        struct reply_body RM_rmb;
    } ru;
};

extern bool_t xdr_callmsg(XDR *xdrs, struct rpc_msg *cmsg);
extern bool_t xdr_callhdr(XDR *xdrs, struct rpc_msg *cmsg);
extern bool_t xdr_replymsg(XDR *xdrs, struct rpc_msg *rmsg);
extern void _seterr_reply(struct rpc_msg *msg, struct rpc_err *error);

#endif /* LIBC_RPC_RPC_MSG_H_ */
