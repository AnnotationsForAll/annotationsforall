/*
 * bitypes.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_BITYPES_H_
#define LIBC_SYS_BITYPES_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"

/*
This header is where BSD systems define their version of the alternative type names (u_char, u_int32_t, etc.).
glibc implements this by simply including <sys/types.h>. We can do better by including our alt. types file instead.
*/

#endif /* LIBC_SYS_BITYPES_H_ */
