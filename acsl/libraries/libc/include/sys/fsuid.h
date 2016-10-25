/*
 * fsuid.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_FSUID_H_
#define LIBC_SYS_FSUID_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_uid_and_gid.h"

#include "errno.h"

/*@
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setfsgid(uid_t fsgid);

/*@
assigns errno, \result;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setfsuid(uid_t fsuid);

#endif /* LIBC_SYS_FSUID_H_ */
