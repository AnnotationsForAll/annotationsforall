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

/* ISO C: 7.26 */
#ifndef __FC_WCTYPE_H
#define __FC_WCTYPE_H

#include "__gt_fc_define_locale_t.h"
#include "__fc_define_wint_t.h"
#include "features.h"
#include "wchar.h"

__BEGIN_DECLS

typedef int wctrans_t;
typedef int wctype_t;

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswalnum(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswalpha(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswascii(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswblank(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswcntrl(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswdigit(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswgraph(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswlower(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswnumber(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswprint(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswpunct(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswspace(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswupper(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
int iswxdigit(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
wint_t towlower(wint_t wc);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc;
*/
wint_t towupper(wint_t wc);

/*@
axiomatic WCTypes {
    logic boolean valid_wctype(wctype_t type);
    logic boolean valid_wctrans(wctrans_t type);
}
*/

/*@
requires \valid(type);
assigns \result \from type[..];
ensures \result != 0 ==> valid_wctype(\result);
*/
wctype_t  wctype(const char * type);

/*@
requires valid_wctype(desc);
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, desc;
*/
int iswctype(wint_t wc, wctype_t desc);

/*@
requires \valid(type);
assigns \result \from type[..];
ensures \result != 0 ==> valid_wctrans(\result);
*/
wctrans_t wctrans(const char * type);

/*@
requires valid_wctrans(desc);
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, desc;
*/
wint_t towctrans(wint_t wc, wctrans_t desc);

/* POSIX */

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswalnum_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswalpha_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswascii_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswblank_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswcntrl_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswdigit_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswgraph_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswlower_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswnumber_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswprint_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswpunct_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswspace_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswupper_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
int iswxdigit_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
wint_t towlower_l(wint_t wc, locale_t locale);

/*@
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, locale;
*/
wint_t towupper_l(wint_t wc, locale_t locale);

/*@
requires \valid(type);
assigns \result \from type[..], locale;
ensures \result != 0 ==> valid_wctype(\result);
*/
wctype_t  wctype_l(const char * type, locale_t locale);

/*@
requires valid_wctype(desc);
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, desc, locale;
*/
int iswctype_l(wint_t wc, wctype_t desc, locale_t locale);

/*@
requires \valid(type);
assigns \result \from type[..], locale;
ensures \result != 0 ==> valid_wctrans(\result);
*/
wctrans_t wctrans_l(const char * type, locale_t locale);

/*@
requires valid_wctrans(desc);
requires representable_as_wchar: (wchar_t)wc == wc || wc == WEOF;
assigns \result \from wc, desc, locale;
*/
wint_t towctrans_l(wint_t wc, wctrans_t desc, locale_t locale);

/* Unknown; provided by frama-c */

int iswhexnumber(wint_t wc);
int iswideogram(wint_t wc);
int iswphonogram(wint_t wc);
int iswrune(wint_t wc);
int iswspecial(wint_t wc);

__END_DECLS

#endif
