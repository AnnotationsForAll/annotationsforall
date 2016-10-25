/*
 * rpc.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_RPC_H_
#define LIBC_RPC_RPC_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

// This header just serves to gather all the RPC headers in one simple place.

#include "../netinet/in.h"
#include "types.h"
#include "auth.h"
#include "clnt.h"
#include "xdr.h"
#include "rpc_msg.h"
#include "auth_unix.h"
#include "auth_des.h"
#include "svc.h"
#include "svc_auth.h"
#include "netdb.h"

#endif /* LIBC_RPC_RPC_H_ */
