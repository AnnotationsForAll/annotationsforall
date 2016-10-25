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

#ifndef __FC_GLOB_H
#define __FC_GLOB_H
#include "features.h"

#include "__fc_machdep.h"

#define GLOB_ERR      (1 << 0)
#define GLOB_MARK     (1 << 1)
#define GLOB_NOSORT   (1 << 2)
#define GLOB_DOOFFS   (1 << 3)
#define GLOB_NOCHECK  (1 << 4)
#define GLOB_APPEND   (1 << 5)
#define GLOB_NOESCAPE (1 << 6)
#define GLOB_PERIOD   (1 << 7)

#define GLOB_NOSPACE 1
#define GLOB_ABORTED 2
#define GLOB_NOMATCH 3
#define GLOB_NOSYS   4

#define GLOB_ABEND GLOB_ABORTED

__BEGIN_DECLS

typedef struct {
  __SIZE_T gl_pathc;
  char **gl_pathv;
  __SIZE_T gl_offs;
  int gl_flags;
  
  /* If the GLOB_ALTDIRFUNC flag is set, the following functions
     are used instead of the normal file access functions.  */
  void (*gl_closedir) (void *);
#ifdef __USE_GNU
  struct dirent *(*gl_readdir) (void *);
#else
  void *(*gl_readdir) (void *);
#endif
  void *(*gl_opendir) (__const char *);
#ifdef __USE_GNU
  int (*gl_lstat) (__const char *__restrict, struct stat *__restrict);
  int (*gl_stat) (__const char *__restrict, struct stat *__restrict);
#else
  int (*gl_lstat) (__const char *__restrict, void *__restrict);
  int (*gl_stat) (__const char *__restrict, void *__restrict);
#endif
} glob_t;

/*@
axiomatic OpenGlob {
    logic boolean is_glob_open{L}(glob_t* glob) reads *glob;
}
*/

/*@
requires \valid(pattern);
requires \valid(pglob);
assigns \result, *pglob \from pattern[..], flags, *errfunc, *pglob;
ensures pglob->gl_pathc != 0 ==> \valid(pglob->gl_pathv+(0..pglob->gl_pathc+pglob->gl_offs-1));
ensures \result != 0 ==> is_glob_open(pglob);
*/
int glob(const char *restrict pattern, int flags, int(*errfunc)(const char *epath, int eerrno), glob_t *restrict pglob);

/*@
requires is_glob_open(pglob);
assigns *pglob \from *pglob;
ensures !is_glob_open(pglob);
*/
void globfree(glob_t *pglob);

/* GNU Extensions */

#define GLOB_MAGCHAR (1 << 9)
#define GLOB_AlTDIRFUNC (1 << 10)
#define GLOB_BRACE (1 << 11)
#define GLOB_NOMAGIC (1 << 12)
#define GLOB_TILDE (1 << 13)
#define GLOB_TILDE_CHECK (1 << 14)
#define GLOB_ONLYDIR (1 << 15)

typedef glob_t glob64_t;

/*@
requires \valid(pattern);
requires \valid(pglob);
assigns \result, *pglob \from pattern[..], flags, *errfunc, *pglob;
ensures pglob->gl_pathc != 0 ==> \valid(pglob->gl_pathv+(0..pglob->gl_pathc+pglob->gl_offs-1));
ensures \result != 0 ==> is_glob_open(pglob);
*/
int glob64(const char *restrict pattern, int flags, int(*errfunc)(const char *epath, int eerrno), glob64_t *restrict pglob);

/*@
requires is_glob_open(pglob);
assigns *pglob \from *pglob;
ensures !is_glob_open(pglob);
*/
void globfree64(glob64_t *pglob);

/*@
requires \valid_read(pattern);
assigns \result \from pattern[0..], quote;
ensures \result == 1 || \result == 0;
*/
int glob_pattern_p(const char *pattern, int quote);

__END_DECLS

#endif
