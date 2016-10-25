/*
 * svc.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_SVC_H_
#define LIBC_RPC_SVC_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_fd_set_t.h"
#include "../poll.h"
#include "types.h"
#include "auth.h"
#include "rpc_msg.h"

#define svc_getcaller(x) (&(x)->xp_raddr)

#define svc_fds svc_fdset.fds_bits[0]

#define SVC_RECV(xprt, msg) (*(xprt)->xp_ops->xp_recv)((xprt), (msg))
#define svc_recv(xprt, msg) (*(xprt)->xp_ops->xp_recv)((xprt), (msg))

#define SVC_STAT(xprt) (*(xprt)->xp_ops->xp_stat)(xprt)
#define svc_stat(xprt) (*(xprt)->xp_ops->xp_stat)(xprt)

#define SVC_GETARGS(xprt, xargs, argsp) (*(xprt)->xp_ops->xp_getargs)((xprt), (xargs), (argsp))
#define svc_getargs(xprt, xargs, argsp) (*(xprt)->xp_ops->xp_getargs)((xprt), (xargs), (argsp))

#define SVC_REPLY(xprt, msg) (*(xprt)->xp_ops->xp_reply) ((xprt), (msg))
#define svc_reply(xprt, msg) (*(xprt)->xp_ops->xp_reply) ((xprt), (msg))

#define SVC_FREEARGS(xprt, xargs, argsp) (*(xprt)->xp_ops->xp_freeargs)((xprt), (xargs), (argsp))
#define svc_freeargs(xprt, xargs, argsp) (*(xprt)->xp_ops->xp_freeargs)((xprt), (xargs), (argsp))

#define SVC_DESTROY(xprt) (*(xprt)->xp_ops->xp_destroy)(xprt)
#define svc_destroy(xprt) (*(xprt)->xp_ops->xp_destroy)(xprt)

enum xprt_stat {
    XPRT_DIED,
    XPRT_MOREREQS,
    XPRT_IDLE
};

typedef struct SVCXPRT {
    int xp_sock;
    u_short xp_port;
    const struct xp_ops {
        bool_t (*xp_recv)(SVCXPRT *__xprt, struct rpc_msg *__msg);
        enum xprt_stat (*xp_stat)(SVCXPRT *__xprt);
        bool_t (*xp_getargs)(SVCXPRT *__xprt, xdrproc_t __xdr_args, caddr_t __args_ptr);
        bool_t (*xp_reply)(SVCXPRT *__xprt, struct rpc_msg *__msg);
        bool_t (*xp_freeargs)(SVCXPRT *__xprt, xdrproc_t __xdr_args, caddr_t __args_ptr);
        void (*xp_destroy)(SVCXPRT *__xprt);
    }*xp_ops;
    int xp_addrlen;
    struct sockaddr_in xp_raddr;
    struct opaque_auth xp_verf;
    caddr_t xp_p1;
    caddr_t xp_p2;
    char xp_pad[256];
} SVCXPRT;

struct svc_req {
    rpcprog_t rq_prog;
    rpcvers_t rq_vers;
    rpcproc_t rq_proc;
    struct opaque_auth rq_cred;
    caddr_t rq_clntcred;
    SVCXPRT *rq_xprt;
};

typedef void (*dispatch_fn_t) (struct svc_req*, SVCXPRT*);

extern struct pollfd *svc_pollfd;
extern int svc_max_pollfd;
extern fd_set svc_fdset;

extern bool_t svc_register(SVCXPRT *xprt, rpcprog_t prog, rpcvers_t vers, dispatch_fn_t dispatch, rpcprot_t protocol);
extern void svc_unregister(rpcprog_t prog, rpcvers_t vers);
extern void xprt_register(SVCXPRT *xprt);
extern void xprt_unregister(SVCXPRT *xprt);
extern bool_t svc_sendreply(SVCXPRT *xprt, xdrproc_t xdr_results, caddr_t xdr_location);
extern void svcerr_decode(SVCXPRT *xprt);
extern void svcerr_weakauth(SVCXPRT *xprt);
extern void svcerr_noproc(SVCXPRT *xprt);
extern void svcerr_progvers(SVCXPRT *xprt, rpcvers_t low_vers, rpcvers_t high_vers);
extern void svcerr_auth(SVCXPRT *xprt, enum auth_stat why);
extern void svcerr_noprog(SVCXPRT *xprt);
extern void svcerr_systemerr(SVCXPRT *xprt);
extern void svc_getreq(int rdfds);
extern void svc_getreq_common(const int fd);
extern void svc_getreqset(fd_set *readfds);
extern void svc_getreq_poll(struct pollfd *, const int);
extern void svc_exit(void);
extern void svc_run(void);
extern SVCXPRT *svcraw_create(void);
extern SVCXPRT *svcudp_create(int sock);
extern SVCXPRT *svcudp_bufcreate(int sock, u_int sendsz, u_int recvsz);
extern SVCXPRT *svctcp_create(int sock, u_int sendsize, u_int recvsize);
extern SVCXPRT *svcfd_create(int sock, u_int sendsize, u_int recvsize);
extern SVCXPRT *svcunix_create(int sock, u_int sendsize, u_int recvsize, char *path);

#endif /* LIBC_RPC_SVC_H_ */
