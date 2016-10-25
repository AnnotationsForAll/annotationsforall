/*
 * ucontext.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_UCONTEXT_H_
#define LIBC_UCONTEXT_H_

// This header is a SVID extension. Do not use for strictly POSIX-compliant work.

#include "signal.h"

#include "errno.h"

//TODO: Include register macros for all possible architectures. Make it machdep dependent.

// x86 64
#define REG_R8      0
#define REG_R9      1
#define REG_R10     2
#define REG_R11     3
#define REG_R12     4
#define REG_R13     5
#define REG_R14     6
#define REG_R15     7
#define REG_RDI     8
#define REG_RSI     9
#define REG_RBP     10
#define REG_RBX     11
#define REG_RDX     12
#define REG_RAX     13
#define REG_RCX     14
#define REG_RSP     15
#define REG_RIP     16
#define REG_EFL     17
#define REG_CSGSFS  18
#define REG_ERR     19
#define REG_TRAPNO  20
#define REG_OLDMASK 21
#define REG_CR2     22

// x86
#define REG_GS     0
#define REG_FS     1
#define REG_ES     2
#define REG_DS     3
#define REG_EDI    4
#define REG_ESI    5
#define REG_EBP    6
#define REG_ESP    7
#define REG_EBX    8
#define REG_EDX    9
#define REG_ECX    10
#define REG_EAX    11
#define REG_TRAPNO 12
#define REG_ERR    13
#define REG_EIP    14
#define REG_CS     15
#define REG_EFL    16
#define REG_UESP   17
#define REG_SS     18

#define NGREG 23

typedef long long int greg_t;
typedef greg_t gregset_t[NGREG];
typedef void* fpregset_t; // gregset is not an opaque type, but fpregset is. In addition, fpregset must be a pointer type.

typedef struct {
    gregset_t gregs;
    fpregset_t fpregs;
    // the following members don't exist on every machdep, but are defined for public use.
    unsigned long int oldmask;
    unsigned long int cr2;
} mcontext_t;

typedef struct ucontext_t {
    struct ucontext_t *uc_link;
    sigset_t uc_sigmask;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
} ucontext_t;

/*@
axiomatic Contexts {
    logic boolean is_context_open(ucontext_t* ucp) reads *ucp;
}
*/

/*@
requires \valid(ucp);
// no assigns clause; this function does a non-local jump!
ensures \result == 0 ==> is_context_open(ucp);
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int getcontext(ucontext_t *ucp);

/*@
requires \valid(ucp);
requires is_context_open(ucp);
assigns errno, \result;
// this function never usually returns. If it does, it's returning with an error.
ensures \result == -1;
ensures errno != 0;
*/
int setcontext(const ucontext_t *ucp);

/*@
requires \valid(ucp);
requires is_context_open(ucp);
requires func != \null;
assigns errno, *ucp;
ensures is_context_open(ucp);
*/
void makecontext(ucontext_t *ucp, void (*func)(void), int argc, ...);

/*@
requires \valid(ucp);
requires is_context_open(ucp);
requires \valid(oucp);
assigns errno, \result, *oucp;
// this function never usually returns. If it does, it's returning with an error.
ensures \result == -1;
ensures errno != 0;
*/
int swapcontext(ucontext_t *restrict oucp, const ucontext_t *restrict ucp);

#endif /* LIBC_UCONTEXT_H_ */
