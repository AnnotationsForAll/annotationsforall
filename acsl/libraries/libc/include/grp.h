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

#ifndef __FC_GRP_H
#define __FC_GRP_H
#include "features.h"
#include "__fc_define_file.h"
#include "__fc_string_axiomatic.h"
#include "__gt_fc_file_axioms.h"
#include "__fc_define_uid_and_gid.h"
#include "__fc_define_size_t.h"
#include "__gt_fc_argv_axiomatic.h"
#include "errno.h"

__BEGIN_DECLS

#define NSS_BUFLEN_GROUP 1024

struct group {
    char *gr_name;
    gid_t gr_gid;
    char **gr_mem;
    /* GNU Extension Members */
    char *gr_passwd;
};

/*@
assigns \nothing;
*/
void endgrent(void);

/*@
assigns \result;
ensures \result != \null ==> \valid(\result);
*/
struct group *getgrent(void);

/*@
assigns \nothing;
*/
void setgrent(void);

/*@
assigns \result \from gid;
ensures \result != \null ==> \valid(\result);
*/
struct group *getgrgid(gid_t gid);

/*@
requires \valid(name);
assigns \result \from name[..];
ensures \result != \null ==> \valid(\result);
*/
struct group *getgrnam(const char *name);

/* GNU Extensions */

/*@
requires \valid(user);
assigns \result \from user[0..], group;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno == EPERM : errno == \old(errno);
*/
int initgroups(const char *user, gid_t group);

/*@
requires \valid(groups+(0..count-1));
assigns \result \from count, groups[0..count-1];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno == EPERM : errno == \old(errno);
*/
int setgroups(size_t count, const gid_t *groups);

/*@
requires \valid(user);
requires \valid(ngroups);
requires *ngroups >= 0;
requires \valid(groups+(0..*ngroups-1));
assigns \result, groups[0..*ngroups-1], *ngroups \from user[0..], *ngroups;
ensures \result == -1 ? *ngroups >= 0 : *ngroups == \old(*ngroups);
*/
int getgrouplist(const char *user, gid_t group, gid_t *groups, int *ngroups);

/*@
requires file_is_open(stream);
assigns \result \from stream;
ensures \result != \null ==> \valid(\result);
*/
struct group * fgetgrent (FILE *stream);

/*@
requires file_is_open(stream);
requires \valid_read(p);
requires \valid_read(p->gr_name);
requires \valid_read(p->gr_passwd);
requires p->gr_mem != \null ==> \exists size_t i; argv_count_pred(p->gr_mem, i);
assigns errno, \result, *stream \from *p, *stream;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int putgrent(const struct group *restrict p, FILE *restrict stream);

/*@
requires \valid(name);
requires \valid(result_buf);
requires \valid(buffer+(0..buflen-1));
requires \valid(result);
assigns errno, \result, *result, *result_buf, buffer[0..buflen-1];
ensures \result != 0 ==> *result == \null;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int getgrnam_r(const char *name, struct group *result_buf, char *buffer, size_t buflen, struct group **result);

/*@
requires \valid(result_buf);
requires \valid(buffer+(0..buflen-1));
requires \valid(result);
assigns errno, \result, *result, *result_buf, buffer[0..buflen-1];
ensures \result != 0 ==> *result == \null;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int getgrent_r(struct group *restrict result_buf, char *restrict buffer, size_t buflen, struct group **restrict result);

/*@
requires \valid(result_buf);
requires \valid(buffer+(0..buflen-1));
requires \valid(result);
assigns errno, \result, *result, *result_buf, buffer[0..buflen-1];
ensures \result != 0 ==> *result == \null;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int getgrgid_r(gid_t gid, struct group *result_buf, char *buffer, size_t buflen, struct group **result);

/*@
requires file_is_open(stream);
requires \valid(result_buf);
requires \valid(buffer+(0..buflen-1));
requires \valid(result);
assigns *result, *result_buf, buffer[0..buflen-1], \result \from stream;
ensures *result != \null ==> \valid(*result);
*/
int fgetgrent_r (FILE *stream, struct group *result_buf, char *buffer, size_t buflen, struct group **result);

__END_DECLS

#endif

