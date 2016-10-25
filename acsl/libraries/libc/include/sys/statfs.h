/*
 * statfs.h
 *
 *  Created on: Jun 30, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_STATFS_H_
#define LIBC_SYS_STATFS_H_

// This header is a GNU extension. Do not use for POSIX standard work.

#include "../__gt_fc_define_fs_types.h"\

#include "../errno.h"

struct statfs {
    fsword_t f_type;
    fsword_t f_bsize;
    fsblkcnt_t f_blocks;
    fsblkcnt_t f_bfree;
    fsblkcnt_t f_bavail;
    fsblkcnt_t f_files;
    fsblkcnt_t f_ffree;
    fsid_t  f_fsid;
    fsword_t f_namelen;
    fsword_t f_frsize;
    fsword_t f_flags;
    fsword_t f_spare[4];
};

struct statfs64 {
    fsword_t f_type;
    fsword_t f_bsize;
    fsblkcnt64_t f_blocks;
    fsblkcnt64_t f_bfree;
    fsblkcnt64_t f_bavail;
    fsblkcnt64_t f_files;
    fsblkcnt64_t f_ffree;
    fsid_t  f_fsid;
    fsword_t f_namelen;
    fsword_t f_frsize;
    fsword_t f_flags;
    fsword_t f_spare[4];
};

/*@
requires \valid(path);
requires \valid(buf);
assigns \result, *buf, errno \from path[..];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int statfs(const char *path, struct statfs *buf);

/*@
requires \valid(buf);
assigns \result, *buf, errno \from fildes;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fstatfs(int fildes, struct statfs *buf);

/*@
requires \valid(path);
requires \valid(buf);
assigns \result, *buf, errno \from path[..];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int statfs64(const char *path, struct statfs64 *buf);

/*@
requires \valid(buf);
assigns \result, *buf, errno \from fildes;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fstatfs64(int fildes, struct statfs64 *buf);

#endif /* LIBC_SYS_STATFS_H_ */
