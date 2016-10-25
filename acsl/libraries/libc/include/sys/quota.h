/*
 * quota.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_QUOTA_H_
#define LIBC_SYS_QUOTA_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__gt_fc_define_caddr_t.h"

#include "../__fc_string_axiomatic.h"
#include "../errno.h"

#define MAX_IQ_TIME 604800
#define MAX_DQ_TIME 604800

#define MAXQUOTAS 2
#define USRQUOTA  0
#define GRPQUOTA  1

#define QUOTAFILENAME "quota"
#define QUOTAGROUP    "staff"

#define NR_DQHASH 43
#define NR_DQUOTS 256

#define SUBCMDMASK       0x00ff
#define SUBCMDSHIFT      8
#define QCMD(cmd, type)  (((cmd) << SUBCMDSHIFT) | ((type) & SUBCMDMASK))

# define Q_QUOTAON  (1 << 6)
# define Q_QUOTAOFF (1 << 7)
# define Q_GETQUOTA (1 << 8)
# define Q_SETQUOTA (1 << 9)
# define Q_SETUSE   (1 << 10)
# define Q_SYNC     (1 << 11)
# define Q_SETQLIM  (1 << 12)
# define Q_GETSTATS (1 << 13)
# define Q_RSQUASH  (1 << 14)
# define Q_GETFMT   (1 << 15)
# define Q_GETINFO  (1 << 16)
# define Q_SETINFO  (1 << 17)

#define QIF_BLIMITS (1 << 0)
#define QIF_SPACE   (1 << 1)
#define QIF_ILIMITS (1 << 2)
#define QIF_INODES  (1 << 3)
#define QIF_BTIME   (1 << 4)
#define QIF_ITIME   (1 << 5)
#define QIF_LIMITS  (QIF_BLIMITS | QIF_ILIMITS)
#define QIF_USAGE   (QIF_SPACE | QIF_INODES)
#define QIF_TIMES   (QIF_BTIME | QIF_ITIME)
#define QIF_ALL     (QIF_LIMITS | QIF_USAGE | QIF_TIMES)

#define dq_bhardlimit dq_dqb.dqb_bhardlimit
#define dq_bsoftlimit dq_dqb.dqb_bsoftlimit
# define dq_curblocks dq_dqb.dqb_curblocks
# define dq_curspace  dq_dqb.dqb_curspace
# define dq_valid     dq_dqb.dqb_valid
#define dq_ihardlimit dq_dqb.dqb_ihardlimit
#define dq_isoftlimit dq_dqb.dqb_isoftlimit
#define dq_curinodes  dq_dqb.dqb_curinodes
#define dq_btime      dq_dqb.dqb_btime
#define dq_itime      dq_dqb.dqb_itime

# define IIF_BGRACE (1 << 0)
# define IIF_IGRACE (1 << 1)
# define IIF_FLAGS  (1 << 2)
# define IIF_ALL    (IIF_BGRACE | IIF_IGRACE | IIF_FLAGS)

#define dbtob(num) ((num) << 10)
#define btodb(num) ((num) >> 10)

#define fs_to_dq_blocks(num, blksize) (((num) * (blksize)) / BLOCK_SIZE)

#define dqoff(UID)      ((loff_t)((UID) * sizeof (struct dqblk)))

#define INITQFNAMES { \
   "user",  \
   "group", \
   "undefined", \
};

struct dqblk {
    u_int64_t dqb_bhardlimit;
    u_int64_t dqb_bsoftlimit;
    u_int64_t dqb_curspace;
    u_int64_t dqb_ihardlimit;
    u_int64_t dqb_isoftlimit;
    u_int64_t dqb_curinodes;
    u_int64_t dqb_btime;
    u_int64_t dqb_itime;
    u_int32_t dqb_valid;
    u_int32_t dqb_curblocks;
};

struct dqstats {
    u_int32_t lookups;
    u_int32_t drops;
    u_int32_t reads;
    u_int32_t writes;
    u_int32_t cache_hits;
    u_int32_t pages_allocated;
    u_int32_t allocated_dquots;
    u_int32_t free_dquots;
    u_int32_t syncs;
};

struct dqinfo {
    u_int64_t dqi_bgrace;
    u_int64_t dqi_igrace;
    u_int32_t dqi_flags;
    u_int32_t dqi_valid;
};

/*@
//FIXME: 'addr' can be interpreted as an address to assign to. Frama-C cannot reason about this.
requires valid_read_string(special);
assigns errno, \result;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int quotactl(int cmd, const char *special, int id, caddr_t addr);

#endif /* LIBC_SYS_QUOTA_H_ */
