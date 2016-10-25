/*
 * clnt.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_CLNT_H_
#define LIBC_RPC_CLNT_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_uid_and_gid.h"
#include "../__fc_define_timeval.h"
#include "../__gt_fc_define_caddr_t.h"
#include "../netinet/in.h"
#include "types.h"

#define RPC_PMAPFAILURE RPC_RPCBFAILURE

#define re_errno    ru.RE_errno
#define re_why      ru.RE_why
#define re_vers     ru.RE_vers
#define re_lb       ru.RE_lb

#define CLSET_TIMEOUT       1
#define CLGET_TIMEOUT       2
#define CLGET_SERVER_ADDR   3
#define CLSET_RETRY_TIMEOUT 4
#define CLGET_RETRY_TIMEOUT 5
#define CLGET_FD            6
#define CLGET_SVC_ADDR      7
#define CLSET_FD_CLOSE      8
#define CLSET_FD_NCLOSE     9
#define CLGET_XID           10
#define CLSET_XID           11
#define CLGET_VERS          12
#define CLSET_VERS          13
#define CLGET_PROG          14
#define CLSET_PROG          15
#define CLSET_SVC_ADDR      16
#define CLSET_PUSH_TIMOD    17
#define CLSET_POP_TIMOD     18

#define RPCTEST_PROGRAM         ((u_long)1)
#define RPCTEST_VERSION         ((u_long)1)
#define RPCTEST_NULL_PROC       ((u_long)2)
#define RPCTEST_NULL_BATCH_PROC ((u_long)3)

#define NULLPROC ((u_long)0)

#define CLNT_CALL(rh, proc, xargs, argsp, xres, resp, secs) ((*(rh)->cl_ops->cl_call)(rh, proc, xargs, argsp, xres, resp, secs))
#define clnt_call(rh, proc, xargs, argsp, xres, resp, secs) ((*(rh)->cl_ops->cl_call)(rh, proc, xargs, argsp, xres, resp, secs))

#define CLNT_ABORT(rh) ((*(rh)->cl_ops->cl_abort)(rh))
#define clnt_abort(rh) ((*(rh)->cl_ops->cl_abort)(rh))

#define CLNT_GETERR(rh,errp) ((*(rh)->cl_ops->cl_geterr)(rh, errp))
#define clnt_geterr(rh,errp) ((*(rh)->cl_ops->cl_geterr)(rh, errp))

#define CLNT_FREERES(rh,xres,resp) ((*(rh)->cl_ops->cl_freeres)(rh,xres,resp))
#define clnt_freeres(rh,xres,resp) ((*(rh)->cl_ops->cl_freeres)(rh,xres,resp))

#define CLNT_CONTROL(cl,rq,in) ((*(cl)->cl_ops->cl_control)(cl,rq,in))
#define clnt_control(cl,rq,in) ((*(cl)->cl_ops->cl_control)(cl,rq,in))

#define CLNT_DESTROY(rh) ((*(rh)->cl_ops->cl_destroy)(rh))
#define clnt_destroy(rh) ((*(rh)->cl_ops->cl_destroy)(rh))

#define UDPMSGSIZE      8800
#define RPCSMALLMSGSIZE 400

enum clnt_stat {
    RPC_SUCCESS = 0,
    RPC_CANTENCODEARGS = 1,
    RPC_CANTDECODERES = 2,
    RPC_CANTSEND = 3,
    RPC_CANTRECV = 4,
    RPC_TIMEDOUT = 5,
    RPC_VERSMISMATCH = 6,
    RPC_AUTHERROR = 7,
    RPC_PROGUNAVAIL = 8,
    RPC_PROGVERSMISMATCH = 9,
    RPC_PROCUNAVAIL = 10,
    RPC_CANTDECODEARGS = 11,
    RPC_SYSTEMERROR = 12,
    RPC_NOBROADCAST = 21,
    RPC_UNKNOWNHOST = 13,
    RPC_UNKNOWNPROTO = 17,
    RPC_UNKNOWNADDR = 19,
    RPC_RPCBFAILURE = 14,
    RPC_PROGNOTREGISTERED = 15,
    RPC_N2AXLATEFAILURE = 22,
    RPC_FAILED = 16,
    RPC_INTR = 18,
    RPC_TLIERROR = 20,
    RPC_UDERROR = 23,
    RPC_INPROGRESS = 24,
    RPC_STALERACHANDLE = 25
};

struct rpc_err {
    enum clnt_stat re_status;
    union {
        int RE_errno;
        enum auth_stat RE_why;
        struct {
            u_long low;
            u_long high;
        } RE_vers;
        struct {
            long s1;
            long s2;
        } RE_lb;
    } ru;
};

typedef struct CLIENT {
    AUTH *cl_auth;
    struct clnt_ops {
        enum clnt_stat (*cl_call)(CLIENT *, u_long, xdrproc_t, caddr_t, xdrproc_t, caddr_t, struct timeval);
        void (*cl_abort)(void);
        void (*cl_geterr)(CLIENT *, struct rpc_err *);
        bool_t (*cl_freeres)(CLIENT *, xdrproc_t, caddr_t);
        void (*cl_destroy)(CLIENT *);
        bool_t (*cl_control)(CLIENT *, int, char *);
    }*cl_ops;
    caddr_t cl_private;
} CLIENT;

struct rpc_createerr {
    enum clnt_stat cf_stat;
    struct rpc_err cf_error;
};

extern struct rpc_createerr rpc_createerr;

extern CLIENT *clntraw_create(const u_long prog, const u_long vers);
extern CLIENT *clnt_create(const char *host, const u_long prog, const u_long vers, const char *prot);
extern CLIENT *clnttcp_create(struct sockaddr_in *raddr, u_long prog, u_long version, int *sockp, u_int sendsz, u_int recvsz);
extern CLIENT *clntudp_create(struct sockaddr_in *raddr, u_long program, u_long version, struct timeval wait_resend, int *sockp);
extern CLIENT *clntudp_bufcreate(struct sockaddr_in *raddr, u_long program, u_long version, struct timeval wait_resend, int *sockp, u_int sendsz, u_int recvsz);
extern CLIENT *clntunix_create(struct sockaddr_un *raddr, u_long program, u_long version, int *sockp, u_int sendsz, u_int recvsz);
extern int callrpc(const char *host, const u_long prognum, const u_long versnum, const u_long procnum, const xdrproc_t inproc, const char *in, const xdrproc_t outproc, char *out);
extern void clnt_pcreateerror(const char *msg);
extern char *clnt_spcreateerror(const char *msg);
extern void clnt_perrno(enum clnt_stat num);
extern void clnt_perror(CLIENT *clnt, const char *msg);
extern char *clnt_sperror(CLIENT *clnt, const char *msg);
extern char *clnt_sperrno(enum clnt_stat num);
extern int getrpcport(const char * host, u_long prognum, u_long versnum, u_int proto);
extern void get_myaddress(struct sockaddr_in *);

#endif /* LIBC_RPC_CLNT_H_ */
