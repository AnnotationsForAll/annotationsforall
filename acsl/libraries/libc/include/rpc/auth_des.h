/*
 * auth_des.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_AUTH_DES_H_
#define LIBC_RPC_AUTH_DES_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_uid_and_gid.h"
#include "../netinet/in.h"
#include "auth.h"

#define adv_timestamp  adv_time_u.adv_ctime
#define adv_xtimestamp adv_time_u.adv_xtime
#define adv_winverf    adv_int_u

#define adv_timeverf  adv_time_u.adv_ctime
#define adv_xtimeverf adv_time_u.adv_xtime
#define adv_nickname  adv_int_u

enum authdes_namekind {
    ADN_FULLNAME,
    ADN_NICKNAME
};

struct authdes_fullname {
    char *name;
    des_block key;
    uint32_t window;
};

struct authdes_cred {
    enum authdes_namekind adc_namekind;
    struct authdes_fullname adc_fullname;
    uint32_t adc_nickname;
};

struct rpc_timeval {
    uint32_t tv_sec;
    uint32_t tv_usec;
};

struct authdes_verf {
    union {
        struct rpc_timeval adv_ctime;
        des_block adv_xtime;
    } adv_time_u;
    uint32_t adv_int_u;
};

int authdes_getucred(const struct authdes_cred * adc, uid_t * uid, gid_t * gid, short *grouplen, gid_t * groups);
int getpublickey(const char *name, char *key);
int getsecretkey(const char *name, char *key, const char *passwd);
int rtime(struct sockaddr_in *addrp, struct rpc_timeval *timep, struct rpc_timeval *timeout);

#endif /* LIBC_RPC_AUTH_DES_H_ */
