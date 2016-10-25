/*
 * kdaemon.h
 *
 *  Created on: Jul 14, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_KDAEMON_H_
#define LIBC_SYS_KDAEMON_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../errno.h"

/*@
assigns errno, \result;
ensures func <= 0 ==> \result == -1;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int bdflush(int func, ...);

#endif /* LIBC_SYS_KDAEMON_H_ */
