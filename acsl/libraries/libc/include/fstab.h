/*
 * fstab.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef FSTAB_H_
#define FSTAB_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "paths.h"

#define FSTAB _PATH_FSTAB

#define FSTAB_RW "rw"
#define FSTAB_RQ "rq"
#define FSTAB_RO "ro"
#define FSTAB_SW "sw"
#define FSTAB_XX "xx"

struct fstab {
    char *fs_spec;
    char *fs_file;
    char *fs_vfstype;
    char *fs_mntops;
    const char *fs_type;
    int fs_freq;
    int fs_passno;
};

/*@
assigns \result \from \nothing;
ensures \result == 0 || \result == 1;
*/
int setfsent (void);

/*@
assigns \nothing;
*/
void endfsent (void);

/*@
assigns \result \from \nothing;
ensures \result != \null ==> \valid(\result);
*/
struct fstab * getfsent (void);

/*@
requires \valid(name);
assigns \result \from name[0..];
ensures \result != \null ==> \valid(\result);
*/
struct fstab * getfsspec (const char *name);

/*@
requires \valid(name);
assigns \result \from name[0..];
ensures \result != \null ==> \valid(\result);
*/
struct fstab * getfsfile (const char *name);

#endif /* FSTAB_H_ */
