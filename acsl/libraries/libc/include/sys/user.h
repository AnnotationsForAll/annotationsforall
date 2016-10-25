/*
 * user.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_USER_H_
#define LIBC_SYS_USER_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

/*
 This header is stated to be only used for GDB, but we define this header just in case
 a user program tries to use this. This is public interface, after all.
 */

// TODO: It feels like these structs should depend on machdep.

struct user_fpregs_struct {
    unsigned short int cwd;
    unsigned short int swd;
    unsigned short int ftw;
    unsigned short int fop;
    unsigned long long int rip;
    unsigned long long int rdp;
    unsigned int mxcsr;
    unsigned int mxcr_mask;
    unsigned int st_space[32];
    unsigned int xmm_space[64];
    unsigned int padding[24];
};

struct user_fpxregs_struct {
    unsigned short int cwd;
    unsigned short int swd;
    unsigned short int twd;
    unsigned short int fop;
    long int fip;
    long int fcs;
    long int foo;
    long int fos;
    long int mxcsr;
    long int reserved;
    long int st_space[32];
    long int xmm_space[32];
    long int padding[56];
};

struct user_regs_struct {
    unsigned long long int r15;
    unsigned long long int r14;
    unsigned long long int r13;
    unsigned long long int r12;
    unsigned long long int rbp;
    unsigned long long int rbx;
    unsigned long long int r11;
    unsigned long long int r10;
    unsigned long long int r9;
    unsigned long long int r8;
    unsigned long long int rax;
    unsigned long long int rcx;
    unsigned long long int rdx;
    unsigned long long int rsi;
    unsigned long long int rdi;
    unsigned long long int orig_rax;
    unsigned long long int rip;
    unsigned long long int cs;
    unsigned long long int eflags;
    unsigned long long int rsp;
    unsigned long long int ss;
    unsigned long long int fs_base;
    unsigned long long int gs_base;
    unsigned long long int ds;
    unsigned long long int es;
    unsigned long long int fs;
    unsigned long long int gs;
};

struct user {
    struct user_regs_struct regs;
    int u_fpvalid;
    struct user_fpregs_struct i387;
    unsigned long long int u_tsize;
    unsigned long long int u_dsize;
    unsigned long long int u_ssize;
    unsigned long long int start_code;
    unsigned long long int start_stack;
    long long int signal;
    int reserved;
    union {
        struct user_regs_struct* u_ar0;
    };
    union {
        struct user_fpregs_struct* u_fpstate;
    };
    unsigned long long int magic;
    char u_comm[32];
    unsigned long long int u_debugreg[8];
};

#define PAGE_SHIFT           12
#define PAGE_SIZE            (1UL << PAGE_SHIFT)
#define PAGE_MASK            (~(PAGE_SIZE-1))
#define NBPG                 PAGE_SIZE
#define UPAGES               1
#define HOST_TEXT_START_ADDR (u.start_code)
#define HOST_STACK_END_ADDR  (u.start_stack + u.u_ssize * NBPG)

#endif /* LIBC_SYS_USER_H_ */
