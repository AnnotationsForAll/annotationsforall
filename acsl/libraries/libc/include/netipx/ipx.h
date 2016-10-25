/*
 * ipx.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETIPX_IPX_H_
#define LIBC_NETIPX_IPX_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_sa_family_t.h"
#include "../sys/ioctl.h"

#define SOL_IPX 256

#define IPX_TYPE     1
#define IPX_NODE_LEN 6
#define IPX_MTU      576

#define sipx_special sipx_port
#define sipx_action  sipx_zero

#define IPX_DLTITF 0
#define IPX_CRTITF 1

#define SIOCAIPXITFCRT (SIOCPROTOPRIVATE+0)
#define SIOCAIPXPRISLT (SIOCPROTOPRIVATE+1)
#define SIOCIPXCFGDATA (SIOCPROTOPRIVATE+2)
#define SIOCIPXNCPCONN (SIOCPROTOPRIVATE+3)

#define IPX_FRAME_NONE    0
#define IPX_FRAME_SNAP    1
#define IPX_FRAME_8022    2
#define IPX_FRAME_ETHERII 3
#define IPX_FRAME_8023    4
#define IPX_FRAME_TR_8022 5

#define IPX_SPECIAL_NONE 0
#define IPX_PRIMARY      1
#define IPX_INTERNAL     2

#define IPX_RT_SNAP     8
#define IPX_RT_8022     4
#define IPX_RT_BLUEBOOK 2
#define IPX_RT_ROUTED   1

typedef struct ipx_route_definition {
    unsigned long ipx_network;
    unsigned long ipx_router_network;
    unsigned char ipx_router_node[IPX_NODE_LEN];
} ipx_route_definition;

typedef struct ipx_interface_definition {
    unsigned long ipx_network;
    unsigned char ipx_device[16];
    unsigned char ipx_dlink_type;
    unsigned char ipx_special;
    unsigned char ipx_node[IPX_NODE_LEN];
} ipx_interface_definition;

typedef struct ipx_config_data {
    unsigned char ipxcfg_auto_select_primary;
    unsigned char ipxcfg_auto_create_interfaces;
} ipx_config_data;

struct sockaddr_ipx {
    sa_family_t sipx_family;
    u_int16_t sipx_port;
    u_int32_t sipx_network;
    unsigned char sipx_node[IPX_NODE_LEN];
    u_int8_t sipx_type;
    unsigned char sipx_zero;
};

struct ipx_route_def {
    unsigned long ipx_network;
    unsigned long ipx_router_network;
#define IPX_ROUTE_NO_ROUTER 0
    unsigned char ipx_router_node[IPX_NODE_LEN];
    unsigned char ipx_device[16];
    unsigned short ipx_flags;
};

#endif /* LIBC_NETIPX_IPX_H_ */
