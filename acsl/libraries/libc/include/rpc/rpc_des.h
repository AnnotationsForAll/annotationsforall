/*
 * rpc_des.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_RPC_DES_H_
#define LIBC_RPC_RPC_DES_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"

#define DES_MAXLEN  65536
#define DES_QUICKLEN    16

#define des_data UDES.UDES_data
#define des_buf UDES.UDES_buf

enum desdir {
    ENCRYPT,
    DECRYPT
};

enum desmode {
    CBC,
    ECB
};

struct desparams {
    u_char des_key[8];
    enum desdir des_dir;
    enum desmode des_mode;
    u_char des_ivec[8];
    unsigned des_len;
    union {
        u_char UDES_data[DES_QUICKLEN];
        u_char *UDES_buf;
    } UDES;
};

#endif /* LIBC_RPC_RPC_DES_H_ */
