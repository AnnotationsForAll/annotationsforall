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

/* ISO C: 7.24 */
#ifndef __FC_UCHAR
#define __FC_UCHAR

#include "__fc_define_size_t.h"
#include "__gt_fc_define_mbstate_t.h"
#include "__gt_fc_define_alternative_types.h"

#include "errno.h"

#ifndef __CHAR16_TYPE__
#define __CHAR16_TYPE__ uint16_t
#endif

#ifndef __CHAR32_TYPE__
#define __CHAR32_TYPE__ uint32_t
#endif

typedef __CHAR16_TYPE__ char16_t;
typedef __CHAR32_TYPE__ char32_t;

mbstate_t __gt_fc_mbrtoc16_internal_mbstate = __GT_FC_MBSTATE_INITIAL_STATE;
/*@
requires s != \null ==> \valid(s+(0..n-1));
requires pc16 != \null ==> \valid(pc16);
requires ps != \null ==> \valid(ps);
assigns \result, *pc16, *ps, __gt_fc_mbrtoc16_internal_mbstate, errno \from *ps, __gt_fc_mbrtoc16_internal_mbstate, s[0..n-1];
ensures \result <= n || \result == (size_t)-1 || \result == (size_t)-2;
ensures \result == (size_t)-1 ? errno != 0 : errno == \old(errno);
behavior ps_null:
    assumes ps == \null;
    ensures *ps == \old(*ps);
behavior ps_not_null:
    assumes ps != \null;
    ensures __gt_fc_mbrtoc16_internal_mbstate == \old(__gt_fc_mbrtoc16_internal_mbstate);
complete behaviors; disjoint behaviors;
 */
size_t mbrtoc16(char16_t *restrict pc16, const char *restrict s, size_t n, mbstate_t *restrict ps);

mbstate_t __gt_fc_c16rtomb_internal_mbstate = __GT_FC_MBSTATE_INITIAL_STATE;
/*@
requires ps != \null ==> \valid(ps);
requires s != \null ==> \valid(s+(0.. MB_CUR_MAX-1));
assigns \result, s[0.. MB_CUR_MAX-1], *ps, __gt_fc_c16rtomb_internal_mbstate \from *ps, __gt_fc_c16rtomb_internal_mbstate, c16;
ensures \result <= MB_CUR_MAX || \result == (size_t)-1;
ensures \result == (size_t)-1 ? errno != 0 : errno == \old(errno);
behavior ps_null:
    assumes ps == \null;
    ensures *ps == \old(*ps);
behavior ps_not_null:
    assumes ps != \null;
    ensures __gt_fc_c16rtomb_internal_mbstate == \old(__gt_fc_c16rtomb_internal_mbstate);
complete behaviors; disjoint behaviors;
*/
size_t c16rtomb(char *restrict s, char16_t c16, mbstate_t *restrict ps);

mbstate_t __gt_fc_mbrtoc32_internal_mbstate = __GT_FC_MBSTATE_INITIAL_STATE;
/*@
requires s != \null ==> \valid(s+(0..n-1));
requires pc32 != \null ==> \valid(pc32);
requires ps != \null ==> \valid(ps);
assigns \result, *pc32, *ps, __gt_fc_mbrtoc32_internal_mbstate, errno \from *ps, __gt_fc_mbrtoc32_internal_mbstate, s[0..n-1];
ensures \result <= n || \result == (size_t)-1 || \result == (size_t)-2;
ensures \result == (size_t)-1 ? errno != 0 : errno == \old(errno);
behavior ps_null:
    assumes ps == \null;
    ensures *ps == \old(*ps);
behavior ps_not_null:
    assumes ps != \null;
    ensures __gt_fc_mbrtoc32_internal_mbstate == \old(__gt_fc_mbrtoc32_internal_mbstate);
complete behaviors; disjoint behaviors;
 */
size_t mbrtoc32(char32_t *restrict pc32, const char *restrict s, size_t n, mbstate_t *restrict ps);

mbstate_t __gt_fc_c32rtomb_internal_mbstate = __GT_FC_MBSTATE_INITIAL_STATE;
/*@
requires ps != \null ==> \valid(ps);
requires s != \null ==> \valid(s+(0.. MB_CUR_MAX-1));
assigns \result, s[0.. MB_CUR_MAX-1], *ps, __gt_fc_c32rtomb_internal_mbstate \from *ps, __gt_fc_c32rtomb_internal_mbstate, c32;
ensures \result <= MB_CUR_MAX || \result == (size_t)-1;
ensures \result == (size_t)-1 ? errno != 0 : errno == \old(errno);
behavior ps_null:
    assumes ps == \null;
    ensures *ps == \old(*ps);
behavior ps_not_null:
    assumes ps != \null;
    ensures __gt_fc_c32rtomb_internal_mbstate == \old(__gt_fc_c32rtomb_internal_mbstate);
complete behaviors; disjoint behaviors;
*/
size_t c32rtomb(char *restrict s, char32_t c32, mbstate_t *restrict ps);

#endif
