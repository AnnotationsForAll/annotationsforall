/*
 * procfs.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_PROCFS_H_
#define LIBC_SYS_PROCFS_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_size_t.h"
#include "../__fc_define_pid_t.h"
#include "../__fc_define_uid_and_gid.h"
#include "../__fc_define_timespec.h"
#include "../stdint.h"
#include "../ucontext.h"

#define ELF_PRARGSZ 80

typedef gregset_t prgregset_t;
typedef fpregset_t prfpregset_t;

typedef struct elf_psinfo {
    int pr_flag;
    int pr_nlwp;
    pid_t pr_pid;
    pid_t pr_ppid;
    pid_t pr_pgid;
    pid_t pr_sid;
    uid_t pr_uid, pr_euid;
    gid_t pr_gid, pr_egid;
    size_t pr_size;
    size_t pr_rssize;
    uint16_t pr_pctcpu;
    uint16_t pr_pctmem;
    struct timespec pr_start;
    struct timespec pr_time;
    struct timespec pr_ctime;
    uint32_t pr_reserved1[2];
    char pr_fname[16];
    char pr_psargs[ELF_PRARGSZ];
    int pr_wstat;
    int pr_argc;
    uintptr_t pr_argv;
    uintptr_t pr_envp;
} psinfo_t;

typedef struct elf_pstatus {
    int pr_flags;
    int pr_nlwp;
    pid_t pr_pid;
    pid_t pr_ppid;
    pid_t pr_pgid;
    pid_t pr_sid;
    struct timespec pr_utime;
    struct timespec pr_stime;
    struct timespec pr_cutime;
    struct timespec pr_cstime;
} pstatus_t;

struct elf_siginfo {
    int si_signo;
    int si_code;
    int si_errno;
};

typedef struct elf_lwpstatus {
    int pr_flags;
    int pr_lwpid;
    int pr_cursig;
    struct elf_siginfo pr_info;
    prgregset_t pr_reg;
    prfpregset_t pr_fpreg;
} lwpstatus_t;

#endif /* LIBC_SYS_PROCFS_H_ */
