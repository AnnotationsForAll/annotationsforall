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

#ifndef __FC_LOCALE
#define __FC_LOCALE
#include "features.h"

__BEGIN_DECLS

#include "__gt_fc_define_locale_t.h"
#include "errno.h"

/* Structure giving information about numeric and monetary notation.  */
struct lconv {
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *int_curr_symbol;
    char *currency_symbol;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
    char int_p_cs_precedes;
    char int_p_sep_by_space;
    char int_n_cs_precedes;
    char int_n_sep_by_space;
    char int_p_sign_posn;
    char int_n_sign_posn;
};

#include "__fc_define_null.h"
#include "__fc_string_axiomatic.h"

#define LC_ALL            0
#define LC_COLLATE        1
#define LC_CTYPE          2
#define LC_MESSAGES       6
#define LC_MONETARY       3
#define LC_NUMERIC        4
#define LC_TIME           5
#define LC_PAPER          6
#define LC_NAME           7
#define LC_ADDRESS        8
#define LC_TELEPHONE      9
#define LC_MEASUREMENT    10
#define LC_IDENTIFICATION 11

#define LC_CTYPE_MASK          (1 << LC_CTYPE)
#define LC_NUMERIC_MASK        (1 << LC_NUMERIC)
#define LC_TIME_MASK           (1 << LC_TIME)
#define LC_COLLATE_MASK        (1 << LC_COLLATE)
#define LC_MONETARY_MASK       (1 << LC_MONETARY)
#define LC_MESSAGES_MASK       (1 << LC_MESSAGES)
#define LC_PAPER_MASK          (1 << LC_PAPER)
#define LC_NAME_MASK           (1 << LC_NAME)
#define LC_ADDRESS_MASK        (1 << LC_ADDRESS)
#define LC_TELEPHONE_MASK      (1 << LC_TELEPHONE)
#define LC_MEASUREMENT_MASK    (1 << LC_MEASUREMENT)
#define LC_IDENTIFICATION_MASK (1 << LC_IDENTIFICATION)
#define LC_ALL_MASK            (LC_CTYPE_MASK | LC_NUMERIC_MASK | LC_TIME_MASK | LC_COLLATE_MASK | LC_MONETARY_MASK | LC_MESSAGES_MASK | LC_PAPER_MASK | LC_NAME_MASK | LC_ADDRESS_MASK | LC_TELEPHONE_MASK | LC_MEASUREMENT_MASK | LC_IDENTIFICATION_MASK)

#define LC_GLOBAL_LOCALE ((locale_t)-1)

extern struct lconv __frama_c_locale;
extern char*__frama_c_locale_names[];

/*@ 
requires locale == \null || valid_read_string(locale);
assigns \result, __frama_c_locale \from category, locale[..];
ensures \result!=\null ==> (\valid(\result) && \exists ℤ i ; \result == __frama_c_locale_names[i]);
*/
extern char *setlocale(int category, const char *locale);

/*@
assigns \result \from __frama_c_locale;
ensures \result == &__frama_c_locale;
*/
extern struct lconv *localeconv(void);

/* POSIX */

/*@
assigns \result, errno \from locobj;
ensures \result == (locale_t)0 ? errno != 0 : errno == \old(errno);
*/
locale_t duplocale(locale_t locobj);

/*@
assigns \nothing;
*/
void freelocale(locale_t locobj);

/*@
requires \valid(locale);
assigns \result, errno \from category_mask, locale[..], base;
ensures \result == (locale_t)0 ? errno != 0 : errno == \old(errno);
*/
locale_t newlocale(int category_mask, const char *locale, locale_t base);

/*@
assigns \result, errno \from newloc;
ensures \result == (locale_t)0 ? errno != 0 : errno == \old(errno);
*/
locale_t uselocale(locale_t newloc);

__END_DECLS

#endif
