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

#ifndef __FC_ICONV
#define __FC_ICONV
#include "features.h"
#include "__fc_define_size_t.h"
#include "errno.h"

__BEGIN_DECLS

typedef int iconv_t;

/*@
axiomatic IconvOpen {
    logic boolean is_iconv_open{L}(iconv_t cd) reads cd;
}
*/

/*@
requires is_iconv_open(cd);
assigns \result, *outbuf[0 .. *outbytesleft-1], *outbytesleft \from *inbuf[0 .. *inbytesleft-1], *inbytesleft;
*/
size_t  iconv(iconv_t cd, char **restrict inbuf, size_t *restrict inbytesleft, char **restrict outbuf, size_t *restrict outbytesleft);

/*@
requires is_iconv_open(cd);
assigns \result, errno \from cd;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> !is_iconv_open(cd);
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int iconv_close(iconv_t cd);

/*@ 
assigns \result \from tocode[..], fromcode[..];
ensures \result != ((iconv_t)-1) ==> is_iconv_open(\result);
*/
iconv_t iconv_open(const char *tocode, const char *fromcode);

__END_DECLS

#endif
