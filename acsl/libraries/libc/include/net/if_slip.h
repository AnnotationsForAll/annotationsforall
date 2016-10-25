/*
 * if_slip.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NET_IF_SLIP_H_
#define LIBC_NET_IF_SLIP_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../sys/ioctl.h"

/*
TODO: Some of this might be public, kernel-independent interface, and some might be kernel-dependent.
The kernel-dependent bits need to be enumerated, sorted out, and made machdep-specific.
*/

#define SL_MODE_SLIP  0
#define SL_MODE_CSLIP 1
#define SL_MODE_KISS  4

#define SL_OPT_SIXBIT   2
#define SL_OPT_ADAPTIVE 8

#define SIOCSKEEPALIVE (SIOCDEVPRIVATE+0)
#define SIOCGKEEPALIVE (SIOCDEVPRIVATE+1)
#define SIOCSOUTFILL   (SIOCDEVPRIVATE+2)
#define SIOCGOUTFILL   (SIOCDEVPRIVATE+3)
#define SIOCSLEASE     (SIOCDEVPRIVATE+4)
#define SIOCGLEASE     (SIOCDEVPRIVATE+5)

#endif /* LIBC_NET_IF_SLIP_H_ */
