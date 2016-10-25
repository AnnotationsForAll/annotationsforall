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

#ifndef __FC_STRINGS_H_
#define __FC_STRINGS_H_
#include "__fc_define_size_t.h"
#include "__gt_fc_define_locale_t.h"
#include "__fc_string_axiomatic.h"
#include "features.h"

__BEGIN_DECLS

/* POSIX */

/*@
assigns \result \from i;
ensures i == 0 ==> \result == 0;
*/
int ffs(int i);

/*@
assigns \result \from i;
ensures i == 0 ==> \result == 0;
*/
int ffsl(long int i);

/*@
assigns \result \from i;
ensures i == 0 ==> \result == 0;
*/
int ffsll(long long int i);

/*@
requires valid_string(s1);
requires valid_string(s2);
assigns \result \from s1[..], s2[..];
ensures s1 == s2 ==> \result == 0;
*/
int strcasecmp(const char *s1, const char *s2);

/*@
requires valid_string(s1);
requires valid_string(s2);
assigns \result \from s1[..], s2[..], locale;
ensures s1 == s2 ==> \result == 0;
*/
int strcasecmp_l(const char *s1, const char *s2, locale_t locale);

/*@
requires valid_string(s1);
requires valid_string(s2);
assigns \result \from s1[..], s2[..], n;
ensures s1 == s2 ==> \result == 0;
*/
int strncasecmp(const char *s1, const char *s2, size_t n);

/*@
requires valid_string(s1);
requires valid_string(s2);
assigns \result \from s1[..], s2[..], n, locale;
ensures s1 == s2 ==> \result == 0;
*/
int strncasecmp_l(const char *s1, const char *s2,
       size_t n, locale_t locale);

/*@ requires \valid (((char*) s)+(0 .. n-1));
   assigns ((char*) s)[0 .. n-1] \from \nothing; */
void   bzero(void *s, size_t n);

/* GNU Exntensions */

/*@
requires \valid_read(((char*)s1)+(0..n-1));
requires \valid_read(((char*)s2)+(0..n-1));
assigns \result \from ((char*)s1)[0..n-1], ((char*)s2)[0..n-1];
ensures \result == memcmp{Here,Here}((char*)s1,(char*)s2,n);
*/
int bcmp(const void *s1, const void *s2, size_t n);

/*@
requires valid_dst: \valid(((char*)dest)+(0..n-1));
requires valid_src: \valid_read(((char*)src)+(0..n-1));
assigns ((char*)dest)[0..n-1] \from ((char*)src)[0..n-1];
ensures memcmp{Post,Pre}((char*)dest,(char*)src,n) == 0;
*/
void bcopy(const void *src, void *dest, size_t n);

/*@ requires valid_string_src: valid_read_string(s);
  @ assigns \result \from s, s[0..strlen(s)],c;
  @ behavior found:
  @   assumes strchr(s,c);
  @   ensures *\result == c;
  @   ensures \base_addr(\result) == \base_addr(s);
  @   ensures s <= \result < s + strlen(s);
  @   ensures valid_read_string(\result);
  @   ensures \forall char* p; s<=p<\result ==> *p != c;
  @ behavior not_found:
  @   assumes ! strchr(s,c);
  @   ensures \result == \null;
  @ behavior default:
  @ ensures \result == \null || \base_addr(\result) == \base_addr(s);
  @*/
char *index(const char *s, int c);

/*@ requires valid_string_src: valid_read_string(s);
  @ assigns \result \from s, s[0..strlen(s)],c;
  @ behavior found:
  @   assumes strchr(s,c);
  @   ensures *\result == c;
  @   ensures \base_addr(\result) == \base_addr(s);
  @   ensures valid_read_string(\result);
  @ behavior not_found:
  @   assumes ! strchr(s,c);
  @   ensures \result == \null;
  @ behavior default:
  @ ensures \result == \null || \base_addr(\result) == \base_addr(s);
  @*/
char *rindex(const char *s, int c);

/*@
requires valid_string(s1);
requires valid_string(s2);
assigns \result \from s1[..], s2[..];
ensures s1 == s2 ==> \result == 0;
*/
int strverscmp (const char *s1, const char *s2);

__END_DECLS

#endif
