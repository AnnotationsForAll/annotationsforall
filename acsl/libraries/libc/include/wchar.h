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

/* ISO C: 7.25 */
#ifndef __FC_WCHAR_H
#define __FC_WCHAR_H

#include "__fc_define_wchar_t.h"
#include "__fc_define_size_t.h"
#include "__fc_define_file.h"
#include "__fc_define_null.h"
#include "__fc_define_wint_t.h"
#include "__gt_fc_define_locale_t.h"
#include "__gt_fc_define_mbstate_t.h"
#include "features.h"
#include "stdarg.h"
#include "stdio.h"
#include "stdlib.h"

__BEGIN_DECLS

// Macros defined: NULL,WCHAR_MIN, WCHAR_MAX, WEOF
#ifndef WCHAR_MIN
/* These constants might also be defined in <inttypes.h>.  */
# define WCHAR_MIN __WCHAR_MIN
# define WCHAR_MAX __WCHAR_MAX
#endif

#ifndef WEOF
# define WEOF (0xffffffffu)
#endif

#include "wctype.h"

/* Frama-C Note: It is unclear whether these are more often in wchar.h or stdio.h */

// Formatted wide character input/output (7.24.2)

/*@
requires file_is_open(stream);
requires \valid(format);
assigns *stream;
*/
int fwprintf(FILE * restrict stream, const wchar_t * restrict format, ...);

/*@
requires \valid(stream);
requires \valid(format);
assigns *stream;
ensures \result >= 0 || \result == EOF;
*/
int fwscanf(FILE * restrict stream, const wchar_t * restrict format, ...);

/*@
requires \valid(s+(0..n-1));
requires \valid(format);
assigns s[0..n-1];
*/
int swprintf(wchar_t * restrict s, size_t n, const wchar_t * restrict format, ...);

/*@ //TODO: assigns
requires \valid(s);
requires \valid(format);
ensures \result >= 0 || \result == EOF;
*/
int swscanf(const wchar_t * restrict s, const wchar_t * restrict format, ...);

/*@
requires file_is_open(stream);
assigns *stream \from format[..], arg;
*/
int vfwprintf(FILE * restrict stream, const wchar_t * restrict format, va_list arg);

/*@
requires file_is_open(stream);
assigns *stream \from format[..], *stream, arg;
ensures \result >= 0 || \result == EOF;
*/
int vfwscanf(FILE * restrict stream, const wchar_t * restrict format, va_list arg);

/*@
requires \valid(s+(0..n-1));
requires \valid(format);
assigns s[0..n-1] \from format[..], arg;
*/
int vswprintf(wchar_t * restrict s, size_t n, const wchar_t * restrict format, va_list arg);\

/*@ //TODO: assigns
requires \valid(s);
requires \valid(format);
ensures \result >= 0 || \result == EOF;
*/
int vswscanf(const wchar_t * restrict s, const wchar_t * restrict format, va_list arg);

/*@
assigns *__fc_stdout \from format[..], arg;
*/
int vwprintf(const wchar_t * restrict format, va_list arg);

/*@
assigns *__fc_stdin \from format[..], *__fc_stdin, arg;
ensures \result >= 0 || \result == EOF;
*/
int vwscanf(const wchar_t * restrict format, va_list arg);

/*@
requires valid_wstring(format);
assigns *__fc_stdout;
*/
int wprintf(const wchar_t * restrict format, ...);

/*@
requires \valid(format);
assigns *__fc_stdin;
ensures \result >= 0 || \result == WEOF;
*/
int wscanf(const wchar_t * restrict format, ...);

// Wide character input/output functions (7.24.3)

/*@
requires file_is_open(stream);
assigns *stream;
ensures (wchar_t)\result == \result || \result == WEOF;
*/
wint_t fgetwc(FILE *stream);

/*@
requires file_is_open(stream);
requires \valid(s+(0..n-1));
assigns s[0..n-1],*stream \from *stream;
assigns \result \from s,n,*stream;
ensures \result == \null || \result == s;
*/
wchar_t *fgetws(wchar_t * restrict s, int n, FILE * restrict stream);

/*@
requires file_is_open(stream);
assigns *stream \from c, *stream;
ensures \result == (wchar_t)c || \result == WEOF;
*/
wint_t fputwc(wchar_t c, FILE *stream);

/*@
requires file_is_open(stream);
requires \valid(s);
assigns *stream \from s[..];
ensures \result >= 0 || \result == EOF;
*/
int fputws(const wchar_t * restrict s, FILE * restrict stream);

/*@
requires file_is_open(stream);
assigns \result, *stream \from *stream, mode;
*/
int fwide(FILE *stream, int mode);

/*@
requires file_is_open(stream);
assigns \result, *stream \from *stream;
ensures (wchar_t)\result == \result || \result == WEOF;
 */
wint_t getwc(FILE *stream);

/*@
assigns *__fc_stdin;
ensures (wchar_t)\result == \result || \result == WEOF;
 */
wint_t getwchar(void);

/*@
requires file_is_open(stream);
assigns *stream \from c, *stream;
ensures \result == (wchar_t)c || \result == WEOF;
*/
wint_t putwc(wchar_t c, FILE *stream);

/*@
assigns *__fc_stdout \from c, *__fc_stdout;
ensures \result == (wchar_t)c || \result == WEOF;
*/
wint_t putwchar(wchar_t c);

/*@
requires file_is_open(stream);
assigns *stream \from c, *stream;
ensures \result == (wchar_t)c || \result == WEOF;
ensures \result != WEOF ==> !file_eof(stream);
*/
wint_t ungetwc(wint_t c, FILE *stream);

// General wide string utilities (7.24.4)

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
double wcstod(const wchar_t * restrict nptr, wchar_t ** restrict endptr);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
float wcstof(const wchar_t * restrict nptr, wchar_t ** restrict endptr);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
long double wcstold(const wchar_t * restrict nptr, wchar_t ** restrict endptr);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
long int wcstol(const wchar_t * restrict nptr, wchar_t ** restrict endptr, int base);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
long long int wcstoll(const wchar_t * restrict nptr, wchar_t ** restrict endptr, int base);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
unsigned long int wcstoul(const wchar_t * restrict nptr, wchar_t ** restrict endptr, int base);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
unsigned long long int wcstoull(const wchar_t * restrict nptr, wchar_t ** restrict endptr, int base);

/*@ requires valid_string_src: valid_wstring(src);
  @ requires room_string: \valid(dest+(0..wcslen(src)));
  @ requires \separated(dest+(0..wcslen(dest)), src+(0..wcslen(src)));
  @ assigns dest[0..wcslen(src)] \from src[0..wcslen(src)];
  @ assigns \result \from dest;
  @ ensures wcscmp(dest,src) == 0;
  @ ensures \result == dest;
  @*/
wchar_t *wcscpy(wchar_t * restrict dest, const wchar_t * restrict src);

/*@
  @ requires valid_string_src: valid_wstring(src);
  @ requires room_nstring: \valid(dest+(0..(n-1))) || \valid(dest+(0..wcslen(src)));
  @ requires \separated(dest+(0..n-1),src+(0..n-1));
  @ assigns dest[0..n - 1] \from src[0..n-1];
  @ assigns \result \from dest;
  @ ensures \result == dest;
  @ behavior complete:
  @   assumes wcslen(src) < n;
  @   ensures wcscmp(dest,src) == 0;
  @ behavior partial:
  @   assumes n <= wcslen(src);
  @   assigns dest[0..n - 1];
  @   ensures wmemcmp{Post,Post}(dest,src,n) == 0;
  @*/
wchar_t *wcsncpy(wchar_t *restrict dest, const wchar_t *restrict src, size_t n);

/*@ requires valid_dst: \valid((dest)+(0..n - 1));
  @ requires valid_src: \valid_read((src)+(0..n - 1));
  @ requires \separated((dest)+(0..n-1),(src)+(0..n-1));
  @ assigns (dest)[0..n - 1] \from (src)[0..n-1];
  @ assigns \result \from dest;
  @ ensures wmemcmp{Post,Pre}(dest,src,n) == 0;
  @ ensures \result == dest;
  @*/
wchar_t *wmemcpy(wchar_t *restrict dest, const wchar_t *restrict src, size_t n);

/*@ requires valid_dst: \valid((dest)+(0..n - 1));
  @ requires valid_src: \valid_read((src)+(0..n - 1));
  @ assigns (dest)[0..n - 1] \from (src)[0..n-1];
  @ assigns \result \from dest;
  @ ensures wmemcmp{Post,Pre}(dest,src,n) == 0;
  @ ensures \result == dest;
  @*/
wchar_t *wmemmove(wchar_t *dest, const wchar_t *src, size_t n);

/*@ // missing: separation
  @ requires valid_string_src: valid_wstring(src);
  @ requires valid_string_dst: valid_wstring(dest);
  @ requires room_string: \valid(dest+(0..wcslen(dest) + wcslen(src)));
  @ requires \separated(dest+(0..wcslen(dest)), src+(0..wcslen(src)));
  @ assigns dest[wcslen(dest)..wcslen(dest) + wcslen(src)]
  @   \from src[0..wcslen(src)];
  @ ensures wcslen(dest) == \old(wcslen(dest) + wcslen(src));
  @ assigns \result \from dest;
  @ ensures \result == dest;
  @*/
wchar_t *wcscat(wchar_t *restrict dest, const wchar_t *restrict src);

/*@ // missing: separation
  @ requires valid_string_src: valid_wstring(src) || \valid(src+(0..n-1));
  @ requires valid_string_dst: valid_wstring(dest);
  @ requires room_string: \valid(dest + (wcslen(dest) .. wcslen(dest) + n)) ;
  @ assigns dest[wcslen(dest) .. wcslen(dest) + n] \from src[0..n];
  @ assigns \result \from dest;
  @ ensures \result == dest;
  @ behavior complete:
  @   assumes valid_wstring(src) && wcslen(src) <= n;
  @   assigns dest[wcslen(dest)..wcslen(dest) + wcslen(src)]
  @   \from src[0..wcslen(src)];
  @   assigns \result \from dest;
  @   ensures wcslen(dest) == \old(wcslen(dest) + wcslen(src));
  @ behavior partial:
  @   assumes ! (valid_wstring(src) && wcslen(src) <= n);
  @   assigns dest[wcslen(dest)..wcslen(dest) + n]
  @   \from src[0..wcslen(src)];
  @   assigns \result \from dest;
  @   ensures wcslen(dest) == \old(wcslen(dest)) + n;
  @*/
wchar_t *wcsncat(wchar_t *restrict dest, const wchar_t *restrict src, size_t n);

/*@ requires valid_string_s1: valid_wstring(s1);
  @ requires valid_string_s2: valid_wstring(s2);
  @ assigns \result \from s1[0..], s2[0..];
  @ ensures \result == wcscmp(s1,s2);
  @*/
int wcscmp(const wchar_t *s1, const wchar_t *s2);

/*@ requires valid_string_s1: valid_wstring(s1); // over-strong
  @ requires valid_string_s2: valid_wstring(s2); // over-strong
  @ assigns \result \from s1[0 .. n-1], s2[0 ..n-1];
  @ ensures \result == wcsncmp(s1,s2,n);
  @*/
int wcsncmp(const wchar_t *s1, const wchar_t *s2, size_t n);

/*@ requires valid_string_s1: valid_wstring(s1); // over-strong
  @ requires valid_string_s2: valid_wstring(s2); // over-strong
  @ assigns \result \from s1[0..], s2[0..];
  @*/
int wcscoll(const wchar_t *s1, const wchar_t *s2);

/*@ requires valid_dest: \valid(dest+(0..n - 1));
  @ requires valid_string_src: valid_wstring(src);
  @ assigns dest[0..n - 1] \from src[0..], n;
  @ assigns \result \from dest;
  @*/
size_t wcsxfrm(char *restrict dest, const wchar_t *restrict src, size_t n);

/*@ requires \valid_read((s1)+(0..n - 1));
  @ requires \valid_read((s2)+(0..n - 1));
  @ assigns \result \from (s1)[0.. n-1], (s2)[0.. n-1];
  @ ensures \result == wmemcmp{Pre,Pre}(s1,s2,n);
  @*/
int wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n);

/*@ requires valid_string_src: valid_wstring(s);
  @ assigns \result \from s, s[0..],c;
  @ behavior found:
  @   assumes wcschr(s,c);
  @   ensures *\result == c;
  @   ensures \base_addr(\result) == \base_addr(s);
  @   ensures s <= \result < s + wcslen(s);
  @   ensures valid_wstring(\result);
  @   ensures \forall wchar_t* p; s<=p<\result ==> *p != c;
  @ behavior not_found:
  @   assumes !wcschr(s,c);
  @   ensures \result == \null;
  @ behavior default:
  @ ensures \result == \null || \base_addr(\result) == \base_addr(s);
  @*/
wchar_t *wcschr(const wchar_t *s, wint_t c);

/*@ requires valid_string_src: valid_wstring(s);
  @ requires valid_string_reject: valid_wstring(reject);
  @ assigns \result \from s[0..], reject[0..];
  @ ensures 0 <= \result <= wcslen(s);
  @*/
size_t wcscspn(const wchar_t *s, const wchar_t *reject);

/*@ requires valid_string_src: valid_wstring(s);
  @ requires valid_string_accept: valid_wstring(accept);
  @ assigns \result \from s, s[0..], accept[0..];
  @ ensures \result == 0 || \base_addr(\result) == \base_addr(s);
  @*/
wchar_t *wcspbrk(const wchar_t *s, const wchar_t *accept);

/*@ requires valid_string_src: valid_wstring(s);
  @ assigns \result \from s, s[0..],c;
  @ behavior found:
  @   assumes wcschr(s,c);
  @   ensures *\result == c;
  @   ensures \base_addr(\result) == \base_addr(s);
  @   ensures valid_wstring(\result);
  @ behavior not_found:
  @   assumes ! wcschr(s,c);
  @   ensures \result == \null;
  @ behavior default:
  @ ensures \result == \null || \base_addr(\result) == \base_addr(s);
  @*/
wchar_t *wcsrchr(const wchar_t *s, wint_t c);

/*@ requires valid_string_src: valid_wstring(s);
  @ requires valid_string_accept: valid_wstring(accept);
  @ assigns \result \from s[0..], accept[0..];
  @ ensures 0 <= \result <= wcslen(s);
  @*/
size_t wcsspn(const wchar_t *s, const wchar_t *accept);

/*@ requires valid_string_haystack: valid_wstring(haystack);
  @ requires valid_string_needle: valid_wstring(needle);
  @ assigns \result \from haystack, haystack[0..], needle, needle[0..];
  @ ensures \result == 0
  @      || (\base_addr(\result) == \base_addr(haystack)
  @          && wmemcmp{Pre,Pre}(\result,needle,wcslen(needle)) == 0);
  @*/
wchar_t *wcsstr(const wchar_t *haystack, const wchar_t *needle);

/*@ requires valid_string_src: valid_wstring_or_null(s);
  @ requires valid_string_delim: valid_wstring(delim);
  @ assigns \result \from s, s[0..], delim[0..];
  @ ensures \result == \null
            || \base_addr(\result) == \base_addr(s);
  @*/
wchar_t *wcstok(wchar_t *restrict s, const wchar_t *restrict delim);

/*@ requires \valid_read((s)+(0..n - 1));
  @ assigns \result \from s, c, (s)[0..n-1];
  @ behavior found:
  @   assumes wmemchr(s,c,n);
  @   ensures \base_addr(\result) == \base_addr(s);
  @   ensures *\result == c;
  @ behavior not_found:
  @   assumes ! wmemchr(s,c,n);
  @   ensures \result == \null;
  @*/
wchar_t *wmemchr(const wchar_t *s, wint_t c, size_t n);

/*@ requires valid_string_src: valid_wstring(s);
  @ assigns \result \from s[0..];
  @ ensures \result == wcslen(s);
  @*/
size_t wcslen(const wchar_t *s);

/*@ requires \valid((s)+(0..n - 1));
  @ assigns (s)[0..n - 1] \from c;
  @ assigns \result \from s;
  @ ensures wmemset(s,c,n);
  @ ensures \result == s;
  @*/
wchar_t *wmemset(wchar_t *s, wint_t c, size_t n);

// Wide character time conversion (7.24.5)

/*@
    requires \valid(s+(0 .. maxsize-1));
    assigns s[0 .. maxsize-1];
    ensures (\result == 0) ||
             (\result == wcslen(s));
 */
size_t wcsftime (wchar_t *restrict s, size_t maxsize, const wchar_t *restrict format, const struct tm *restrict timeptr);

// Extended multibyte/wide character conversion utilities (7.24.6)

/*@
    assigns \result \from c;
    ensures (c == EOF) ==> (\result == WEOF);
 */
wint_t btowc (int c);

/*@
    assigns \result \from c;
    ensures (\result == EOF) ||  ((unsigned char)\result == \result);
 */
int wctob (wint_t c);

/*@
    requires (ps == \null) || (\valid(ps));
    assigns \result \from *ps;
    behavior ps_null:
        assumes ps == \null;
        ensures \result != 0;
    behavior ps_not_null:
        assumes ps != \null;
        // ps is inital conversion state -> \result != 0
        // ps is NOT inital conversion state -> \result == 0
        // determines if ps describes an initial conversion state
    complete behaviors ps_null, ps_not_null;
    disjoint behaviors ps_null, ps_not_null;
 */
int mbsinit (const mbstate_t *ps);

mbstate_t __gt_fc_mbrlen_internal_mbstate = __GT_FC_MBSTATE_INITIAL_STATE;

/*@
requires \valid(s+(0..n-1));
requires ps != \null ==> \valid(ps);
assigns \result, *ps, __gt_fc_mbrlen_internal_mbstate, errno \from s[0..n-1], n, *ps;
ensures \result <= n || \result == (size_t)-1 || \result == (size_t)-2;
ensures \result == (size_t)-1 ? errno != 0 : errno == \old(errno);
behavior ps_null:
    assumes ps == \null;
    ensures *ps == \old(*ps);
behavior ps_not_null:
    assumes ps != \null;
    ensures __gt_fc_mbrlen_internal_mbstate == \old(__gt_fc_mbrlen_internal_mbstate);
complete behaviors; disjoint behaviors;
*/
size_t mbrlen (const char *restrict s, size_t n, mbstate_t *restrict ps);

mbstate_t __gt_fc_mbrtowc_internal_mbstate = __GT_FC_MBSTATE_INITIAL_STATE;
/*@
requires s != \null ==> \valid(s+(0..n-1));
requires pwc != \null ==> \valid(pwc);
requires ps != \null ==> \valid(ps);
assigns \result, *pwc, *ps, __gt_fc_mbrtowc_internal_mbstate, errno \from *ps, __gt_fc_mbrtowc_internal_mbstate, s[0..n-1];
ensures \result <= n || \result == (size_t)-1 || \result == (size_t)-2;
ensures \result == (size_t)-1 ? errno != 0 : errno == \old(errno);
behavior ps_null:
    assumes ps == \null;
    ensures *ps == \old(*ps);
behavior ps_not_null:
    assumes ps != \null;
    ensures __gt_fc_mbrtowc_internal_mbstate == \old(__gt_fc_mbrtowc_internal_mbstate);
complete behaviors; disjoint behaviors;
 */
size_t mbrtowc (wchar_t *restrict pwc, const char *restrict s, size_t n, mbstate_t *ps);

mbstate_t __gt_fc_wcrtomb_internal_mbstate = __GT_FC_MBSTATE_INITIAL_STATE;
/*@
requires ps != \null ==> \valid(ps);
requires s != \null ==> \valid(s+(0.. MB_CUR_MAX-1));
assigns \result, s[0.. MB_CUR_MAX-1], *ps, __gt_fc_wcrtomb_internal_mbstate \from *ps, __gt_fc_wcrtomb_internal_mbstate, wc;
ensures \result <= MB_CUR_MAX || \result == (size_t)-1;
ensures \result == (size_t)-1 ? errno != 0 : errno == \old(errno);
behavior ps_null:
    assumes ps == \null;
    ensures *ps == \old(*ps);
behavior ps_not_null:
    assumes ps != \null;
    ensures __gt_fc_wcrtomb_internal_mbstate == \old(__gt_fc_wcrtomb_internal_mbstate);
complete behaviors; disjoint behaviors;
*/
size_t wcrtomb (char *restrict s, wchar_t wc, mbstate_t *restrict ps);

mbstate_t __gt_fc_mbsrtowcs_internal_mbstate = __GT_FC_MBSTATE_INITIAL_STATE;
/*@
requires \valid(dst+(0..len-1));
assigns \result, dst[0..len-1], *ps, __gt_fc_mbsrtowcs_internal_mbstate, errno \from src[..], len, *ps, __gt_fc_mbsrtowcs_internal_mbstate;
ensures \result <= len || \result == (size_t)-1;
ensures \result == (size_t)-1 ? errno != 0 : errno == \old(errno);
behavior ps_null:
    assumes ps == \null;
    ensures *ps == \old(*ps);
behavior ps_not_null:
    assumes ps != \null;
    ensures __gt_fc_mbsrtowcs_internal_mbstate == \old(__gt_fc_mbsrtowcs_internal_mbstate);
complete behaviors; disjoint behaviors;
*/
size_t mbsrtowcs (wchar_t *restrict dst, const char **restrict src, size_t len, mbstate_t *restrict ps);

mbstate_t __gt_fc_wcsrtombs_internal_mbstate = __GT_FC_MBSTATE_INITIAL_STATE;
/*@
requires \valid(dst+(0..len-1));
assigns \result, dst[0..len-1], *ps, __gt_fc_wcsrtombs_internal_mbstate, errno \from src[..], len, *ps, __gt_fc_wcsrtombs_internal_mbstate;
ensures \result <= len || \result == (size_t)-1;
ensures \result == (size_t)-1 ? errno != 0 : errno == \old(errno);
behavior ps_null:
    assumes ps == \null;
    ensures *ps == \old(*ps);
behavior ps_not_null:
    assumes ps != \null;
    ensures __gt_fc_wcsrtombs_internal_mbstate == \old(__gt_fc_wcsrtombs_internal_mbstate);
complete behaviors; disjoint behaviors;
*/
size_t wcsrtombs (char *restrict dst, const wchar_t **restrict src, size_t len, mbstate_t *restrict ps);

/* POSIX */

size_t mbsnrtowcs(wchar_t *restrict, const char **restrict, size_t, size_t, mbstate_t *restrict);
size_t wcsnrtombs(char *restrict, const wchar_t **restrict, size_t, size_t, mbstate_t *restrict);

/*@ //FIXME: errno behavior?
requires \valid(sizep);
requires \valid(bufp) && \valid((*bufp)+(0..((*sizep)-1)));
assigns \result \from bufp, sizep, __fc_fopen[..];
ensures \result != \null ==> file_has_stream(\result);
ensures \result != \null ==> file_is_open(\result);
ensures \result != \null ==> !file_error(\result);
ensures \result != \null ==> !file_eof(\result);
*/
FILE *open_wmemstream(wchar_t **bufp, size_t *sizep);

/*@
requires valid_string_src: valid_wstring(src);
requires room_string: \valid(dest+(0..wcslen(src)));
assigns dest[0..wcslen(src)] \from src[0..wcslen(src)];
assigns \result \from dest;
ensures wcscmp(dest,src) == 0;
ensures \result == dest+wcslen(src);
*/
wchar_t *wcpcpy(wchar_t *restrict dest, const wchar_t *restrict src);

/*@
requires valid_string_src: valid_wstring(src);
// FIXME: min(...) requires room_nstring: \valid(dest+(0 .. n));
assigns dest[0..n - 1] \from src[0..n-1];
assigns \result \from dest;
behavior complete:
  assumes wcslen(src) < n;
  ensures wcscmp(dest,src) == 0;
  ensures \result == dest+wcslen(src);
behavior partial:
  assumes n <= wcslen(src);
  assigns dest[0..n - 1];
  ensures wmemcmp{Post,Post}(dest,src,n) == 0;
  ensures \result == dest+n;
*/
wchar_t *wcpncpy(wchar_t *restrict dest, const wchar_t *restrict src, size_t n);

/*@
requires valid_wstring(s1);
requires valid_wstring(s2);
assigns \result \from s1[..], s2[..];
ensures s1 == s2 ==> \result == 0;
*/
int wcscasecmp(const wchar_t * s1, const wchar_t * s2);

/*@
requires valid_wstring(s1);
requires valid_wstring(s2);
assigns \result \from s1[..], s2[..], locale;
ensures s1 == s2 ==> \result == 0;
*/
int wcscasecmp_l(const wchar_t * s1, const wchar_t * s2, locale_t locale);

/*@ requires valid_string_s1: valid_wstring(s1); // over-strong
  @ requires valid_string_s2: valid_wstring(s2); // over-strong
  @ assigns \result \from s1[0..], s2[0..];
  @*/
int wcscoll_l(const wchar_t * s1, const wchar_t * s2, locale_t locale);

/*@ requires valid_string_src: valid_wstring(s);
  @ assigns \result; // FIXME
  @ ensures \valid(\result+(0..wcslen(s))) && wcscmp(\result,s) == 0;
  @*/
wchar_t *wcsdup (const wchar_t *s);

/*@
requires valid_wstring(s1);
requires valid_wstring(s2);
assigns \result \from s1[..], s2[..], n;
ensures s1 == s2 ==> \result == 0;
*/
int wcsncasecmp(const wchar_t *s1, const wchar_t *s2, size_t n);

/*@
requires valid_wstring(s1);
requires valid_wstring(s2);
assigns \result \from s1[..], s2[..], n, locale;
ensures s1 == s2 ==> \result == 0;
*/
int wcsncasecmp_l(const wchar_t *s1, const wchar_t *s2, size_t n, locale_t locale);

/*@
requires valid_string_src: valid_wstring(s);
assigns \result \from s[0..n-1], n;
ensures wcslen(s) < n ==> \result == wcslen(s);
ensures wcslen(s) >= n ==> \result == n;
*/
size_t wcsnlen(const wchar_t *s, size_t n);

/*@
requires valid_wstring(pwcs);
assigns \result \from pwcs[0..wcslen(pwcs)-1], n;
ensures \result >= -1;
*/
int wcswidth(const wchar_t *pwcs, size_t n);

/*@ requires valid_dest: \valid(dest+(0..n - 1));
  @ requires valid_string_src: valid_wstring(src);
  @ assigns dest[0..n - 1] \from src[0..], n, locale;
  @ assigns \result \from dest;
  @*/
size_t wcsxfrm_l(char *restrict dest, const wchar_t *restrict src, size_t n, locale_t locale);

/*@
assigns \result \from wc;
ensures \result >= -1;
*/
int wcwidth(wchar_t wc);

/* GNU Extensions */

#define wcswcs wcsstr

#define wcstoq wcstoll
#define wcstouq wcstoull

/*@ requires valid_dst: \valid((dest)+(0..n - 1));
  @ requires valid_src: \valid_read((src)+(0..n - 1));
  @ requires \separated((dest)+(0..n-1),(src)+(0..n-1));
  @ assigns (dest)[0..n - 1] \from (src)[0..n-1];
  @ assigns \result \from dest;
  @ ensures wmemcmp{Post,Pre}(dest,src,n) == 0;
  @ ensures \result == dest+n;
  @*/
wchar_t * wmempcpy (wchar_t *restrict dest, const wchar_t *restrict src, size_t n);

/*@ requires valid_string_src: valid_wstring(s);
  @ assigns \result \from s, s[0..],c;
  @ behavior found:
  @   assumes wcschr(s,c);
  @   ensures *\result == c;
  @   ensures \base_addr(\result) == \base_addr(s);
  @   ensures s <= \result < s + wcslen(s);
  @   ensures valid_wstring(\result);
  @   ensures \forall wchar_t* p; s<=p<\result ==> *p != c;
  @ behavior not_found:
  @   assumes !wcschr(s,c);
  @   ensures \result == s+wcslen(s);
  @ behavior default:
  @ ensures \result == \null || \base_addr(\result) == \base_addr(s);
  @*/
wchar_t * wcschrnul (const wchar_t *s, wchar_t c);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
double wcstod_l(const wchar_t * restrict nptr, wchar_t ** restrict endptr, locale_t loc);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
float wcstof_l(const wchar_t * restrict nptr, wchar_t ** restrict endptr, locale_t loc);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
long double wcstold_l(const wchar_t * restrict nptr, wchar_t ** restrict endptr, locale_t loc);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
long int wcstol_l(const wchar_t * restrict nptr, wchar_t ** restrict endptr, int base, locale_t loc);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
long long int wcstoll_l(const wchar_t * restrict nptr, wchar_t ** restrict endptr, int base, locale_t loc);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
unsigned long int wcstoul_l(const wchar_t * restrict nptr, wchar_t ** restrict endptr, int base, locale_t loc);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
unsigned long long int wcstoull_l(const wchar_t * restrict nptr, wchar_t ** restrict endptr, int base, locale_t loc);

/*@
    requires \valid(s+(0 .. maxsize-1));
    assigns s[0 .. maxsize-1];
    ensures (\result == 0) ||
             (\result == wcslen(s));
 */
size_t wcsftime_l(wchar_t *restrict s, size_t maxsize, const wchar_t *restrict format, const struct tm *restrict timeptr, locale_t loc);

/*@
requires file_is_open(stream);
requires \valid(s+(0..n-1));
assigns s[0..n-1],*stream \from *stream;
assigns \result \from s,n,*stream;
ensures \result == \null || \result == s;
*/
wchar_t *fgetws_unlocked(wchar_t * restrict s, int n, FILE * restrict stream);

/*@
requires file_is_open(stream);
assigns *stream \from c, *stream;
ensures \result == (wchar_t)c || \result == WEOF;
*/
wint_t fputwc_unlocked(wchar_t c, FILE *stream);

/*@
requires file_is_open(stream);
requires \valid(s);
assigns *stream \from s[..];
ensures \result >= 0 || \result == EOF;
*/
int fputws_unlocked(const wchar_t * restrict s, FILE * restrict stream);

/*@
requires file_is_open(stream);
assigns \result, *stream \from *stream;
ensures (wchar_t)\result == \result || \result == WEOF;
 */
wint_t getwc_unlocked(FILE *stream);

/*@
assigns *__fc_stdin;
ensures (wchar_t)\result == \result || \result == WEOF;
 */
wint_t getwchar_unlocked(void);

/*@
requires file_is_open(stream);
assigns *stream \from c, *stream;
ensures \result == (wchar_t)c || \result == WEOF;
*/
wint_t putwc_unlocked(wchar_t c, FILE *stream);

/*@
assigns *__fc_stdout \from c, *__fc_stdout;
ensures \result == (wchar_t)c || \result == WEOF;
*/
wint_t putwchar_unlocked(wchar_t c);

__END_DECLS

#endif
