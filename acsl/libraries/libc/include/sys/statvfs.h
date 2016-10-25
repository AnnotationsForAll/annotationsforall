/*
 * statvfs.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_STATVFS_H_
#define LIBC_SYS_STATVFS_H_

#include "../__gt_fc_define_fs_types.h"
#include "errno.h"

struct statvfs {
    unsigned long f_bsize;
    unsigned long f_frsize;
    fsblkcnt_t f_blocks;
    fsblkcnt_t f_bfree;
    fsblkcnt_t f_bavail;
    fsfilcnt_t f_files;
    fsfilcnt_t f_ffree;
    fsfilcnt_t f_favail;
    unsigned long f_fsid;
    unsigned long f_flag;
    unsigned long f_namemax;
};

struct statvfs64 {
    unsigned long f_bsize;
    unsigned long f_frsize;
    fsblkcnt64_t f_blocks;
    fsblkcnt64_t f_bfree;
    fsblkcnt64_t f_bavail;
    fsfilcnt64_t f_files;
    fsfilcnt64_t f_ffree;
    fsfilcnt64_t f_favail;
    unsigned long f_fsid;
    unsigned long f_flag;
    unsigned long f_namemax;
};

#define ST_RDONLY      1
#define ST_NOSUID      2
#define ST_NODEV       3
#define ST_NOEXEC      4
#define ST_SYNCHRONOUS 5
#define ST_MANDLOCK    6
#define ST_WRITE       7
#define ST_APPEND      8
#define ST_IMMUTABLE   9
#define ST_NOATIME     10
#define ST_NODIRATIME  11
#define ST_RELATIME    12

/*@
requires \valid(buf);
assigns \result, *buf, errno \from fildes;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fstatvfs(int fildes, struct statvfs *buf);

/*@
requires \valid(path);
requires \valid(buf);
assigns \result, *buf, errno \from path[..];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int statvfs(const char *restrict path, struct statvfs *restrict buf);

/*@
requires \valid(buf);
assigns \result, *buf, errno \from fildes;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fstatvfs64(int fildes, struct statvfs64 *buf);

/*@
requires \valid(path);
requires \valid(buf);
assigns \result, *buf, errno \from path[..];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int statvfs64(const char *restrict path, struct statvfs64 *restrict buf);

#endif /* LIBC_SYS_STATVFS_H_ */
