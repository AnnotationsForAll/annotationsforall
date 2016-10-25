/*
 * mntent.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_MNTENT_H_
#define LIBC_MNTENT_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "__fc_define_file.h"
#include "__fc_string_axiomatic.h"
#include "__gt_fc_file_axioms.h"
#include "paths.h"

#define MNTTAB  _PATH_MNTTAB
#define MOUNTED _PATH_MOUNTED

#define MNTTYPE_IGNORE "ignore"
#define MNTTYPE_NFS "nfs"
#define MNTTYPE_SWAP "swap"

#define MNTOPT_DEFAULTS "defaults"
#define MNTOPT_RO "ro"
#define MNTOPT_RW "rw"
#define MNTOPT_SUID "suid"
#define MNTOPT_NOSUID "nosuid"
#define MNTOPT_NOAUTO "noauto"

struct mntent {
    char *mnt_fsname;
    char *mnt_dir;
    char *mnt_type;
    char *mnt_opts;
    int mnt_freq;
    int mnt_passno;
};

/*@
requires \valid(file) && \valid(mode);
assigns \result \from file[0..], mode[0..];
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> file_has_stream(\result);
ensures \result != \null ==> file_is_open(\result);
ensures \result != \null ==> !file_error(\result);
ensures \result != \null ==> !file_eof(\result);
ensures \result==\null || (\valid(\result) && file_is_open(\result));
*/
FILE * setmntent (const char *file, const char *mode);

/*@
requires \valid(stream);
requires file_is_open(stream);
assigns *stream, \result \from *stream;
ensures \result == 1;
*/
int endmntent (FILE *stream);

/*@
requires \valid(stream);
requires file_is_open(stream);
assigns \result \from stream;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> \valid_read(\result->mnt_fsname);
ensures \result != \null ==> \valid_read(\result->mnt_dir);
ensures \result != \null ==> \valid_read(\result->mnt_type);
ensures \result != \null ==> \valid_read(\result->mnt_opts);
*/
struct mntent * getmntent (FILE *stream);

/*@
requires \valid(stream);
requires file_is_open(stream);
requires \valid(result);
requires \valid(buffer+(0..bufsize-1));
assigns \result, *result, buffer[0..bufsize-1] \from stream;
ensures \result != \null ==> \result == result;
*/
struct mntent * getmntent_r (FILE *stream, struct mntent *result, char *buffer, int bufsize);

/*@
requires \valid(stream);
requires file_is_open(stream);
requires \valid(mnt);
assigns \result \from stream, *mnt;
ensures \result == 0 || \result == 1;
*/
int addmntent (FILE *stream, const struct mntent *mnt);

/*@
requires \valid_read(mnt);
requires \valid_read(mnt->mnt_opts);
requires \valid(opt);
assigns \result \from *mnt, opt[0..];
ensures \result != \null ==> \base_addr(\result) == \base_addr(mnt->mnt_opts) && \result >= mnt->mnt_opts;
*/
char * hasmntopt (const struct mntent *mnt, const char *opt);

#endif /* LIBC_MNTENT_H_ */
