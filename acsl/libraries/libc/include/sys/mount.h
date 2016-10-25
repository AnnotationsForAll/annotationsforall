/*
 * mount.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_MOUNT_H_
#define LIBC_SYS_MOUNT_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "errno.h"
#include "ioctl.h"

#define MS_MGC_VAL 0xC0ED0000
#define MS_MGC_MSK 0xffff0000

#define MS_BIND        (1 << 0)
#define MS_DIRSYNC     (1 << 1)
#define MS_LAZYTIME    (1 << 2)
#define MS_MANDLOCK    (1 << 3)
#define MS_MOVE        (1 << 4)
#define MS_NOATIME     (1 << 5)
#define MS_NODEV       (1 << 6)
#define MS_NODIRATIME  (1 << 7)
#define MS_NOEXEC      (1 << 8)
#define MS_NOSUID      (1 << 9)
#define MS_RDONLY      (1 << 10)
#define MS_RELATIME    (1 << 11)
#define MS_REMOUNT     (1 << 12)
#define MS_SILENT      (1 << 13)
#define MS_STRICTATIME (1 << 14)
#define MS_SYNCHRONOUS (1 << 15)

#define MNT_FORCE       (1 << 0)
#define MNT_DETACH      (1 << 1)
#define MNT_EXPIRE      (1 << 2)
#define UMOUNT_NOFOLLOW (1 << 3)

#define MS_RMT_MASK (MS_RDONLY|MS_SYNCHRONOUS|MS_MANDLOCK|MS_I_VERSION|MS_LAZYTIME)

#define BLKROSET     _IO(0x12, 93)
#define BLKROGET     _IO(0x12, 94)
#define BLKRRPART    _IO(0x12, 95)
#define BLKGETSIZE   _IO(0x12, 96)
#define BLKFLSBUF    _IO(0x12, 97)
#define BLKRASET     _IO(0x12, 98)
#define BLKRAGET     _IO(0x12, 99)
#define BLKFRASET    _IO(0x12,100)
#define BLKFRAGET    _IO(0x12,101)
#define BLKSECTSET   _IO(0x12,102)
#define BLKSECTGET   _IO(0x12,103)
#define BLKSSZGET    _IO(0x12,104)
#define BLKBSZGET    _IOR(0x12,112,size_t)
#define BLKBSZSET    _IOW(0x12,113,size_t)
#define BLKGETSIZE64 _IOR(0x12,114,size_t)

/*@
requires \valid(src);
requires \valid(dst);
requires \valid(fstype);
requires \valid(((char*)data));
assigns \result, errno \from src[0..], dst[0..], fstype[0..], flags, ((char*)data)[0..];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mount (const char *src, const char *dst, const char *fstype, unsigned long int flags, const void *data);

/*@
requires \valid(file);
assigns \result, errno \from file[0..];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int umount (const char *file);

/*@
requires \valid(file);
assigns \result, errno \from file[0..], flags;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int umount2 (const char *file, int flags);

#endif /* LIBC_SYS_MOUNT_H_ */
