/**************************************************************************/
/*                                                                        */
/*  This file is part of Frama-C.                                         */
/*                                                                        */
/*  Copyright (C) 2007-2015                                               */
/*    CEA (Commissariat à l'énergie atomique et aux énergies              */
/*         alternatives)                                                  */
/*                                                                        */
/*  you can redistribute it and/or modify it under the terms of the GNU   */
/*  Lesser General Public License as published by the Free Software       */
/*  Foundation, version 2.1.                                              */
/*                                                                        */
/*  It is distributed in the hope that it will be useful,                 */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/*  GNU Lesser General Public License for more details.                   */
/*                                                                        */
/*  See the GNU Lesser General Public License version 2.1                 */
/*  for more details (enclosed in the file licenses/LGPLv2.1).            */
/*                                                                        */
/**************************************************************************/

#ifndef __FC_FCNTL
#define __FC_FCNTL
#include "features.h"

#include "__fc_define_off_t.h"
#include "__fc_define_pid_t.h"
#include "__fc_define_mode_t.h"
#include "__fc_define_size_t.h"
#include "__fc_define_ssize_t.h"
#include "__fc_define_iovec.h"
#include "__fc_define_seek_macros.h"
#include "__gt_fc_fcntl_macros.h"
#include "sys/stat.h"
#include "errno.h"

#define F_RDLCK     0
#define F_WRLCK     1
#define F_UNLCK     2
#define F_EXLCK     4
#define F_GETLK64   5
#define F_SETLK64   6
#define F_SETLKW64  7
#define F_SHLCK     8

__BEGIN_DECLS

struct flock {
    short int l_type;
    short int l_whence;
    off_t l_start;
    off_t l_len;
    pid_t l_pid;
};

#define F_DUPFD         1
#define F_GETFD         2
#define F_SETFD         3
#define F_GETFL         4
#define F_SETFL         5
#define F_GETLK         6
#define F_SETLK         7
#define F_SETLKW        8
#define F_GETOWN        9
#define F_SETOWN        10
#define F_SETSIG        11
#define F_GETSIG        12
#define F_SETOWN_EX     13
#define F_GETOWN_EX     14
#define F_SETLEASE      15
#define F_GETLEASE      16
#define F_NOTIFY        17
#define F_SETPIPE_SZ    18
#define F_GETPIPE_SZ    19
#define F_DUPFD_CLOEXEC 20

#define FD_CLOEXEC 1

#define AT_FDCWD            (1 << 0)
#define AT_SYMLINK_NOFOLLOW (1 << 1)
#define AT_REMOVEDIR        (1 << 2)
#define AT_SYMLINK_FOLLOW   (1 << 3)
#define AT_NO_AUTOMOUNT     (1 << 4)
#define AT_EMPTY_PATH       (1 << 5)
#define AT_EACCESS          (1 << 6)

#define O_RDONLY    0x0000
#define O_WRONLY    0x0001
#define O_RDWR      0x0002
#define O_ACCMODE   0x0003
#define O_NONBLOCK  0x0004
#define O_APPEND    0x0008
#define O_CREAT     0x0200
#define O_TRUNC     0x0400
#define O_EXCL      0x0800

#define O_NDELAY    O_NONBLOCK
#define O_SYNC         04010000
#define O_FSYNC      O_SYNC
#define O_ASYNC      020000

#define O_DIRECTORY    0200000
#define O_NOFOLLOW 0400000
#define O_CLOEXEC     02000000

#define O_DIRECT    040000
#define O_NOATIME     01000000


#define POSIX_FADV_NORMAL  0
#define POSIX_FADV_RANDOM  1
#define POSIX_FADV_SEQUENTIAL  2
#define POSIX_FADV_WILLNEED    3
#define POSIX_FADV_DONTNEED    4
#define POSIX_FADV_NOREUSE 5

/* Defined by POSIX 1003.1; BSD default, but must be distinct from O_RDONLY. */
#define O_NOCTTY 0x8000

/*@
requires \valid(filename);
assigns \result \from filename[0..], mode;
ensures \result >= -1;
*/
int creat(const char *filename, mode_t mode);

/*@
assigns \result \from fd, cmd;
*/
int fcntl(int fd, int cmd, ...);

/*@
requires \valid(filename);
assigns \result \from filename[0..], flags;
ensures \result >= -1;
*/
int open(const char *filename, int flags, ...);

/*@
requires \valid(filename);
assigns \result \from dirfd, filename[0..], flags;
ensures \result >= -1;
*/
int openat(int dirfd, const char *filename, int flags, ...);

/* The following functions are "fixed-argument" versions of open/fcntl. They
   are used when the translation of variadic function to fixed-adic is
   enabled */

/*@ requires valid_cmd: cmd == F_GETFD || cmd == F_GETFL ||
                        cmd == F_GETOWN ;
    assigns \result \from fd, cmd ; */
int __va_fcntl_void(int fd, int cmd);

/*@ requires valid_cmd: cmd == F_DUPFD || cmd == F_SETFD ||
                        cmd == F_SETFL || cmd == F_SETOWN ;
    assigns \result \from fd, cmd, arg ;*/
int __va_fcntl_int(int fd, int cmd, int arg);

/*@ requires valid_cmd: cmd == F_GETLK || cmd == F_SETLK ||
                        cmd == F_SETLKW ;
    requires valid_arg: \valid(arg) ;
    assigns \result, *arg \from fd, cmd, *arg ; */
int __va_fcntl_flock(int fd, int cmd, struct flock *arg);

/*@ requires valid_flag: !(flags & O_CREAT) ;
    assigns \result \from filename[0..], flags ; */
int __va_open_void(const char *filename, int flags);

/*@ assigns \result \from filename[0..], flags, mode ; */
int __va_open_mode_t(const char *filename, int flags, mode_t mode);

/*@ requires valid_flag: !(flags & O_CREAT) ;
    assigns \result \from dirfd, filename[0..], flags ; */
int __va_openat_void(int dirfd, const char *filename, int flags);

/*@ assigns \result \from dirfd, filename[0..], flags, mode ; */
int __va_openat_mode_t(int dirfd, const char *filename, int flags, mode_t mode);

/* GNU Extensions */

#define SYNC_FILE_RANGE_WAIT_BEFORE 1
#define SYNC_FILE_RANGE_WRITE 2
#define SYNC_FILE_RANGE_WAIT_AFTER 4

#define FALLOC_FL_KEEP_SIZE      (1 << 0)
#define FALLOC_FL_PUNCH_HOLE     (1 << 1)
#define FALLOC_FL_COLLAPSE_RANGE (1 << 2)
#define FALLOC_FL_ZERO_RANGE     (1 << 3)
#define FALLOC_FL_INSERT_RANGE   (1 << 4)

#define SPLICE_F_MOVE     (1 << 0)
#define SPLICE_F_NONBLOCK (1 << 1)
#define SPLICE_F_MORE     (1 << 2)
#define SPLICE_F_GIFT     (1 << 3)

#define DN_ACCESS    (1 << 0)
#define DN_MODIFY    (1 << 1)
#define DN_CREATE    (1 << 2)
#define DN_DELETE    (1 << 3)
#define DN_RENAME    (1 << 4)
#define DN_ATTRIB    (1 << 5)
#define DN_MULTISHOT (1 << 6)

#define LOCK_SH    (1 << 0)
#define LOCK_EX    (1 << 1)
#define LOCK_NB    (1 << 2)
#define LOCK_UN    (1 << 3)
#define LOCK_MAND  (1 << 4)
#define LOCK_READ  (1 << 5)
#define LOCK_WRITE (1 << 6)
#define LOCK_RW    (LOCK_READ | LOCK_WRITE)

#define MAX_HANDLE_SZ 128

struct file_handle {
    unsigned int handle_bytes;
    int handle_type;
    unsigned char f_handle[0];
};

/*@
requires \valid(filename);
assigns \result \from filename[0..], mode;
ensures \result >= -1;
*/
int creat64(const char *filename, mode_t mode);

/*@
assigns \result, errno;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int posix_fallocate (int fd, off_t offset, off_t length);

/*@
assigns \result, errno;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int posix_fallocate64 (int fd, off64_t offset, off64_t length);

/*@
assigns \result, errno;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int posix_fadvise(int fd, off_t offset, off_t len, int advice);

/*@
assigns \result, errno;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int posix_fadvise64(int fd, off64_t offset, off64_t len, int advice);

/*@
assigns \result, errno \from fd, offset, len, flags;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int sync_file_range(int fd, off64_t offset, off64_t len, unsigned int flags);

/*@
assigns \result, errno;
ensures \result == 0 || \result == -1;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int fallocate(int fd, int mode, off_t offset, off_t len);

/*@
assigns \result, errno;
ensures \result == 0 || \result == -1;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int fallocate64(int fd, int mode, off64_t offset, off64_t len);

/*@
requires \valid_read(filename);
requires \valid(((char*)handle)+(0..sizeof(struct file_handle)+handle->handle_bytes-1));
requires \valid(mount_id);
assigns \result, errno, *mount_id, ((char*)handle)[0..sizeof(struct file_handle)+handle->handle_bytes-1];
ensures 0 <= handle->handle_bytes <= MAX_HANDLE_SZ;
*/
int name_to_handle_at(int dirfd, const char *filename, struct file_handle *handle, int *mount_id, int flags);

/*@
requires \valid_read(((char*)handle)+(0..sizeof(struct file_handle)+handle->handle_bytes-1));
assigns \result, errno;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int open_by_handle_at(int mount_fd, struct file_handle *handle, int flags);

/*@
assigns \result, errno;
ensures \result == 0 || \result == -1;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
ssize_t readahead(int fd, off64_t offset, size_t count);

/*@
requires off_in != \null ==> \valid_read(off_in);
requires off_out != \null ==> \valid_read(off_out);
assigns \result, errno;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t splice(int fd_in, off64_t *off_in, int fd_out, off64_t *off_out, size_t len, unsigned int flags);

/*@
assigns \result, errno;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t tee(int fd_in, int fd_out, size_t len, unsigned int flags);

/*@
requires \valid_read(iov+(0..nr_segs-1));
requires \forall unsigned long i; 0 <= i < nr_segs ==> \valid(((char*)(iov[i].iov_base))+(0..iov[i].iov_len-1));
assigns \result, errno;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t vmsplice(int fd, const struct iovec *iov, unsigned long nr_segs, unsigned int flags);

/*@
requires \valid(filename);
assigns \result \from filename[0..], flags;
ensures \result >= -1;
*/
int open64(const char *filename, int flags, ...);

/*@
requires \valid(filename);
assigns \result \from dirfd, filename[0..], flags;
ensures \result >= -1;
*/
int openat64(int dirfd, const char *filename, int flags, ...);

/* BSD compatibility */

#define FAPPEND   O_APPEND
#define FFSYNC    O_FSYNC
#define FASYNC    O_ASYNC
#define FNONBLOCK O_NONBLOCK
#define FNDELAY   O_NDELAY

__END_DECLS

#endif
