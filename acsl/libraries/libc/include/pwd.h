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

#ifndef __FC_PWD_H__
#define __FC_PWD_H__
#include "features.h"

#include "__fc_define_uid_and_gid.h"
#include "__fc_define_file.h"
#include "__fc_string_axiomatic.h"
#include "__gt_fc_file_axioms.h"
#include "errno.h"

// for size_t
#include "stddef.h"

__BEGIN_DECLS

struct passwd {
    char *pw_name;
    char *pw_passwd;
    uid_t pw_uid;
    gid_t pw_gid;
    char *pw_gecos;
    char *pw_dir;
    char *pw_shell;
};

/*@
assigns \nothing;
*/
void endpwent(void);

/*@
assigns \result \from \nothing;
ensures \result != \null ==> \valid(\result);
*/
struct passwd *getpwent(void);

/*@
assigns \nothing;
*/
void setpwent(void);

/*@
requires \valid(name);
assigns \result \from name[..];
ensures \result != \null ==> \valid(\result);
*/
struct passwd *getpwnam(const char *name);

/*@
assigns \result \from uid;
ensures \result != \null ==> \valid(\result);
*/
struct passwd *getpwuid(uid_t uid);

/* GNU Extensions */

#define NSS_BUFLEN_PASSWD 1024

/*@
requires file_is_open(stream);
assigns \result \from stream;
ensures \result != \null ==> \valid(\result);
*/
struct passwd * fgetpwent (FILE *stream);

/*@
requires file_is_open(stream);
requires \valid(p);
assigns \result \from *p, stream;
ensures \result == -1 || \result == 0;
*/
int putpwent (const struct passwd *p, FILE *stream);

/*@
// This function is unsafe, as it could always overrun the buffer provided.
requires buf != \null ==> \valid(buf);
assigns errno, \result, buf[0..];
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> errno == \old(errno);
ensures buf == \null ==> errno == EINVAL;
*/
int getpw(uid_t uid, char *buf);

/*@
requires \valid(resultbuf);
requires \valid(buffer+(0..buflen-1));
requires \valid(result);
assigns \result, *resultbuf, buffer[0..buflen-1], *result;
ensures \result == 0 ==> *result == resultbuf;
ensures \result != 0 ==> *result == \null;
*/
int getpwent_r(struct passwd * resultbuf, char * buffer, size_t buflen, struct passwd ** result);

/*@
requires \valid_read(name);
requires \valid(resultbuf);
requires \valid(buffer+(0..buflen-1));
requires \valid(result);
assigns \result, *resultbuf, buffer[0..buflen-1], *result;
ensures \result == 0 ==> *result!= \null ==> *result == resultbuf;
ensures \result != 0 ==> *result == \null;
*/
int getpwnam_r(const char *name, struct passwd *resultbuf, char *buffer, size_t buflen, struct passwd **result);

/*@
requires \valid(resultbuf);
requires \valid(buffer+(0..buflen-1));
requires \valid(result);
assigns \result, *resultbuf, buffer[0..buflen-1], *result;
ensures \result == 0 ==> *result!= \null ==> *result == resultbuf;
ensures \result != 0 ==> *result == \null;
*/
int getpwuid_r(uid_t uid, struct passwd *resultbuf, char *buffer, size_t buflen, struct passwd **result);

/*@
requires file_is_open(stream);
requires \valid(resultbuf);
requires \valid(buffer+(0..buflen-1));
requires \valid(result);
assigns \result, *resultbuf, buffer[0..buflen-1], *result;
ensures \result == 0 ==> *result == resultbuf;
ensures \result != 0 ==> *result == \null;
*/
int fgetpwent_r(FILE *stream, struct passwd *resultbuf, char *buffer, size_t buflen, struct passwd **result);

__END_DECLS

#endif
