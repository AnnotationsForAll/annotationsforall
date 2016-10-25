/*
 * reg.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_REG_H_
#define LIBC_SYS_REG_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

// TODO: These values do vary based on 32 vs. 64 bit. Machdep?
// In addition, this header only appears on x86 / x64 systems.

#define R15      0
#define R14      1
#define R13      2
#define R12      3
#define RBP      4
#define RBX      5
#define R11      6
#define R10      7
#define R9       8
#define R8       9
#define RAX      10
#define RCX      11
#define RDX      12
#define RSI      13
#define RDI      14
#define ORIG_RAX 15
#define RIP      16
#define CS       17
#define EFLAGS   18
#define RSP      19
#define SS       20
#define FS_BASE  21
#define GS_BASE  22
#define DS       23
#define ES       24
#define FS       25
#define GS       26

#define EBX      27
#define ECX      28
#define EDX      29
#define ESI      30
#define EDI      31
#define EBP      32
#define EAX      33
#define ORIG_EAX 34
#define EIP      35
#define EFL      36
#define UESP     37

#endif /* LIBC_SYS_REG_H_ */
