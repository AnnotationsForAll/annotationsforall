/*
 * ftw.h
 *
 *  Created on: Jul 15, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_FTW_H_
#define LIBC_FTW_H_

#include "sys/stat.h"
#include "errno.h"

typedef struct FTW {
    int base;
    int level;
} FTW;

#define FTW_F 1
#define FTW_D 2
#define FTW_DNR 4
#define FTW_DP 8
#define FTW_NS 16
#define FTW_SL 32
#define FTW_SLN 64

#define FTW_PHYS         (1 << 0)
#define FTW_MOUNT        (1 << 1)
#define FTW_DEPTH        (1 << 2)
#define FTW_CHDIR        (1 << 3)
#define FTW_ACTIONRETVAL (1 << 4)

/*@
// The ftw() function is marked obsolescent.
requires \false;
assigns \result, errno \from path[..], *fn, n;
*/
int ftw(const char  *path, int (*fn)(const char *, const struct stat *, int), int n);

/*@
requires \valid(path);
requires fn != \null;
assigns \result, errno \from path[..], *fn, fd_limit, flags;
*/
int nftw(const char *path, int (*fn)(const char *, const struct stat *, int, struct FTW *), int fd_limit, int flags);

/* GNU Extensions */

#define FTW_CONTINUE      0
#define FTW_STOP          1
#define FTW_SKIP_SUBTREE  2
#define FTW_SKIP_SIBLINGS 3

typedef int (*__ftw_func_t) (const char *, const struct stat *, int);
typedef int (*__ftw64_func_t) (const char *, const struct stat64 *, int);
typedef int (*__nftw_func_t) (const char *, const struct stat *, int, struct FTW *);
typedef int (*__nftw64_func_t) (const char *, const struct stat64 *, int, struct FTW *);

/*@
// The ftw() function is marked obsolescent.
requires \false;
assigns \result, errno \from path[..], *fn, n;
*/
int ftw64(const char  *path, int (*fn)(const char *, const struct stat64 *, int), int n);

/*@
requires \valid(path);
requires fn != \null;
assigns \result, errno \from path[..], *fn, fd_limit, flags;
*/
int nftw64(const char *path, int (*fn)(const char *, const struct stat64 *, int, struct FTW *), int fd_limit, int flags);

#endif /* LIBC_FTW_H_ */
