/*
 * reboot.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_REBOOT_H_
#define LIBC_SYS_REBOOT_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../errno.h"

#define RB_DISABLE_CAD 0
#define RB_ENABLE_CAD  0x89abcdef
#define RB_HALT_SYSTEM 0xcdef0123
#define RB_KEXEC       0x45584543
#define RB_POWER_OFF   0x4321fedc
#define RB_AUTOBOOT    0x1234567
#define RB_SW_SUSPEND  0xd000fce1

/*@
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int reboot(int cmd);

#endif /* LIBC_SYS_REBOOT_H_ */
