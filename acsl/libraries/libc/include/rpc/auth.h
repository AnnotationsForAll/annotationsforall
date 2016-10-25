/*
 * auth.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_AUTH_H_
#define LIBC_RPC_AUTH_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_uid_and_gid.h"
#include "../__gt_fc_define_caddr_t.h"
#include "xdr.h"
#include "types.h"

#define MAX_AUTH_BYTES 400
#define MAXNETNAMELEN  255

#define AUTH_NEXTVERF(auth) ((*((auth)->ah_ops->ah_nextverf))(auth))
#define auth_nextverf(auth) ((*((auth)->ah_ops->ah_nextverf))(auth))

#define AUTH_MARSHALL(auth, xdrs) ((*((auth)->ah_ops->ah_marshal))(auth, xdrs))
#define auth_marshall(auth, xdrs) ((*((auth)->ah_ops->ah_marshal))(auth, xdrs))

#define AUTH_VALIDATE(auth, verfp) ((*((auth)->ah_ops->ah_validate))((auth), verfp))
#define auth_validate(auth, verfp) ((*((auth)->ah_ops->ah_validate))((auth), verfp))

#define AUTH_REFRESH(auth) ((*((auth)->ah_ops->ah_refresh))(auth))
#define auth_refresh(auth) ((*((auth)->ah_ops->ah_refresh))(auth))

#define AUTH_DESTROY(auth) ((*((auth)->ah_ops->ah_destroy))(auth))
#define auth_destroy(auth) ((*((auth)->ah_ops->ah_destroy))(auth))

#define AUTH_NONE   0
#define AUTH_NULL   AUTH_NONE
#define AUTH_SYS    1
#define AUTH_UNIX   AUTH_SYS
#define AUTH_SHORT  2
#define AUTH_DES    3
#define AUTH_DH     AUTH_DES
#define AUTH_KERB   4

enum auth_stat {
    AUTH_OK = 0,
    AUTH_BADCRED = 1,
    AUTH_REJECTEDCRED = 2,
    AUTH_BADVERF = 3,
    AUTH_REJECTEDVERF = 4,
    AUTH_TOOWEAK = 5,
    AUTH_INVALIDRESP = 6,
    AUTH_FAILED = 7
};

typedef union des_block {
    struct {
        u_int32_t high;
        u_int32_t low;
    } key;
    char c[8];
} des_block;

typedef struct opaque_auth { // Ironically, this struct isn't actually opaque.
    enum_t oa_flavor;
    caddr_t oa_base;
    u_int oa_length;
} opaque_auth;

typedef struct AUTH {
    struct opaque_auth ah_cred;
    struct opaque_auth ah_verf;
    union des_block ah_key;
    struct auth_ops {
        void (*ah_nextverf)(AUTH *);
        int (*ah_marshal)(AUTH *, XDR *);
        int (*ah_validate)(AUTH *, struct opaque_auth *);
        int (*ah_refresh)(AUTH *);
        void (*ah_destroy)(AUTH *);
    }*ah_ops;
    caddr_t ah_private;
} AUTH;

extern bool_t xdr_des_block(XDR *__xdrs, des_block *__blkp);
extern AUTH *authunix_create(char *__machname, __uid_t  __uid, __gid_t  __gid, int __len, __gid_t *__aup_gids);
extern AUTH *authunix_create_default(void);
extern AUTH *authnone_create(void);
extern AUTH *authdes_create(const char *__servername, u_int __window, struct sockaddr *__syncaddr, des_block *__ckey);
extern AUTH *authdes_pk_create(const char *, netobj *, u_int, struct sockaddr *, des_block *);
extern int getnetname(char *);
extern int host2netname(char *, const char *, const char *);
extern int user2netname(char *, const uid_t, const char *);
extern int netname2user(const char *, uid_t *, gid_t *, int *, gid_t *);
extern int netname2host(const char *, char *, const int);
extern int key_decryptsession(char *, des_block *);
extern int key_decryptsession_pk(char *, netobj *, des_block *);
extern int key_encryptsession(char *, des_block *);
extern int key_encryptsession_pk(char *, netobj *, des_block *);
extern int key_gendes(des_block *);
extern int key_setsecret(char *);
extern int key_secretkey_is_set(void);
extern int key_get_conv(char *, des_block *);
extern bool_t xdr_opaque_auth(XDR *, struct opaque_auth *);

#endif /* LIBC_RPC_AUTH_H_ */
