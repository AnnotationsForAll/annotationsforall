/*
 * prctl.h
 *
 *  Created on: Jul 14, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_PRCTL_H_
#define LIBC_SYS_PRCTL_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

/*
 TODO: Some of this might be public, kernel-independent interface, and some might be kernel-dependent.
 The kernel-dependent bits need to be enumerated, sorted out, and made machdep-specific.
 */

#define PR_CAP_AMBIENT               0
#define PR_CAPBSET_READ              1
#define PR_CAPBSET_DROP              2
#define PR_SET_CHILD_SUBREAPER       3
#define PR_GET_CHILD_SUBREAPER       4
#define PR_SET_DUMPABLE              5
#define PR_GET_DUMPABLE              6
#define PR_SET_ENDIAN                7
#define PR_GET_ENDIAN                8
#define PR_SET_FPEMU                 9
#define PR_GET_FPEMU                 10
#define PR_SET_FPEXC                 11
#define PR_GET_FPEXC                 12
#define PR_SET_KEEPCAPS              13
#define PR_GET_KEEPCAPS              14
#define PR_MCE_KILL                  15
#define PR_MCE_KILL_GET              16
#define PR_SET_MM                    17
#define PR_MPX_ENABLE_MANAGEMENT     18
#define PR_MPX_DISABLE_MANAGEMENT    19
#define PR_SET_NAME                  20
#define PR_GET_NAME                  21
#define PR_SET_NO_NEW_PRIVS          22
#define PR_GET_NO_NEW_PRIVS          23
#define PR_SET_PDEATHSIG             24
#define PR_GET_PDEATHSIG             25
#define PR_SET_PTRACER               26
#define PR_SET_SECCOMP               27
#define PR_GET_SECCOMP               28
#define PR_SET_SECUREBITS            29
#define PR_GET_SECUREBITS            30
#define PR_SET_THP_DISABLE           31
#define PR_TASK_PERF_EVENTS_DISABLE  32
#define PR_TASK_PERF_EVENTS_ENABLE   33
#define PR_TASK_PERF_COUNTERS_ENABLE PR_TASK_PERF_EVENTS_ENABLE
#define PR_GET_THP_DISABLE           34
#define PR_GET_TID_ADDRESS           35
#define PR_SET_TIMERSLACK            36
#define PR_GET_TIMERSLACK            37
#define PR_SET_TIMING                38
#define PR_GET_TIMING                39
#define PR_SET_TSC                   40
#define PR_GET_TSC                   41
#define PR_SET_UNALIGN               42
#define PR_GET_UNALIGN               43

#define PR_CAP_AMBIENT_RAISE         0
#define PR_CAP_AMBIENT_LOWER         1
#define PR_CAP_AMBIENT_IS_SET        2
#define PR_CAP_AMBIENT_CLEAR_ALL     3

#define SUID_DUMP_DISABLE            0
#define SUID_DUMP_USER               1

#define PR_ENDIAN_BIG                0
#define PR_ENDIAN_LITTLE             1
#define PR_ENDIAN_PPC_LITTLE         2

#define PR_FPEMU_NOPRINT             0
#define PR_FPEMU_SIGFPE              1

#define PR_FP_EXC_SW_ENABLE          0
#define PR_FP_EXC_DIV                1
#define PR_FP_EXC_OVF                2
#define PR_FP_EXC_UND                3
#define PR_FP_EXC_RES                4
#define PR_FP_EXC_INV                5
#define PR_FP_EXC_DISABLED           6
#define PR_FP_EXC_NONRECOV           7
#define PR_FP_EXC_ASYNC              8
#define PR_FP_EXC_PRECISE            9

#define PR_MCE_KILL_CLEAR            0
#define PR_MCE_KILL_SET              1
#define PR_MCE_KILL_EARLY            2
#define PR_MCE_KILL_LATE             3
#define PR_MCE_KILL_DEFAULT          4

#define PR_SET_MM_START_CODE         0
#define PR_SET_MM_END_CODE           1
#define PR_SET_MM_START_DATA         2
#define PR_SET_MM_END_DATA           3
#define PR_SET_MM_START_STACK        4
#define PR_SET_MM_START_BRK          5
#define PR_SET_MM_BRK                6
#define PR_SET_MM_ARG_START          7
#define PR_SET_MM_ARG_END            8
#define PR_SET_MM_ENV_START          9
#define PR_SET_MM_ENV_END            10
#define PR_SET_MM_AUXV               11
#define PR_SET_MM_EXE_FILE           12

#define PR_SET_PTRACER_ANY           0

#define SECCOMP_MODE_STRICT          0
#define SECCOMP_MODE_FILTER          1

#define PR_TIMING_STATISTICAL        0
#define PR_TIMING_TIMESTAMP          1

#define PR_TSC_ENABLE                0
#define PR_TSC_SIGSEGV               1

#define PR_UNALIGN_NOPRINT           0
#define PR_UNALIGN_SIGBUS            1

/*@
assigns \result;
*/
int prctl(int option, ...);

#endif /* LIBC_SYS_PRCTL_H_ */
