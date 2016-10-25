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

#ifndef __FC_NL_TYPES
#define __FC_NL_TYPES
#include "features.h"
__BEGIN_DECLS

typedef unsigned long nl_catd;
typedef unsigned long nl_item;
#define NL_SETD 0
#define NL_CAT_LOCALE 1

#include "errno.h"

/*@
axiomatic IsCatOpen {
    logic boolean is_cat_open{L}(nl_catd catd) reads catd;
}
*/

/*@
requires \valid(name);
assigns \result \from name[..], oflag;
ensures \result != (nl_catd) -1 ==> is_cat_open(\result);
*/
nl_catd catopen(const char *name, int oflag);

/*@
requires is_cat_open(catd);
assigns \result, errno \from catd;
ensures \result == 0 || \result == -1;
ensures \result != -1 ==> !is_cat_open(catd);
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int catclose(nl_catd catd);

/*@
requires is_cat_open(catd);
assigns \result \from catd, set_id, msg_id, s[..];
ensures \valid(\result);
*/
char *catgets(nl_catd catd, int set_id, int msg_id, const char *s);

__END_DECLS

#endif
