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

#ifndef __FC_SYS_STAT_H
#define __FC_SYS_STAT_H

#include "../__fc_define_mode_t.h"
#include "../__fc_define_stat.h"
#include "../__fc_string_axiomatic.h"
#include "time.h"
#include "errno.h"

/*@
requires valid_string(path);
assigns \result \from path[..], mode;
ensures \result == -1 || \result == 0;
*/
int chmod(const char *path, mode_t mode);

/*@
requires valid_string(path);
assigns \result \from path[..], mode, fd, flag;
ensures \result == -1 || \result == 0;
*/
int fchmodat(int fd, const char *path, mode_t mode, int flag);

/*@
assigns \result \from fildes, mode;
ensures \result == -1 || \result == 0;
*/
int fchmod(int fildes, mode_t mode);

/*@
requires \valid(buf);
assigns \result, *buf \from fildes;
ensures \result == -1 || \result == 0;
*/
int fstat(int fildes, struct stat *buf);

/*@
requires \valid(buf);
requires valid_string(path);
assigns \result, *buf \from fd, path[..], flag;
ensures \result == -1 || \result == 0;
*/
int fstatat(int fd, const char *restrict path, struct stat *restrict buf, int flag);

/*@
requires \valid(buf);
requires valid_string(path);
assigns \result, *buf \from path[..];
ensures \result == -1 || \result == 0;
*/
int lstat(const char *restrict path, struct stat *restrict buf);

/*@
requires \valid(buf);
requires valid_string(path);
assigns \result, *buf \from path[..];
ensures \result == -1 || \result == 0;
*/
int stat(const char *restrict path, struct stat *restrict buf);

/*@
requires valid_string(path);
assigns \result \from path[..], mode;
ensures \result == -1 || \result == 0;
*/
int mkdir(const char *path, mode_t mode);

/*@
requires valid_string(path);
assigns \result \from path[..], mode, fd;
ensures \result == -1 || \result == 0;
*/
int mkdirat(int fd, const char *path, mode_t mode);

/*@
requires valid_string(path);
assigns \result \from path[..], mode;
ensures \result == -1 || \result == 0;
*/
int mkfifo(const char *path, mode_t mode);

/*@
requires valid_string(path);
assigns \result \from path[..], mode, fd;
ensures \result == -1 || \result == 0;
*/
int mkfifoat(int fd, const char *path, mode_t mode);

/*@
requires valid_string(path);
assigns \result \from path[..], mode, dev;
ensures \result == -1 || \result == 0;
*/
int mknod(const char *path, mode_t mode, dev_t dev);

/*@
requires valid_string(path);
assigns \result \from path[..], mode, dev, fd;
ensures \result == -1 || \result == 0;
*/
int mknodat(int fd, const char *path, mode_t mode, dev_t dev);

/*@
assigns \result \from cmask;
*/
mode_t umask(mode_t cmask);

/*@
requires \valid(times+(0..1));
assigns \result, errno \from fd, times[0..1];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int futimens(int fd, const struct timespec * times);

/*@
requires \valid(times+(0..1));
requires \valid(path);
assigns \result, errno \from path[..], fd, times[0..1], flag;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int utimensat(int fd, const char *path, const struct timespec * times, int flag);

/* GNU Extensions */

#define UTIME_NOW  ((1l << 30) - 1l)
#define UTIME_OMIT ((1l << 30) - 2l)

/*@
assigns \result;
*/
mode_t getumask (void);

/*@
requires \valid(buf);
requires valid_string(path);
assigns \result, *buf \from path[..];
ensures \result == -1 || \result == 0;
*/
int stat64(const char *restrict path, struct stat64 *restrict buf);

/*@
requires \valid(buf);
assigns \result, *buf \from fildes;
ensures \result == -1 || \result == 0;
*/
int fstat64(int fildes, struct stat64 *buf);

/*@
requires \valid(buf);
requires valid_string(path);
assigns \result, *buf \from path[..];
ensures \result == -1 || \result == 0;
*/
int lstat64(const char *restrict path, struct stat64 *restrict buf);

/*@
assigns errno, \result;
ensures -1 <= \result <= 1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int isfdtype(int fd, int fdtype);

/*@
requires \valid(buf);
requires valid_string(path);
assigns \result, *buf \from fd, path[..], flag;
ensures \result == -1 || \result == 0;
*/
int fstatat64(int fd, const char *restrict path, struct stat64 *restrict buf, int flag);

/*@
requires valid_string(path);
assigns \result \from path[..], mode;
ensures \result == -1 || \result == 0;
*/
int lchmod (const char *path, mode_t mode);

#endif
