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

#ifndef __FC_STRING_H_
#define __FC_STRING_H_

#include "__fc_string_axiomatic.h"
#include "stddef.h"
#include "limits.h"
#include "features.h"
#include "__gt_fc_define_locale_t.h"
#include "libgen.h"

__BEGIN_DECLS

// Query memory

/*@ requires \valid_read(((char*)s1)+(0..n - 1));
  @ requires \valid_read(((char*)s2)+(0..n - 1));
  @ assigns \result \from ((char*)s1)[0.. n-1], ((char*)s2)[0.. n-1];
  @ ensures \result == memcmp{Pre,Pre}((char*)s1,(char*)s2,n);
  @*/
extern int memcmp (const void *s1, const void *s2, size_t n);

/*@ requires \valid_read(((char*)s)+(0..n - 1));
  @ assigns \result \from s, c, ((char*)s)[0..n-1];
  @ behavior found:
  @   assumes memchr((char*)s,c,n);
  @   ensures \base_addr(\result) == \base_addr(s);
  @   ensures *(char*)\result == c;
  @   ensures \forall integer i;
  @     0 <= i < n ==> *((char*)s+i) == c
  @     ==> \result <= s+i;
  @ behavior not_found:
  @   assumes ! memchr((char*)s,c,n);
  @   ensures \result == \null;
  @*/
extern void *memchr(const void *s, int c, size_t n);

// Copy memory

/*@ requires valid_dst: \valid(((char*)dest)+(0..n - 1));
  @ requires valid_src: \valid_read(((char*)src)+(0..n - 1));
  @ requires \separated(((char *)dest)+(0..n-1),((char *)src)+(0..n-1));
  @ assigns ((char*)dest)[0..n - 1] \from ((char*)src)[0..n-1];
  @ assigns \result \from dest;
  @ ensures memcmp{Post,Pre}((char*)dest,(char*)src,n) == 0;
  @ ensures \result == dest;
  @*/
extern void *memcpy(void *restrict dest,
            const void *restrict src, size_t n);

/*@ requires valid_dst: \valid(((char*)dest)+(0..n - 1));
  @ requires valid_src: \valid_read(((char*)src)+(0..n - 1));
  @ assigns ((char*)dest)[0..n - 1] \from ((char*)src)[0..n-1];
  @ assigns \result \from dest;
  @ ensures memcmp{Post,Pre}((char*)dest,(char*)src,n) == 0;
  @ ensures \result == dest;
  @*/
extern void *memmove(void *dest, const void *src, size_t n);

// Set memory

/*@ requires \valid(((char*)s)+(0..n - 1));
  @ assigns ((char*)s)[0..n - 1] \from c;
  @ assigns \result \from s;
  @ ensures memset((char*)s,c,n);
  @ ensures \result == s;
  @*/
extern void *memset(void *s, int c, size_t n);

// Query strings

/*@ requires valid_string_src: valid_read_string(s);
  @ assigns \result \from s[0..];
  @ ensures \result == strlen(s);
  @*/
extern size_t strlen (const char *s);

/*@ requires valid_string_s1: valid_read_string(s1);
  @ requires valid_string_s2: valid_read_string(s2);
  @ assigns \result \from s1[0..], s2[0..];
  @ ensures \result == strcmp(s1,s2);
  @*/
extern int strcmp (const char *s1, const char *s2);

/*@ requires valid_string_s1: valid_read_string(s1); // over-strong
  @ requires valid_string_s2: valid_read_string(s2); // over-strong
  @ assigns \result \from s1[0 .. n-1], s2[0 ..n-1];
  @ ensures \result == strncmp(s1,s2,n);
  @*/
extern int strncmp (const char *s1, const char *s2, size_t n);

/*@ requires valid_string_s1: valid_read_string(s1); // over-strong
  @ requires valid_string_s2: valid_read_string(s2); // over-strong
  @ assigns \result \from s1[0..], s2[0..];
  @*/
extern int strcoll (const char *s1, const char *s2);

/*@ requires valid_string_src: valid_read_string(s);
  @ assigns \result \from s, s[0..],c;
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
extern char *strchr(const char *s, int c);

/*@ requires valid_string_src: valid_read_string(s);
  @ assigns \result \from s, s[0..],c;
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
extern char *strrchr(const char *s, int c);

/*@ requires valid_string_src: valid_read_string(s);
  @ requires valid_string_reject: valid_read_string(reject);
  @ assigns \result \from s[0..], reject[0..];
  @ ensures 0 <= \result <= strlen(s);
  @*/
extern size_t strcspn(const char *s, const char *reject);

/*@ requires valid_string_src: valid_read_string(s);
  @ requires valid_string_accept: valid_read_string(accept);
  @ assigns \result \from s[0..], accept[0..];
  @ ensures 0 <= \result <= strlen(s);
  @*/
extern size_t strspn(const char *s, const char *accept);

/*@ requires valid_string_src: valid_read_string(s);
  @ requires valid_string_accept: valid_read_string(accept);
  @ assigns \result \from s, s[0..], accept[0..];
  @ ensures \result == 0 || \base_addr(\result) == \base_addr(s);
  @*/
extern char *strpbrk(const char *s, const char *accept);

/*@ requires valid_string_haystack: valid_read_string(haystack);
  @ requires valid_string_needle: valid_read_string(needle);
  @ assigns \result \from haystack, haystack[0..], needle[0..];
  @ ensures \result == 0
  @      || (\subset(\result, haystack+(0..)) && \valid_read(\result)
  @          && memcmp{Pre,Pre}(\result,needle,strlen(needle)) == 0);
  @*/
extern char *strstr(const char *haystack, const char *needle);

/*@ requires valid_string_src: valid_string_or_null(s);
  @ requires valid_string_delim: valid_read_string(delim);
  @ assigns \result \from s, s[0..], delim[0..];
  @ ensures \result == \null
            || \base_addr(\result) == \base_addr(s);
  @*/
extern char *strtok(char *restrict s, const char *restrict delim);

/*@ requires valid_string_src: \valid(stringp) && valid_string(*stringp);
  @ requires valid_string_delim: valid_read_string(delim);
  @ assigns *stringp \from delim[..], *stringp[..];
  @ assigns \result \from delim[..], *stringp[..];
  @*/
extern char *strsep (char **stringp, const char *delim);


/*@ assigns \result \from errnum;
  @ ensures valid_read_string(\result);
  @*/
extern char *strerror(int errnum);

// Copy strings

/*@ requires valid_string_src: valid_read_string(src);
  @ requires room_string: \valid(dest+(0..strlen(src)));
  @ requires \separated(dest+(0..strlen(dest)), src+(0..strlen(src)));
  @ assigns dest[0..strlen(src)] \from src[0..strlen(src)];
  @ assigns \result \from dest;
  @ ensures strcmp(dest,src) == 0;
  @ ensures \result == dest;
  @*/
extern char *strcpy(char *restrict dest, const char *restrict src);

/*@ 
  @ requires valid_string_src: valid_read_string(src) || \valid(src+(0..n-1));
  @ requires valid_string_dst: valid_string(dest);
  @ requires room_string: \valid(dest + (0 .. strlen(src))) || \valid(dest + (0 .. n-1));
  @ requires \separated(dest+(0..strlen(dest)), src+(0..strlen(src))) || \separated(dest+(0..strlen(dest)), src+(0..n-1));
  @ assigns dest[0..n - 1] \from src[0..n-1];
  @ assigns \result \from dest;
  @ ensures \result == dest;
  @ ensures \initialized(dest+(0 .. n-1));
  @ behavior complete:
  @   assumes strlen(src) < n;
  @   ensures strcmp(dest,src) == 0;
  @ behavior partial:
  @   assumes n <= strlen(src);
  @   ensures memcmp{Post,Post}(dest,src,n) == 0;
  @*/
extern char *strncpy(char *restrict dest,
             const char *restrict src, size_t n);

// stpcpy is POSIX.1-2008
#ifdef _POSIX_C_SOURCE
# if _POSIX_C_SOURCE >= 200809L
/*@ requires valid_string_src: valid_read_string(src);
  @ requires room_string: \valid(dest+(0..strlen(src)));
  @ assigns dest[0..strlen(src)] \from src[0..strlen(src)];
  @ assigns \result \from dest;
  @ ensures strcmp(dest,src) == 0;
  @ ensures \result == dest + strlen(dest);
  @*/
extern char *stpcpy(char *restrict dest, const char *restrict src);
# endif
#endif

/*@ // missing: separation
  @ requires valid_string_src: valid_read_string(src);
  @ requires valid_string_dst: valid_string(dest);
  @ requires room_string: \valid(dest+(0..strlen(dest) + strlen(src)));
  @ assigns dest[strlen(dest)..strlen(dest) + strlen(src)]
  @   \from src[0..strlen(src)];
  @ ensures strlen(dest) == \old(strlen(dest) + strlen(src));
  @ assigns \result \from dest;
  @ ensures \result == dest;
  @*/
extern char *strcat(char *restrict dest, const char *restrict src);

/*@ // missing: separation
  @ requires valid_string_src: valid_read_string(src) || \valid_read(src+(0..n-1));
  @ requires valid_string_dst: valid_string(dest);
  @ requires room_string: \valid(dest + (strlen(dest) .. strlen(dest) + n)) ;
  @ assigns dest[strlen(dest) .. strlen(dest) + n] \from src[0..n];
  @ assigns \result \from dest;
  @ ensures \result == dest;
  @ behavior complete:
  @   assumes valid_read_string(src) && strlen(src) <= n;
  @   assigns dest[strlen(dest)..strlen(dest) + strlen(src)]
  @   \from src[0..strlen(src)];
  @   assigns \result \from dest;
  @   ensures strlen(dest) == \old(strlen(dest) + strlen(src));
  @ behavior partial:
  @   assumes ! (valid_read_string(src) && strlen(src) <= n);
  @   assigns dest[strlen(dest)..strlen(dest) + n]
  @   \from src[0..strlen(src)];
  @   assigns \result \from dest;
  @   ensures strlen(dest) == \old(strlen(dest)) + n;
  @*/
extern char *strncat(char *restrict dest, const char *restrict src, size_t n);

/*@ requires valid_dest: \valid(dest+(0..n - 1));
  @ requires valid_string_src: valid_read_string(src);
  @ requires \separated(dest+(0..strlen(dest)), src+(0..strlen(src)));
  @ assigns dest[0..n - 1] \from src[0..], n;
  @ assigns \result \from dest;
  @*/
extern size_t strxfrm (char *restrict dest,
               const char *restrict src, size_t n);

/* POSIX */

/*@
requires \valid(((char*)s1)+(0..n-1)) && \valid(((char*)s2)+(0..n-1));
requires \separated((char*)s1+(0..n-1), (char*)s2+(0..n-1));
assigns ((char*)s1)[0..n-1], \result \from ((char*)s2)[0..n-1], c, n;
ensures (char*)\result != \null ==> \base_addr(s1) == \base_addr(\result);
*/
void *memccpy(void *restrict s1, const void *restrict s2, int c, size_t n);

/*@
requires valid_string_src: valid_string(src);
requires room_string: \valid(dest+(0..strlen(src)));
requires \separated(dest+(0..strlen(dest)), src+(0..strlen(src)));
assigns dest[0..strlen(src)] \from src[0..strlen(src)];
assigns \result \from dest;
ensures strcmp(dest,src) == 0;
ensures \result == dest+strlen(src);
*/
char *stpcpy(char *restrict dest, const char *restrict src);

/*@
requires valid_string_src: valid_string(src);
requires room_nstring: \valid(dest+(0 .. n)) || \valid(dest+(0 .. strlen(src)));
requires \separated(dest+(0..strlen(dest)), src+(0..strlen(src))) || \separated(dest+(0..n-1), src+(0..n-1));
assigns dest[0..n - 1] \from src[0..n-1];
assigns \result \from dest;
behavior complete:
  assumes strlen(src) < n;
  ensures strcmp(dest,src) == 0;
  ensures \result == dest+strlen(src);
behavior partial:
  assumes n <= strlen(src);
  assigns dest[0..n - 1];
  ensures memcmp{Post,Post}(dest,src,n) == 0;
  ensures \result == dest+n;
*/
char *stpncpy(char *restrict dest, const char *restrict src, size_t n);

/*@
requires valid_string_s1: valid_string(s1); // over-strong
requires valid_string_s2: valid_string(s2); // over-strong
assigns \result \from s1[0..], s2[0..], locale;
*/
int strcoll_l(const char *s1, const char *s2, locale_t locale);

/*@
assigns \result \from errnum, locale;
ensures valid_string(\result);
*/
char *strerror_l(int errnum, locale_t locale);

/*@
requires \valid(strerrbuf+(0..buflen-1));
assigns \result, strerrbuf[0..buflen-1] \from errnum;
ensures valid_string(strerrbuf);
*/
int strerror_r(int errnum, char *strerrbuf, size_t buflen);

/*@
requires valid_string_src: valid_read_string(s); // over-strong
assigns \result \from s[0..n-1], n;
ensures strlen(s) < n ==> \result == strlen(s);
ensures strlen(s) >= n ==> \result == n;
*/
size_t strnlen(const char *s, size_t n);

/*@
assigns \result \from signum;
ensures \valid(\result);
*/
char *strsignal(int signum);

/*@
requires \valid(lasts);
requires valid_string_src: valid_string(s);
requires valid_string_delim: valid_string(delim);
assigns \result, *lasts \from s, s[0..], delim[0..];
ensures \result == \null || \base_addr(\result) == \base_addr(s);
*/
char *strtok_r(char *restrict s, const char *restrict delim, char **restrict lasts);

/*@
requires valid_dest: \valid(dest+(0..n - 1));
requires valid_string_src: valid_string(src);
assigns dest[0..n - 1] \from src[0..], n, locale;
assigns \result \from dest;
*/
size_t strxfrm_l(char *restrict dest, const char *restrict src, size_t n, locale_t locale);

/*@ requires valid_string_src: valid_read_string(s);
  @ assigns \result; // FIXME
  @ ensures \valid(\result+(0..strlen(s))) && strcmp(\result,s) == 0;
  @*/
char *strdup (const char *s);

/*@ requires valid_string_src: valid_read_string(s); // FIXME
  @ assigns \result; // FIXME
  @ ensures \valid(\result+(0..minimum(strlen(s),n)))
  @         && valid_string(\result) && strlen(\result) <= n
  @         && strncmp(\result,s,n) == 0;
  @*/
char *strndup (const char *s, size_t n);

/* GNU Extensions */

/*@ requires valid_dst: \valid(((char*)dest)+(0..n - 1));
  @ requires valid_src: \valid_read(((char*)src)+(0..n - 1));
  @ requires \separated(((char *)dest)+(0..n-1),((char *)src)+(0..n-1));
  @ assigns ((char*)dest)[0..n - 1] \from ((char*)src)[0..n-1];
  @ assigns \result \from dest;
  @ ensures memcmp{Post,Pre}((char*)dest,(char*)src,n) == 0;
  @ ensures \result == dest+n;
  @*/
void * mempcpy (void *restrict dest, const void *restrict src, size_t n);

/*@ requires valid_string_src: valid_read_string(s);
  @ assigns \result; // FIXME
  @ ensures \valid(\result+(0..strlen(s))) && strcmp(\result,s) == 0;
  @*/
char * strdupa (const char *s);

/*@ requires valid_string_src: valid_read_string(s); // FIXME
  @ assigns \result; // FIXME
  @ ensures \valid(\result+(0..minimum(strlen(s),n)))
  @         && valid_string(\result) && strlen(\result) <= n
  @         && strncmp(\result,s,n) == 0;
  @*/
char *strndupa (const char *s, size_t n);

/*@ requires \valid_read(((char*)s)+(0..\block_length(s)));
  @ requires memchr((char*)s,c,\block_length(s));
  @ assigns \result \from s, c, ((char*)s)[0..\block_length(s)];
  @   ensures \base_addr(\result) == \base_addr(s);
  @   ensures *(char*)\result == c;
  @   ensures \forall integer i;
  @     0 <= i < \block_length(s) ==> *((char*)s+i) == c
  @     ==> \result <= s+i;
  @*/
void * rawmemchr (const void *s, int c);

/*@ requires \valid_read(((char*)s)+(0..n - 1));
  @ assigns \result \from s, c, ((char*)s)[0..n-1];
  @ behavior found:
  @   assumes memchr((char*)s,c,n);
  @   ensures \base_addr(\result) == \base_addr(s);
  @   ensures *(char*)\result == c;
  @   ensures \forall integer i;
  @     0 <= i < n ==> *((char*)s+i) == c
  @     ==> \result <= s+i;
  @ behavior not_found:
  @   assumes ! memchr((char*)s,c,n);
  @   ensures \result == \null;
  @*/
void * memrchr (const void *s, int c, size_t n);

/*@ requires valid_string_src: valid_read_string(s);
  @ assigns \result \from s, s[0..],c;
  @ behavior found:
  @   assumes strchr(s,c);
  @   ensures *\result == c;
  @   ensures \base_addr(\result) == \base_addr(s);
  @   ensures s <= \result < s + strlen(s);
  @   ensures valid_read_string(\result);
  @   ensures \forall char* p; s<=p<\result ==> *p != c;
  @ behavior not_found:
  @   assumes ! strchr(s,c);
  @   ensures \result == s+strlen(s);
  @ behavior default:
  @ ensures \result == \null || \base_addr(\result) == \base_addr(s);
  @*/
char * strchrnul (const char *s, int c);

/*@ requires valid_string_haystack: \valid_read(((char*)haystack)+(0..haystack_len-1));
  @ requires valid_string_needle: \valid_read(((char*)needle)+(0..needle_len-1));
  @ assigns \result \from ((char*)haystack)[0..haystack_len-1], ((char*)needle)[0..needle_len-1];
  @ ensures \result == \null
  @      || (\base_addr(\result) == \base_addr(haystack) && \result >= haystack && \valid_read((char*)\result)
  @          && memcmp{Pre,Pre}((char*)\result,((char*)needle),needle_len) == 0);
  @*/
void * memmem (const void *haystack, size_t haystack_len, const void *needle, size_t needle_len);

/*@
requires \valid(((char*)mem)+(0..length-1));
assigns ((char*)mem)[0..length-1] \from ((char*)mem)[0..length-1], length;
ensures \forall size_t i; 0 <= i < length ==> ((char*)mem)[i] == (((char)\old(((char*)mem)[i])) ^ ((char)0b00101010));
ensures \result == mem;
*/
void * memfrob (void *mem, size_t length);

/*@
requires valid_string(string);
assigns \result, string[0..strlen(string)-1] \from string[0..strlen(string)-1];
ensures valid_string(string);
ensures \result == string;
*/
char * strfry (char *string);

__END_DECLS

/* Include strings.h: this is what BSD does, and glibc does something
   equivalent (having copied prototypes to string.h). */
#include <strings.h>

#endif /* _STRING_H_ */
