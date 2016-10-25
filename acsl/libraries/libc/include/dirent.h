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

#ifndef __FC_DIRENT_H
#define __FC_DIRENT_H
#include "features.h"

#include "errno.h"

#include "__fc_define_ino_t.h"
#include "__fc_define_ssize_t.h"
#include "__fc_define_size_t.h"
#include "__fc_define_off_t.h"

__BEGIN_DECLS

struct dirent {
    ino_t          d_ino;       /* inode number */
    off_t          d_off;       /* offset to the next dirent */
    unsigned short d_reclen;    /* length of this record */
    unsigned char  d_type;      /* type of file; not supported
                                   by all file system types */
    char           d_name[256]; /* filename */
};

typedef struct DIR {
  unsigned int __fc_dir_id;
  unsigned int __fc_dir_position;
  struct stat* __fc_dir_inode;
  struct dirent ** __fc_dir_entries;
} DIR;

//@ ghost DIR __fc_opendir[__FC_FOPEN_MAX];
//@ ghost const DIR* _p__fc_opendir = __fc_opendir;

/*@
axiomatic IsOpenDir {
    logic boolean is_dir_open{L}(DIR* dirp) reads dirp;
}
*/

/*@
requires \valid(d1) && \valid(d2);
requires \valid(*d1) && \valid(*d2);
assigns \result \from **d1, **d2;
*/
int alphasort(const struct dirent **d1, const struct dirent **d2);

/*@
requires is_dir_open(dirp);
assigns \result, *dirp \from dirp, *dirp, _p__fc_opendir;
assigns __FC_errno \from dirp, *dirp, _p__fc_opendir;
ensures (\result == 0 && dirp->__fc_dir_inode == \null && !is_dir_open(dirp)) || \result == -1;
*/
int closedir(DIR *dirp);

/*@
requires is_dir_open(dirp);
assigns \result \from *dirp;
ensures \result >= -1;
*/
int dirfd(DIR *dirp);

/*@
assigns \result \from fd, _p__fc_opendir;
ensures \result == \null || \valid(\result);
ensures \result != \null ==> \result->__fc_dir_inode != \null;
ensures \result != \null ==> is_dir_open(\result);
*/
DIR *fdopendir(int fd);

/*@
assigns \result \from path[0..], _p__fc_opendir;
assigns __FC_errno \from path[0..], _p__fc_opendir;
ensures \result == \null || \valid(\result);
ensures \result != \null ==> \result->__fc_dir_inode != \null;
ensures \result != \null ==> is_dir_open(\result);
*/
DIR *opendir(const char *path);

/*@
requires is_dir_open(dirp);
assigns \result \from *dirp, _p__fc_opendir;
assigns dirp->__fc_dir_position \from dirp->__fc_dir_position;
assigns __FC_errno \from dirp, *dirp, _p__fc_opendir;
ensures \result == \null || \valid(\result);
*/
struct dirent *readdir(DIR *dirp);

/*@
requires is_dir_open(dirp);
requires \valid(entry);
requires \valid(result);
assigns \result, *entry, *result \from *dirp, _p__fc_opendir, *entry, *result;
assigns dirp->__fc_dir_position \from dirp->__fc_dir_position;
assigns __FC_errno \from dirp, *dirp, _p__fc_opendir;
ensures \result == 0 || \result == -1;
*/
int readdir_r(DIR * dirp, struct dirent * entry, struct dirent ** result);

/*@
requires is_dir_open(dirp);
assigns *dirp \from *dirp;
*/
void rewinddir(DIR *dirp);

/*@
requires \valid(namelist);
requires compar != \null;
requires \valid(dir);
assigns \result, *namelist \from dir[..], *sel, *compar;
ensures \result >= -1;
ensures \result != -1 ==> \valid(*namelist+(0..\result));
*/
int scandir(const char *dir, struct dirent ***namelist, int (*sel)(const struct dirent *), int (*compar)(const struct dirent **, const struct dirent **));

/*@
requires is_dir_open(dirp);
assigns *dirp \from loc;
*/
void seekdir(DIR *dirp, long loc);

/*@
requires is_dir_open(dirp);
assigns \result \from *dirp;
*/
long telldir(DIR *dirp);

/* File types for `d_type'.  */
enum
  {
    DT_UNKNOWN = 0,
# define DT_UNKNOWN DT_UNKNOWN
    DT_FIFO = 1,
# define DT_FIFO    DT_FIFO
    DT_CHR = 2,
# define DT_CHR     DT_CHR
    DT_DIR = 4,
# define DT_DIR     DT_DIR
    DT_BLK = 6,
# define DT_BLK     DT_BLK
    DT_REG = 8,
# define DT_REG     DT_REG
    DT_LNK = 10,
# define DT_LNK     DT_LNK
    DT_SOCK = 12,
# define DT_SOCK    DT_SOCK
    DT_WHT = 14
# define DT_WHT     DT_WHT
  };

/* Convert between stat structure types and directory types.  */
# define IFTODT(mode)   (((mode) & 0170000) >> 12)
# define DTTOIF(dirtype)    ((dirtype) << 12)

#define d_fileno d_ino

/* GNU Extensions */

struct dirent64 {
    ino_t          d_ino;       /* inode number */
    off_t          d_off;       /* offset to the next dirent */
    unsigned short d_reclen;    /* length of this record */
    unsigned char  d_type;      /* type of file; not supported
                                   by all file system types */
    char           d_name[256]; /* filename */
};

/*@
requires \valid(d1) && \valid(d2);
requires \valid(*d1) && \valid(*d2);
assigns \result \from **d1, **d2;
*/
int versionsort(const struct dirent **d1, const struct dirent **d2);

/*@
requires is_dir_open(dirp);
assigns \result \from *dirp, _p__fc_opendir;
assigns dirp->__fc_dir_position \from dirp->__fc_dir_position;
assigns __FC_errno \from dirp, *dirp, _p__fc_opendir;
ensures \result == \null || \valid(\result);
*/
struct dirent64 * readdir64(DIR *dirp);

/*@
requires is_dir_open(dirp);
requires \valid(entry);
requires \valid(result);
assigns \result, *entry, *result \from *dirp, _p__fc_opendir, *entry, *result;
assigns dirp->__fc_dir_position \from dirp->__fc_dir_position;
assigns __FC_errno \from dirp, *dirp, _p__fc_opendir;
ensures \result == 0 || \result == -1;
*/
int readdir64_r(DIR *dirp, struct dirent64 *entry, struct dirent64 **result);

/*@
requires \valid(namelist);
requires compar != \null;
requires \valid(dir);
assigns \result, *namelist \from dir[..], *sel, *compar;
ensures \result >= -1;
ensures \result != -1 ==> \valid(*namelist+(0..\result));
*/
int scandir64(const char *dir, struct dirent64 ***namelist, int (*sel)(const struct dirent64 *), int (*compar)(const struct dirent64 **, const struct dirent64 **));

/*@
requires \valid(d1) && \valid(d2);
requires \valid(*d1) && \valid(*d2);
assigns \result \from **d1, **d2;
*/
int alphasort64(const struct dirent64 **d1, const struct dirent **d2);

/*@
requires \valid(d1) && \valid(d2);
requires \valid(*d1) && \valid(*d2);
assigns \result \from **d1, **d2;
*/
int versionsort64(const struct dirent64 **d1, const struct dirent64 **d2);

/*@
requires \valid(buf+(0..nbytes-1));
requires \valid(basep);
requires 0 <= *basep < nbytes;
assigns \result, errno, buf[0..nbytes-1], *basep \from *basep, fd, nbytes;
ensures \result >= -1;
ensures \result == -1 ? *basep == \old(*basep) : *basep == \old(*basep) + \result;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t getdirentries(int fd, char *buf, size_t nbytes, off_t *basep);

/*@
requires \valid(buf+(0..nbytes-1));
requires \valid(basep);
requires 0 <= *basep < nbytes;
assigns \result, errno, buf[0..nbytes-1], *basep \from *basep, fd, nbytes;
ensures \result >= -1;
ensures \result == -1 ? *basep == \old(*basep) : *basep == \old(*basep) + \result;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t getdirentries64(int fd, char *buf, size_t nbytes, off64_t *basep);

/*@
requires \valid(namelist);
requires compar != \null;
requires \valid(dir);
assigns \result, *namelist \from dir[..], *sel, *compar, fd;
ensures \result >= -1;
ensures \result != -1 ==> \valid(*namelist+(0..\result));
*/
int scandirat(int fd, const char *restrict dir, struct dirent ***restrict namelist, int (*sel)(const struct dirent *), int (*compar)(const struct dirent **, const struct dirent **));

/*@
requires \valid(namelist);
requires compar != \null;
requires \valid(dir);
assigns \result, *namelist \from dir[..], *sel, *compar, fd;
ensures \result >= -1;
ensures \result != -1 ==> \valid(*namelist+(0..\result));
*/
int scandirat64(int fd, const char *restrict dir, struct dirent64 ***restrict namelist, int (*sel)(const struct dirent64 *), int (*compar)(const struct dirent64 **, const struct dirent64 **));

__END_DECLS

#endif

