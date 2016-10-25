/*
 * ptrace.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_PTRACE_H_
#define LIBC_SYS_PTRACE_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../errno.h"

#define PT_TRACE_ME               1
#define PT_READ_I                 2
#define PT_READ_D                 3
#define PT_READ_U                 4
#define PT_WRITE_I                5
#define PT_WRITE_D                6
#define PT_WRITE_U                7
#define PT_CONTINUE               8
#define PT_KILL                   9
#define PT_STEP                   10
#define PT_GETREGS                11
#define PT_SETREGS                12
#define PT_GETFPREGS              13
#define PT_SETFPREGS              14
#define PT_ATTACH                 15
#define PT_DETACH                 16
#define PT_GETFPXREGS             17
#define PT_SETFPXREGS             18
#define PT_SYSCALL                19
#define PT_SETOPTIONS             20
#define PT_GETEVENTMSG            21
#define PT_GETSIGINFO             22
#define PT_SETSIGINFO             23
#define PTRACE_GETREGSET          24
#define PTRACE_SETREGSET          25
#define PTRACE_SEIZE              26
#define PTRACE_INTERRUPT          27
#define PTRACE_LISTEN             28
#define PTRACE_PEEKSIGINFO        29
#define PTRACE_GETSIGMASK         30
#define PTRACE_SETSIGMASK         31
#define PTRACE_SECCOMP_GET_FILTER 32

#define PTRACE_SEIZE_DEVEL 0x80000000

#define PTRACE_O_TRACESYSGOOD    (1 << 0)
#define PTRACE_O_TRACEFORK       (1 << 1)
#define PTRACE_O_TRACEVFORK      (1 << 2)
#define PTRACE_O_TRACECLONE      (1 << 3)
#define PTRACE_O_TRACEEXEC       (1 << 4)
#define PTRACE_O_TRACEVFORKDONE  (1 << 5)
#define PTRACE_O_TRACEEXIT       (1 << 6)
#define PTRACE_O_TRACESECCOMP    (1 << 7)
#define PTRACE_O_EXITKILL        (1 << 8)
#define PTRACE_O_SUSPEND_SECCOMP (1 << 9)
#define PTRACE_O_MASK            0x000003ff

#define PTRACE_EVENT_FORK       1
#define PTRACE_EVENT_VFORK      2
#define PTRACE_EVENT_CLONE      3
#define PTRACE_EVENT_EXEC       4
#define PTRACE_EVENT_VFORK_DONE 5
#define PTRACE_EVENT_EXIT       6
#define PTRACE_EVENT_SECCOMP    7

#define PTRACE_PEEKSIGINFO_SHARED (1 << 0)

/*@
assigns errno, \result;
*/
long int ptrace (int request, ...);

#endif /* LIBC_SYS_PTRACE_H_ */
