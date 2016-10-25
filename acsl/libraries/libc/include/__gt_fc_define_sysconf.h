/*
 * __gt_fc_define_sysconf_values.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC___GT_FC_DEFINE_SYSCONF_H_
#define LIBC___GT_FC_DEFINE_SYSCONF_H_

#include "errno.h"

/* Values for the NAME argument to `pathconf' and `fpathconf'.  */
#define _PC_LINK_MAX           0
#define _PC_MAX_CANON          1
#define _PC_MAX_INPUT          2
#define _PC_NAME_MAX           3
#define _PC_PATH_MAX           4
#define _PC_PIPE_BUF           5
#define _PC_CHOWN_RESTRICTED   6
#define _PC_NO_TRUNC           7
#define _PC_VDISABLE           8
#define _PC_SYNC_IO            9
#define _PC_ASYNC_IO           10
#define _PC_PRIO_IO            11
#define _PC_SOCK_MAXBUF        12
#define _PC_FILESIZEBITS       13
#define _PC_REC_INCR_XFER_SIZE 14
#define _PC_REC_MAX_XFER_SIZE  15
#define _PC_REC_MIN_XFER_SIZE  16
#define _PC_REC_XFER_ALIGN     17
#define _PC_ALLOC_SIZE_MIN     18
#define _PC_SYMLINK_MAX        19
#define _PC_2_SYMLINKS         20

/* Values for the argument to `sysconf'.  */
#define _SC_ARG_MAX                      0
#define _SC_CHILD_MAX                    1
#define _SC_CLK_TCK                      2
#define _SC_NGROUPS_MAX                  3
#define _SC_OPEN_MAX                     4
#define _SC_STREAM_MAX                   5
#define _SC_TZNAME_MAX                   6
#define _SC_JOB_CONTROL                  7
#define _SC_SAVED_IDS                    8
#define _SC_REALTIME_SIGNALS             9
#define _SC_PRIORITY_SCHEDULING          10
#define _SC_TIMERS                       11
#define _SC_ASYNCHRONOUS_IO              12
#define _SC_PRIORITIZED_IO               13
#define _SC_SYNCHRONIZED_IO              14
#define _SC_FSYNC                        15
#define _SC_MAPPED_FILES                 16
#define _SC_MEMLOCK                      17
#define _SC_MEMLOCK_RANGE                18
#define _SC_MEMORY_PROTECTION            19
#define _SC_MESSAGE_PASSING              20
#define _SC_SEMAPHORES                   21
#define _SC_SHARED_MEMORY_OBJECTS        22
#define _SC_AIO_LISTIO_MAX               23
#define _SC_AIO_MAX                      24
#define _SC_AIO_PRIO_DELTA_MAX           25
#define _SC_DELAYTIMER_MAX               26
#define _SC_MQ_OPEN_MAX                  27
#define _SC_MQ_PRIO_MAX                  28
#define _SC_VERSION                      29
#define _SC_PAGESIZE                     30
#define _SC_RTSIG_MAX                    31
#define _SC_SEM_NSEMS_MAX                32
#define _SC_SEM_VALUE_MAX                33
#define _SC_SIGQUEUE_MAX                 34
#define _SC_TIMER_MAX                    35
#define _SC_BC_BASE_MAX                  36
#define _SC_BC_DIM_MAX                   37
#define _SC_BC_SCALE_MAX                 38
#define _SC_BC_STRING_MAX                39
#define _SC_COLL_WEIGHTS_MAX             40
#define _SC_EQUIV_CLASS_MAX              41
#define _SC_EXPR_NEST_MAX                42
#define _SC_LINE_MAX                     43
#define _SC_RE_DUP_MAX                   44
#define _SC_CHARCLASS_NAME_MAX           45
#define _SC_2_VERSION                    46
#define _SC_2_C_BIND                     47
#define _SC_2_C_DEV                      48
#define _SC_2_FORT_DEV                   49
#define _SC_2_FORT_RUN                   50
#define _SC_2_SW_DEV                     51
#define _SC_2_LOCALEDEF                  52
#define _SC_PII                          53
#define _SC_PII_XTI                      54
#define _SC_PII_SOCKET                   55
#define _SC_PII_INTERNET                 56
#define _SC_PII_OSI                      57
#define _SC_POLL                         58
#define _SC_SELECT                       59
#define _SC_UIO_MAXIOV                   60
#define _SC_PII_INTERNET_STREAM          61
#define _SC_PII_INTERNET_DGRAM           62
#define _SC_PII_OSI_COTS                 63
#define _SC_PII_OSI_CLTS                 64
#define _SC_PII_OSI_M                    65
#define _SC_T_IOV_MAX                    66
#define _SC_THREADS                      67
#define _SC_THREAD_SAFE_FUNCTIONS        68
#define _SC_GETGR_R_SIZE_MAX             69
#define _SC_GETPW_R_SIZE_MAX             70
#define _SC_LOGIN_NAME_MAX               71
#define _SC_TTY_NAME_MAX                 72
#define _SC_THREAD_DESTRUCTOR_ITERATIONS 73
#define _SC_THREAD_KEYS_MAX              74
#define _SC_THREAD_STACK_MIN             75
#define _SC_THREAD_THREADS_MAX           76
#define _SC_THREAD_ATTR_STACKADDR        77
#define _SC_THREAD_ATTR_STACKSIZE        78
#define _SC_THREAD_PRIORITY_SCHEDULING   79
#define _SC_THREAD_PRIO_INHERIT          80
#define _SC_THREAD_PRIO_PROTECT          81
#define _SC_THREAD_PROCESS_SHARED        82
#define _SC_NPROCESSORS_CONF             83
#define _SC_NPROCESSORS_ONLN             84
#define _SC_PHYS_PAGES                   85
#define _SC_AVPHYS_PAGES                 86
#define _SC_ATEXIT_MAX                   87
#define _SC_PASS_MAX                     88
#define _SC_XOPEN_VERSION                89
#define _SC_XOPEN_XCU_VERSION            90
#define _SC_XOPEN_UNIX                   91
#define _SC_XOPEN_CRYPT                  92
#define _SC_XOPEN_ENH_I18N               93
#define _SC_XOPEN_SHM                    94
#define _SC_2_CHAR_TERM                  95
#define _SC_2_C_VERSION                  96
#define _SC_2_UPE                        97
#define _SC_XOPEN_XPG2                   98
#define _SC_XOPEN_XPG3                   99
#define _SC_XOPEN_XPG4                   100
#define _SC_CHAR_BIT                     101
#define _SC_CHAR_MAX                     102
#define _SC_CHAR_MIN                     103
#define _SC_INT_MAX                      104
#define _SC_INT_MIN                      105
#define _SC_LONG_BIT                     106
#define _SC_WORD_BIT                     107
#define _SC_MB_LEN_MAX                   108
#define _SC_NZERO                        109
#define _SC_SSIZE_MAX                    110
#define _SC_SCHAR_MAX                    111
#define _SC_SCHAR_MIN                    112
#define _SC_SHRT_MAX                     113
#define _SC_SHRT_MIN                     114
#define _SC_UCHAR_MAX                    115
#define _SC_UINT_MAX                     116
#define _SC_ULONG_MAX                    117
#define _SC_USHRT_MAX                    118
#define _SC_NL_ARGMAX                    119
#define _SC_NL_LANGMAX                   120
#define _SC_NL_MSGMAX                    121
#define _SC_NL_NMAX                      122
#define _SC_NL_SETMAX                    123
#define _SC_NL_TEXTMAX                   124
#define _SC_XBS5_ILP32_OFF32             125
#define _SC_XBS5_ILP32_OFFBIG            126
#define _SC_XBS5_LP64_OFF64              127
#define _SC_XBS5_LPBIG_OFFBIG            128
#define _SC_XOPEN_LEGACY                 129
#define _SC_XOPEN_REALTIME               130
#define _SC_XOPEN_REALTIME_THREADS       131
#define _SC_ADVISORY_INFO                132
#define _SC_BARRIERS                     133
#define _SC_BASE                         134
#define _SC_C_LANG_SUPPORT               135
#define _SC_C_LANG_SUPPORT_R             136
#define _SC_CLOCK_SELECTION              137
#define _SC_CPUTIME                      138
#define _SC_THREAD_CPUTIME               139
#define _SC_DEVICE_IO                    130
#define _SC_DEVICE_SPECIFIC              141
#define _SC_DEVICE_SPECIFIC_R            142
#define _SC_FD_MGMT                      143
#define _SC_FIFO                         144
#define _SC_PIPE                         145
#define _SC_FILE_ATTRIBUTES              146
#define _SC_FILE_LOCKING                 147
#define _SC_FILE_SYSTEM                  148
#define _SC_MONOTONIC_CLOCK              149
#define _SC_MULTI_PROCESS                140
#define _SC_SINGLE_PROCESS               151
#define _SC_NETWORKING                   152
#define _SC_READER_WRITER_LOCKS          153
#define _SC_SPIN_LOCKS                   154
#define _SC_REGEXP                       155
#define _SC_REGEX_VERSION                156
#define _SC_SHELL                        157
#define _SC_SIGNALS                      158
#define _SC_SPAWN                        159
#define _SC_SPORADIC_SERVER              160
#define _SC_THREAD_SPORADIC_SERVER       161
#define _SC_SYSTEM_DATABASE              162
#define _SC_SYSTEM_DATABASE_R            163
#define _SC_TIMEOUTS                     164
#define _SC_TYPED_MEMORY_OBJECTS         165
#define _SC_USER_GROUPS                  166
#define _SC_USER_GROUPS_R                167
#define _SC_2_PBS                        168
#define _SC_2_PBS_ACCOUNTING             169
#define _SC_2_PBS_LOCATE                 170
#define _SC_2_PBS_MESSAGE                171
#define _SC_2_PBS_TRACK                  172
#define _SC_SYMLOOP_MAX                  173
#define _SC_STREAMS                      174
#define _SC_2_PBS_CHECKPOINT             175
#define _SC_V6_ILP32_OFF32               176
#define _SC_V6_ILP32_OFFBIG              177
#define _SC_V6_LP64_OFF64                178
#define _SC_V6_LPBIG_OFFBIG              179
#define _SC_HOST_NAME_MAX                180
#define _SC_TRACE                        181
#define _SC_TRACE_EVENT_FILTER           182
#define _SC_TRACE_INHERIT                183
#define _SC_TRACE_LOG                    184
#define _SC_LEVEL1_ICACHE_SIZE           185
#define _SC_LEVEL1_ICACHE_ASSOC          186
#define _SC_LEVEL1_ICACHE_LINESIZE       187
#define _SC_LEVEL1_DCACHE_SIZE           188
#define _SC_LEVEL1_DCACHE_ASSOC          189
#define _SC_LEVEL1_DCACHE_LINESIZE       190
#define _SC_LEVEL2_CACHE_SIZE            191
#define _SC_LEVEL2_CACHE_ASSOC           192
#define _SC_LEVEL2_CACHE_LINESIZE        193
#define _SC_LEVEL3_CACHE_SIZE            194
#define _SC_LEVEL3_CACHE_ASSOC           195
#define _SC_LEVEL3_CACHE_LINESIZE        196
#define _SC_LEVEL4_CACHE_SIZE            197
#define _SC_LEVEL4_CACHE_ASSOC           198
#define _SC_LEVEL4_CACHE_LINESIZE        199
#define _SC_IPV6                         200
#define _SC_RAW_SOCKETS                  201
#define _SC_V7_ILP32_OFF32               202
#define _SC_V7_ILP32_OFFBIG              203
#define _SC_V7_LP64_OFF64                204
#define _SC_V7_LPBIG_OFFBIG              205
#define _SC_SS_REPL_MAX                  206
#define _SC_TRACE_EVENT_NAME_MAX         207
#define _SC_TRACE_NAME_MAX               208
#define _SC_TRACE_SYS_MAX                209
#define _SC_TRACE_USER_EVENT_MAX         210
#define _SC_XOPEN_STREAMS                211
#define _SC_THREAD_ROBUST_PRIO_INHERIT   212
#define _SC_THREAD_ROBUST_PRIO_PROTECT   213

/* Values for the NAME argument to `confstr'.  */
#define _CS_PATH                            0
#define _CS_V6_WIDTH_RESTRICTED_ENVS        1
#define _CS_POSIX_V6_WIDTH_RESTRICTED_ENVS  2
#define _CS_GNU_LIBC_VERSION                3
#define _CS_GNU_LIBPTHREAD_VERSION          4
#define _CS_V5_WIDTH_RESTRICTED_ENVS        5
#define _CS_POSIX_V5_WIDTH_RESTRICTED_ENVS  6
#define _CS_V7_WIDTH_RESTRICTED_ENVS        7
#define _CS_POSIX_V7_WIDTH_RESTRICTED_ENVS  8
#define _CS_LFS_CFLAGS                      9
#define _CS_LFS_LDFLAGS                     10
#define _CS_LFS_LIBS                        11
#define _CS_LFS_LINTFLAGS                   12
#define _CS_LFS64_CFLAGS                    13
#define _CS_LFS64_LDFLAGS                   14
#define _CS_LFS64_LIBS                      15
#define _CS_LFS64_LINTFLAGS                 16
#define _CS_XBS5_ILP32_OFF32_CFLAGS         17
#define _CS_XBS5_ILP32_OFF32_LDFLAGS        18
#define _CS_XBS5_ILP32_OFF32_LIBS           19
#define _CS_XBS5_ILP32_OFF32_LINTFLAGS      20
#define _CS_XBS5_ILP32_OFFBIG_CFLAGS        21
#define _CS_XBS5_ILP32_OFFBIG_LDFLAGS       22
#define _CS_XBS5_ILP32_OFFBIG_LIBS          23
#define _CS_XBS5_ILP32_OFFBIG_LINTFLAGS     24
#define _CS_XBS5_LP64_OFF64_CFLAGS          25
#define _CS_XBS5_LP64_OFF64_LDFLAGS         26
#define _CS_XBS5_LP64_OFF64_LIBS            27
#define _CS_XBS5_LP64_OFF64_LINTFLAGS       28
#define _CS_XBS5_LPBIG_OFFBIG_CFLAGS        29
#define _CS_XBS5_LPBIG_OFFBIG_LDFLAGS       30
#define _CS_XBS5_LPBIG_OFFBIG_LIBS          31
#define _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS     32
#define _CS_POSIX_V6_ILP32_OFF32_CFLAGS     33
#define _CS_POSIX_V6_ILP32_OFF32_LDFLAGS    34
#define _CS_POSIX_V6_ILP32_OFF32_LIBS       35
#define _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS  36
#define _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS    37
#define _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS   38
#define _CS_POSIX_V6_ILP32_OFFBIG_LIBS      39
#define _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS 40
#define _CS_POSIX_V6_LP64_OFF64_CFLAGS      41
#define _CS_POSIX_V6_LP64_OFF64_LDFLAGS     42
#define _CS_POSIX_V6_LP64_OFF64_LIBS        43
#define _CS_POSIX_V6_LP64_OFF64_LINTFLAGS   44
#define _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS    45
#define _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS   46
#define _CS_POSIX_V6_LPBIG_OFFBIG_LIBS      47
#define _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS 48
#define _CS_POSIX_V7_ILP32_OFF32_CFLAGS     49
#define _CS_POSIX_V7_ILP32_OFF32_LDFLAGS    50
#define _CS_POSIX_V7_ILP32_OFF32_LIBS       51
#define _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS  52
#define _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS    53
#define _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS   54
#define _CS_POSIX_V7_ILP32_OFFBIG_LIBS      55
#define _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS 56
#define _CS_POSIX_V7_LP64_OFF64_CFLAGS      57
#define _CS_POSIX_V7_LP64_OFF64_LDFLAGS     58
#define _CS_POSIX_V7_LP64_OFF64_LIBS        59
#define _CS_POSIX_V7_LP64_OFF64_LINTFLAGS   60
#define _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS    61
#define _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS   62
#define _CS_POSIX_V7_LPBIG_OFFBIG_LIBS      63
#define _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS 64
#define _CS_V6_ENV                          65
#define _CS_V7_ENV                          66

#define _SC_PAGE_SIZE _SC_PAGESIZE
#define _SC_IOV_MAX   _SC_UIO_MAXIOV

/*@
requires \valid(buf+(0..len-1));
assigns \result, buf[0..len-1], errno \from name, len;
ensures 0 <= \result <= len;
ensures \result > 0 ==> errno == \old(errno);
*/
size_t confstr(int name, char *buf, size_t len);

/*@
assigns \result \from fildes, name;
*/
long fpathconf(int fildes, int name);

/*@
requires \valid(path);
assigns \result \from path[..], name;
*/
long pathconf(const char *path, int name);

/*@
    predicate sysconfPosixVar(integer name) = _SC_ARG_MAX <= name <= _SC_THREAD_ROBUST_PRIO_PROTECT;
    axiomatic sysconf {
        logic long sysconf(integer name);
        axiom invalid{L}:
            \forall integer i; !sysconfPosixVar(i) ==> sysconf(i) == -1;

        axiom sysconf_page_size: sysconf(_SC_PAGESIZE) > 0;
    }
*/

/*@
assigns \result, errno \from name;
ensures \result == sysconf(name);
ensures !sysconfPosixVar(name) ==> errno == EINVAL;
ensures sysconfPosixVar(name) ==> errno == \old(errno);
*/
long sysconf(int name);

#endif /* LIBC___GT_FC_DEFINE_SYSCONF_H_ */
