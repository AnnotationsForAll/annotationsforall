/*
 * gmon_out.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_GMON_OUT_H_
#define LIBC_SYS_GMON_OUT_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#define GMON_MAGIC   "gmon"
#define GMON_VERSION 1

#define GMON_SHOBJ_VERSION  0x1ffff

struct gmon_hdr {
    char cookie[4];
    char version[4];
    char spare[3 * 4];
};

typedef enum {
    GMON_TAG_TIME_HIST = 0,
    GMON_TAG_CG_ARC = 1,
    GMON_TAG_BB_COUNT = 2
} GMON_Record_Tag;

struct gmon_hist_hdr {
    char low_pc[sizeof(char *)];
    char high_pc[sizeof(char *)];
    char hist_size[4];
    char prof_rate[4];
    char dimen[15];
    char dimen_abbrev;
};

struct gmon_cg_arc_record {
    char from_pc[sizeof(char *)];
    char self_pc[sizeof(char *)];
    char count[4];
};

#endif /* LIBC_SYS_GMON_OUT_H_ */
