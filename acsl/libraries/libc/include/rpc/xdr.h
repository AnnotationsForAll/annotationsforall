/*
 * xdr.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_XDR_H_
#define LIBC_RPC_XDR_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__gt_fc_define_caddr_t.h"
#include "../__fc_define_file.h"
#include "types.h"

#define BYTES_PER_XDR_UNIT  (4)

#define NULL_xdrproc_t ((xdrproc_t)0)

#define MAX_NETOBJ_SZ 1024

#define RNDUP(x) (((x) + BYTES_PER_XDR_UNIT - 1) & ~(BYTES_PER_XDR_UNIT - 1))

#define XDR_GETINT32(xdrs, int32p) (*(xdrs)->x_ops->x_getint32)(xdrs, int32p)
#define xdr_getint32(xdrs, int32p) (*(xdrs)->x_ops->x_getint32)(xdrs, int32p)

#define XDR_PUTINT32(xdrs, int32p) (*(xdrs)->x_ops->x_putint32)(xdrs, int32p)
#define xdr_putint32(xdrs, int32p) (*(xdrs)->x_ops->x_putint32)(xdrs, int32p)

#define XDR_GETLONG(xdrs, longp) (*(xdrs)->x_ops->x_getlong)(xdrs, longp)
#define xdr_getlong(xdrs, longp) (*(xdrs)->x_ops->x_getlong)(xdrs, longp)

#define XDR_PUTLONG(xdrs, longp) (*(xdrs)->x_ops->x_putlong)(xdrs, longp)
#define xdr_putlong(xdrs, longp) (*(xdrs)->x_ops->x_putlong)(xdrs, longp)

#define XDR_GETBYTES(xdrs, addr, len) (*(xdrs)->x_ops->x_getbytes)(xdrs, addr, len)
#define xdr_getbytes(xdrs, addr, len) (*(xdrs)->x_ops->x_getbytes)(xdrs, addr, len)

#define XDR_PUTBYTES(xdrs, addr, len) (*(xdrs)->x_ops->x_putbytes)(xdrs, addr, len)
#define xdr_putbytes(xdrs, addr, len) (*(xdrs)->x_ops->x_putbytes)(xdrs, addr, len)

#define XDR_GETPOS(xdrs) (*(xdrs)->x_ops->x_getpostn)(xdrs)
#define xdr_getpos(xdrs) (*(xdrs)->x_ops->x_getpostn)(xdrs)

#define XDR_SETPOS(xdrs, pos) (*(xdrs)->x_ops->x_setpostn)(xdrs, pos)
#define xdr_setpos(xdrs, pos) (*(xdrs)->x_ops->x_setpostn)(xdrs, pos)

#define XDR_INLINE(xdrs, len) (*(xdrs)->x_ops->x_inline)(xdrs, len)
#define xdr_inline(xdrs, len) (*(xdrs)->x_ops->x_inline)(xdrs, len)

#define XDR_DESTROY(xdrs)                   \
    do {                            \
        if ((xdrs)->x_ops->x_destroy)           \
            (*(xdrs)->x_ops->x_destroy)(xdrs);  \
    } while (0)
#define xdr_destroy(xdrs)                   \
    do {                            \
        if ((xdrs)->x_ops->x_destroy)           \
            (*(xdrs)->x_ops->x_destroy)(xdrs);  \
    } while (0)

#define IXDR_GET_INT32(buf)      ((int32_t)ntohl((uint32_t)*(buf)++))
#define IXDR_PUT_INT32(buf, v)   (*(buf)++ = (int32_t)htonl((uint32_t)(v)))
#define IXDR_GET_U_INT32(buf)    ((uint32_t)IXDR_GET_INT32(buf))
#define IXDR_PUT_U_INT32(buf, v) IXDR_PUT_INT32(buf, (int32_t)(v))

#define IXDR_GET_LONG(buf)      ((long)IXDR_GET_U_INT32(buf))
#define IXDR_PUT_LONG(buf, v)   ((long)IXDR_PUT_INT32(buf, (long)(v)))
#define IXDR_GET_U_LONG(buf)    ((u_long)IXDR_GET_LONG(buf))
#define IXDR_PUT_U_LONG(buf, v) IXDR_PUT_LONG(buf, (long)(v))

#define IXDR_GET_BOOL(buf)    ((bool_t)IXDR_GET_LONG(buf))
#define IXDR_GET_ENUM(buf, t) ((t)IXDR_GET_LONG(buf))
#define IXDR_GET_SHORT(buf)   ((short)IXDR_GET_LONG(buf))
#define IXDR_GET_U_SHORT(buf) ((u_short)IXDR_GET_LONG(buf))

#define IXDR_PUT_BOOL(buf, v)    IXDR_PUT_LONG(buf, (long)(v))
#define IXDR_PUT_ENUM(buf, v)    IXDR_PUT_LONG(buf, (long)(v))
#define IXDR_PUT_SHORT(buf, v)   IXDR_PUT_LONG(buf, (long)(v))
#define IXDR_PUT_U_SHORT(buf, v) IXDR_PUT_LONG(buf, (long)(v))

enum xdr_op {
    XDR_ENCODE = 0,
    XDR_DECODE = 1,
    XDR_FREE = 2
};

typedef bool_t (*xdrproc_t)(XDR *, void *, ...);

typedef struct XDR {
    enum xdr_op x_op;
    struct xdr_ops {
        bool_t (*x_getlong)(XDR *__xdrs, long *__lp);
        bool_t (*x_putlong)(XDR *__xdrs, const long *__lp);
        bool_t (*x_getbytes)(XDR *__xdrs, caddr_t __addr, u_int __len);
        bool_t (*x_putbytes)(XDR *__xdrs, const char *__addr, u_int __len);
        u_int (*x_getpostn)(const XDR *__xdrs);
        bool_t (*x_setpostn)(XDR *__xdrs, u_int __pos);
        int32_t *(*x_inline)(XDR *__xdrs, u_int __len);
        void (*x_destroy)(XDR *__xdrs);
        bool_t (*x_getint32)(XDR *__xdrs, int32_t *__ip);
        bool_t (*x_putint32)(XDR *__xdrs, const int32_t *__ip);
    } *x_ops;
    caddr_t x_public;
    caddr_t x_private;
    caddr_t x_base;
    u_int x_handy;
} XDR;

struct xdr_discrim {
    int value;
    xdrproc_t proc;
};

typedef struct netobj {
    u_int n_len;
    char *n_bytes;
} netobj;

extern bool_t xdr_void(void);
extern bool_t xdr_short(XDR *xdrs, short *sp);
extern bool_t xdr_u_short(XDR *xdrs, u_short *usp);
extern bool_t xdr_int(XDR *xdrs, int *ip);
extern bool_t xdr_u_int(XDR *xdrs, u_int *up);
extern bool_t xdr_long(XDR *xdrs, long *lp);
extern bool_t xdr_u_long(XDR *xdrs, u_long *ulp);
extern bool_t xdr_hyper(XDR *xdrs, quad_t *llp);
extern bool_t xdr_u_hyper(XDR *xdrs, u_quad_t *ullp);
extern bool_t xdr_longlong_t(XDR *xdrs, quad_t *llp);
extern bool_t xdr_u_longlong_t(XDR *xdrs, u_quad_t *ullp);
extern bool_t xdr_int8_t(XDR *xdrs, int8_t *ip);
extern bool_t xdr_uint8_t(XDR *xdrs, uint8_t *up);
extern bool_t xdr_int16_t(XDR *xdrs, int16_t *ip);
extern bool_t xdr_uint16_t(XDR *xdrs, uint16_t *up);
extern bool_t xdr_int32_t(XDR *xdrs, int32_t *ip);
extern bool_t xdr_uint32_t(XDR *xdrs, uint32_t *up);
extern bool_t xdr_int64_t(XDR *xdrs, int64_t *ip);
extern bool_t xdr_uint64_t(XDR *xdrs, uint64_t *up);
extern bool_t xdr_quad_t(XDR *xdrs, quad_t *ip);
extern bool_t xdr_u_quad_t(XDR *xdrs, u_quad_t *up);
extern bool_t xdr_bool(XDR *xdrs, bool_t *bp);
extern bool_t xdr_enum(XDR *xdrs, enum_t *ep);
extern bool_t xdr_array(XDR * _xdrs, caddr_t *addrp, u_int *sizep, u_int maxsize, u_int elsize, xdrproc_t elproc);
extern bool_t xdr_bytes(XDR *xdrs, char **cpp, u_int *sizep, u_int maxsize);
extern bool_t xdr_opaque(XDR *xdrs, caddr_t cp, u_int cnt);
extern bool_t xdr_string(XDR *xdrs, char **cpp, u_int maxsize);
extern bool_t xdr_union(XDR *xdrs, enum_t *dscmp, char *unp, const struct xdr_discrim *choices, xdrproc_t dfault);
extern bool_t xdr_char(XDR *xdrs, char *cp);
extern bool_t xdr_u_char(XDR *xdrs, u_char *cp);
extern bool_t xdr_vector(XDR *xdrs, char *basep, u_int nelem, u_int elemsize, xdrproc_t xdr_elem);
extern bool_t xdr_float(XDR *xdrs, float *fp);
extern bool_t xdr_double(XDR *xdrs, double *dp);
extern bool_t xdr_reference(XDR *xdrs, caddr_t *xpp, u_int size, xdrproc_t proc);
extern bool_t xdr_pointer(XDR *xdrs, char **objpp, u_int obj_size, xdrproc_t xdr_obj);
extern bool_t xdr_wrapstring(XDR *xdrs, char **cpp);
extern u_long xdr_sizeof(xdrproc_t, void *);
extern bool_t xdr_netobj(XDR *xdrs, struct netobj *np);
extern void xdrmem_create(XDR *xdrs, const caddr_t addr, u_int size, enum xdr_op xop);
extern void xdrstdio_create(XDR *xdrs, FILE *file, enum xdr_op xop);
extern void xdrrec_create(XDR *xdrs, u_int sendsize, u_int recvsize, caddr_t tcp_handle, int (*readit)(char *, char *, int), int (*writeit)(char *, char *, int));
extern bool_t xdrrec_endofrecord(XDR *xdrs, bool_t sendnow);
extern bool_t xdrrec_skiprecord(XDR *xdrs);
extern bool_t xdrrec_eof(XDR *xdrs);
extern void xdr_free(xdrproc_t proc, char *objp);

#endif /* LIBC_RPC_XDR_H_ */
