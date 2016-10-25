/*
 * debugreg.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_DEBUGREG_H_
#define LIBC_SYS_DEBUGREG_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

/*
This header is only present on Intel-family systems. However, it has the same macros across architectures, even if the values differ.
TODO: machdep?
*/

#define DR_FIRSTADDR 0
#define DR_LASTADDR  3

#define DR_STATUS  6
#define DR_CONTROL 7

#define DR_TRAP0 (1 << 0)
#define DR_TRAP1 (1 << 1)
#define DR_TRAP2 (1 << 2)
#define DR_TRAP3 (1 << 3)

#define DR_STEP   (1 << 4)
#define DR_SWITCH (1 << 5)

#define DR_CONTROL_SHIFT 16
#define DR_CONTROL_SIZE  4

#define DR_RW_EXECUTE 0
#define DR_RW_WRITE   1
#define DR_RW_READ    2

#define DR_LEN_1 (0x0)
#define DR_LEN_2 (0x4)
#define DR_LEN_4 (0xC)
#define DR_LEN_8 (0x8)

#define DR_LOCAL_ENABLE_SHIFT  0
#define DR_GLOBAL_ENABLE_SHIFT 1
#define DR_ENABLE_SIZE         2

#define DR_LOCAL_ENABLE_MASK  (0x55)
#define DR_GLOBAL_ENABLE_MASK (0xAA)

#define DR_CONTROL_RESERVED 0
#define DR_LOCAL_SLOWDOWN   (1 << 6)
#define DR_GLOBAL_SLOWDOWN  (1 << 7)

#endif /* LIBC_SYS_DEBUGREG_H_ */
