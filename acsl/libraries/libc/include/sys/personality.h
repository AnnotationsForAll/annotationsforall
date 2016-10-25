/*
 * personality.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_PERSONALITY_H_
#define LIBC_SYS_PERSONALITY_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../errno.h"

#define ADDR_COMPAT_LAYOUT (1 << 0)
#define ADDR_NO_RANDOMIZE  (1 << 1)
#define ADDR_LIMIT_32BIT   (1 << 2)
#define ADDR_LIMIT_3GB     (1 << 3)
#define FDPIC_FUNCPTRS     (1 << 4)
#define MMAP_PAGE_ZERO     (1 << 5)
#define READ_IMPLIES_EXEC  (1 << 6)
#define SHORT_INODE        (1 << 7)
#define STICKY_TIMEOUTS    (1 << 8)
#define UNAME26            (1 << 9)
#define WHOLE_SECONDS      (1 << 10)

#define PER_BSD         1
#define PER_HPUX        2
#define PER_IRIX32      3
#define PER_IRIX64      4
#define PER_IRIXN32     5
#define PER_ISCR4       6
#define PER_LINUX       0
#define PER_LINUX32     7
#define PER_LINUX32_3GB 8
#define PER_LINUX_32BIT 9
#define PER_LINUX_FDPIC 10
#define PER_OSF4        11
#define PER_OSR5        12
#define PER_RISCOS      13
#define PER_SCOSVR3     14
#define PER_SOLARIS     15
#define PER_SUNOS       16
#define PER_SVR3        17
#define PER_SVR4        18
#define PER_UW7         19
#define PER_WYSEV386    20
#define PER_XENIX       21

/*@
assigns \result;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int personality(unsigned long persona);

#endif /* LIBC_SYS_PERSONALITY_H_ */
