/*
 * cdefs.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_CDEFS_H_
#define LIBC_SYS_CDEFS_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../features.h"

/*
This is an old BSD header used for various internal utility macros.
Some programs depend on these internal macros now, so we provide them.
Most of these needed macros already appear in <features.h>, luckily for us.

TODO: Some BSDs add even more stuff here. They will need to be added for compatibility if it arises.
*/

#define __P(protos)   protos
#define __CONCAT(x,y) x ## y
#define __STRING(x)   #x

#endif /* LIBC_SYS_CDEFS_H_ */
