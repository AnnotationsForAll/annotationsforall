/*
 * fts.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_FTS_H_
#define LIBC_FTS_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "__fc_define_stat.h"
#include "__fc_string_axiomatic.h"
#include "__gt_fc_argv_axiomatic.h"

#define FTS_D         0
#define FTS_DC        1
#define FTS_DEFAULT   2
#define FTS_DNR       3
#define FTS_DOT       4
#define FTS_DP        5
#define FTS_ERR       6
#define FTS_F         7
#define FTS_NS        8
#define FTS_NSOK      9
#define FTS_SL        10
#define FTS_SLNONE    11

#define FTS_COMFOLLOW (1 << 0)
#define FTS_LOGICAL   (1 << 1)
#define FTS_NOCHDIR   (1 << 2)
#define FTS_NOSTAT    (1 << 3)
#define FTS_PHYSICAL  (1 << 4)
#define FTS_SEEDOT    (1 << 5)
#define FTS_XDEV      (1 << 6)

#define FTS_NAMEONLY  1

#define FTS_AGAIN     0
#define FTS_FOLLOW    1
#define FTS_SKIP      2

typedef void* FTS; // opaque type

typedef struct ftsent {
    unsigned short fts_info;
    char *fts_accpath;
    char *fts_path;
    short fts_pathlen;
    char *fts_name;
    short fts_namelen;
    short fts_level;
    int fts_errno;
    long fts_number;
    void *fts_pointer;
    struct ftsent *fts_parent;
    struct ftsent *fts_link;
    struct ftsent *fts_cycle;
    struct stat *fts_statp;
} FTSENT;

typedef void* FTS64; // opaque type

typedef struct ftsent64 {
    unsigned short fts_info;
    char *fts_accpath;
    char *fts_path;
    short fts_pathlen;
    char *fts_name;
    short fts_namelen;
    short fts_level;
    int fts_errno;
    long fts_number;
    void *fts_pointer;
    struct ftsent64 *fts_parent;
    struct ftsent64 *fts_link;
    struct ftsent64 *fts_cycle;
    struct stat64 *fts_statp;
} FTSENT64;

#define __gt_fc_ftsent_valid(f) (\valid(f) && valid_fts_accpath(f) && valid_fts_path(f) && valid_fts_name(f) && valid_fts_level(f) && valid_fts_number(f) && valid_fts_pointer(f) && valid_fts_parent(f) && valid_fts_link(f) && valid_fts_cycle(f) && valid_fts_statp(f))
#define __gt_fc_ftsent_valid64(f) (\valid(f) && valid_fts_accpath64(f) && valid_fts_path64(f) && valid_fts_name64(f) && valid_fts_level64(f) && valid_fts_number64(f) && valid_fts_pointer64(f) && valid_fts_parent64(f) && valid_fts_link64(f) && valid_fts_cycle64(f) && valid_fts_statp64(f))

/*@
axiomatic Fts {
    logic boolean is_fts_open(FTS* f) reads *f;

    logic boolean valid_fts_accpath(FTSENT* f) reads f->fts_accpath[0..strlen(f->fts_accpath)];
    logic boolean valid_fts_path(FTSENT* f) reads f->fts_path[0..f->fts_pathlen], f->fts_pathlen;
    logic boolean valid_fts_name(FTSENT* f) reads f->fts_name[0..f->fts_namelen], f->fts_namelen;
    logic boolean valid_fts_level(FTSENT* f) reads f->fts_level;
    logic boolean valid_fts_number(FTSENT* f) reads f->fts_number;
    logic boolean valid_fts_pointer(FTSENT* f) reads f->fts_pointer;
    logic boolean valid_fts_parent(FTSENT* f) reads f->fts_parent;
    logic boolean valid_fts_link(FTSENT* f) reads f->fts_link;
    logic boolean valid_fts_cycle(FTSENT* f) reads f->fts_cycle;
    logic boolean valid_fts_statp(FTSENT* f) reads f->fts_statp;

    axiom ftsent_valid_1: \forall FTSENT* f; valid_fts_accpath(f) ==> f->fts_level != -1 ==> valid_string(f->fts_accpath);
    axiom ftsent_valid_2: \forall FTSENT* f; valid_fts_path(f) ==> f->fts_level != -1 ==> valid_string(f->fts_path);
    axiom ftsent_valid_3: \forall FTSENT* f; valid_fts_path(f) ==> f->fts_level != -1 ==> \valid(f->fts_path+(0..f->fts_pathlen));
    axiom ftsent_valid_4: \forall FTSENT* f; valid_fts_name(f) ==> f->fts_level != -1 ==> valid_string(f->fts_name);
    axiom ftsent_valid_5: \forall FTSENT* f; valid_fts_name(f) ==> f->fts_level != -1 ==> \valid(f->fts_name+(0..f->fts_namelen));
    axiom ftsent_valid_6: \forall FTSENT* f; valid_fts_level(f) ==> f->fts_level >= -1;
    axiom ftsent_valid_7: \forall FTSENT* f; valid_fts_number(f) ==> f->fts_number == 0;
    axiom ftsent_valid_8: \forall FTSENT* f; valid_fts_pointer(f) ==> f->fts_pointer == \null;
    axiom ftsent_valid_9: \forall FTSENT* f; valid_fts_parent(f) ==> f->fts_level != -1 ==> f->fts_parent != \null && __gt_fc_ftsent_valid(f->fts_parent);
    axiom ftsent_valid_10: \forall FTSENT* f; valid_fts_link(f) ==> f->fts_level != -1 ==> f->fts_link != \null ==> \valid(f->fts_link) && __gt_fc_ftsent_valid(f->fts_link) && valid_fts_link(f);
}

axiomatic Fts64 {
    logic boolean is_fts_open64(FTS64* f) reads *f;

    logic boolean valid_fts_accpath64(FTSENT64* f) reads f->fts_accpath[0..strlen(f->fts_accpath)];
    logic boolean valid_fts_path64(FTSENT64* f) reads f->fts_path[0..f->fts_pathlen], f->fts_pathlen;
    logic boolean valid_fts_name64(FTSENT64* f) reads f->fts_name[0..f->fts_namelen], f->fts_namelen;
    logic boolean valid_fts_level64(FTSENT64* f) reads f->fts_level;
    logic boolean valid_fts_number64(FTSENT64* f) reads f->fts_number;
    logic boolean valid_fts_pointer64(FTSENT64* f) reads f->fts_pointer;
    logic boolean valid_fts_parent64(FTSENT64* f) reads f->fts_parent;
    logic boolean valid_fts_link64(FTSENT64* f) reads f->fts_link;
    logic boolean valid_fts_cycle64(FTSENT64* f) reads f->fts_cycle;
    logic boolean valid_fts_statp64(FTSENT64* f) reads f->fts_statp;

    axiom ftsent64_valid_1: \forall FTSENT64* f; valid_fts_accpath64(f) ==> f->fts_level != -1 ==> valid_string(f->fts_accpath);
    axiom ftsent64_valid_2: \forall FTSENT64* f; valid_fts_path64(f) ==> f->fts_level != -1 ==> valid_string(f->fts_path);
    axiom ftsent64_valid_3: \forall FTSENT64* f; valid_fts_path64(f) ==> f->fts_level != -1 ==> \valid(f->fts_path+(0..f->fts_pathlen));
    axiom ftsent64_valid_4: \forall FTSENT64* f; valid_fts_name64(f) ==> f->fts_level != -1 ==> valid_string(f->fts_name);
    axiom ftsent64_valid_5: \forall FTSENT64* f; valid_fts_name64(f) ==> f->fts_level != -1 ==> \valid(f->fts_name+(0..f->fts_namelen));
    axiom ftsent64_valid_6: \forall FTSENT64* f; valid_fts_level64(f) ==> f->fts_level >= -1;
    axiom ftsent64_valid_7: \forall FTSENT64* f; valid_fts_number64(f) ==> f->fts_number == 0;
    axiom ftsent64_valid_8: \forall FTSENT64* f; valid_fts_pointer64(f) ==> f->fts_pointer == \null;
    axiom ftsent64_valid_9: \forall FTSENT64* f; valid_fts_parent64(f) ==> f->fts_level != -1 ==> f->fts_parent != \null && __gt_fc_ftsent_valid64(f->fts_parent);
    axiom ftsent64_valid_10: \forall FTSENT64* f; valid_fts_link64(f) ==> f->fts_level != -1 ==> f->fts_link != \null ==> \valid(f->fts_link) && __gt_fc_ftsent_valid64(f->fts_link) && valid_fts_link64(f);
}
*/

/*@
requires \exists size_t i; argv_count_pred(path_argv, i);
assigns \result;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> is_fts_open(\result);
*/
FTS *fts_open(char * const *path_argv, int options, int (*compar)(const FTSENT **, const FTSENT **));

/*@
requires \valid(ftsp);
requires is_fts_open(ftsp);
assigns \result, *ftsp;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> __gt_fc_ftsent_valid(\result);
ensures \result != \null ==> \result->fts_level >= 0;
ensures is_fts_open(ftsp);
*/
FTSENT *fts_read(FTS *ftsp);

/*@
requires \valid(ftsp);
requires is_fts_open(ftsp);
assigns \result, *ftsp;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> __gt_fc_ftsent_valid(\result);
ensures \result != \null ==> \result->fts_level >= 0;
ensures \result != \null ==> valid_fts_link(\result);
ensures is_fts_open(ftsp);
*/
FTSENT *fts_children(FTS *ftsp, int options);

/*@
requires \valid(ftsp);
requires is_fts_open(ftsp);
requires \valid(f);
assigns \result, *ftsp, *f;
ensures \result == -1 || \result == 0;
ensures is_fts_open(ftsp);
*/
int fts_set(FTS *ftsp, FTSENT *f, int options);

/*@
requires \valid(ftsp);
requires is_fts_open(ftsp);
assigns \result, *ftsp;
ensures !is_fts_open(ftsp);
ensures \result == -1 || \result == 0;
*/
int fts_close(FTS *ftsp);

/*@
requires \exists size_t i; argv_count_pred(path_argv, i);
assigns \result;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> is_fts_open64(\result);
*/
FTS64 *fts64_open(char * const *path_argv, int options, int (*compar)(const FTSENT64 **, const FTSENT64 **));

/*@
requires \valid(ftsp);
requires is_fts_open64(ftsp);
assigns \result, *ftsp;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> __gt_fc_ftsent_valid64(\result);
ensures \result != \null ==> \result->fts_level >= 0;
ensures is_fts_open64(ftsp);
*/
FTSENT64 *fts64_read(FTS64 *ftsp);

/*@
requires \valid(ftsp);
requires is_fts_open64(ftsp);
assigns \result, *ftsp;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> __gt_fc_ftsent_valid64(\result);
ensures \result != \null ==> \result->fts_level >= 0;
ensures \result != \null ==> valid_fts_link64(\result);
ensures is_fts_open64(ftsp);
*/
FTSENT64 *fts64_children(FTS64 *ftsp, int options);

/*@
requires \valid(ftsp);
requires is_fts_open64(ftsp);
requires \valid(f);
assigns \result, *ftsp, *f;
ensures \result == -1 || \result == 0;
ensures is_fts_open64(ftsp);
*/
int fts64_set(FTS64 *ftsp, FTSENT64 *f, int options);

/*@
requires \valid(ftsp);
requires is_fts_open64(ftsp);
assigns \result, *ftsp;
ensures !is_fts_open64(ftsp);
ensures \result == -1 || \result == 0;
*/
int fts64_close(FTS64 *ftsp);

#endif /* LIBC_FTS_H_ */
