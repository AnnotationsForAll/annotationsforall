// Notice from frama-c
/**************************************************************************/
/*                                                                        */
/*  This file is part of Frama-C.                                         */
/*                                                                        */
/*  Copyright (C) 2007-2014                                               */
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

#ifndef __GT_FC_STDLIB_H_
#define __GT_FC_STDLIB_H_

/** Directly from frama-c Neon **/
#include "__fc_define_size_t.h"
#include "__fc_define_wchar_t.h"
#include "__fc_string_axiomatic.h"
#include "__gt_fc_define_comparison_fn_t.h"
#include "__gt_fc_define_alternative_types.h"
#include "__gt_fc_heap_axiomatics.h"
#include "__gt_fc_define_locale_t.h"
#include "__gt_fc_define_mbstate_t.h"
#include "features.h"
#include "crypt.h"
#include "alloca.h"

__BEGIN_DECLS

typedef struct __fc_div_t {
  int quot;              /* Quotient.  */
  int rem;               /* Remainder.  */
} div_t;
typedef struct __fc_ldiv_t {
  long int quot;              /* Quotient.  */
  long int rem;               /* Remainder.  */
} ldiv_t;

typedef struct __fc_lldiv_t {
  long long int quot;              /* Quotient.  */
  long long int rem;               /* Remainder.  */
} lldiv_t;

#include "__fc_define_null.h"

/* These could be customizable */
#define EXIT_FAILURE (-1)
#define EXIT_SUCCESS 0

#include "limits.h"
#include "errno.h"

#define RAND_MAX __FC_RAND_MAX
/** End directly from frama-c Neon **/

/****** abs ******/

/*@
  requires abs_representable:(int)(-j) == -j ;
  assigns \result \from j ;
  behavior positive:
    assumes j >= 0;
    ensures \result == j;
  behavior negative:
    assumes j < 0;
    ensures \result == -j;
  complete behaviors; disjoint behaviors;
*/
int abs(int j);

/*@
  requires abs_representable:(long)(-j) == -j ;
  assigns \result \from j ;
  behavior positive:
    assumes j >= 0;
    ensures \result == j;
  behavior negative:
    assumes j < 0;
    ensures \result == -j;
  complete behaviors; disjoint behaviors;
*/
long int labs(long int j);

/*@
  requires abs_representable:(long long)(-j) == -j ;
  assigns \result \from j ;
  behavior positive:
    assumes j >= 0;
    ensures \result == j;
  behavior negative:
    assumes j < 0;
    ensures \result == -j;
  complete behaviors; disjoint behaviors;
*/
long long int llabs(long long int j);

/*@
    // If either part of the result cannot be represented, the behavior is undefined
    requires no_div_by_zero:    denom != 0;
    // Overflow can occur during two's complement signed integer division when the dividend is equal to the minimum (negative) value for the signed integer type and the divisor is equal to −1
    requires div_representable: (int)(numer/denom) == (numer/denom);
    assigns \result \from numer, denom;
    ensures \result.quot == numer / denom;
    ensures \result.rem  == numer % denom;
*/
div_t div(int numer, int denom);

/*@
    requires no_div_by_zero:    denom != 0;
    requires div_representable: (long int)(numer/denom) == (numer/denom);
    assigns \result \from numer,denom ;
    ensures \result.quot == numer / denom;
    ensures \result.rem  == numer % denom;
*/
ldiv_t ldiv(long int numer, long int denom);

/*@
    requires no_div_by_zero:    denom != 0;
    requires div_representable: (long long int)(numer/denom) == (numer/denom);
    assigns \result \from numer,denom ;
    ensures \result.quot == numer / denom;
    ensures \result.rem  == numer % denom;
*/
lldiv_t lldiv(long long int numer, long long int denom);

/*@
requires \valid(nptr);
assigns \result \from nptr[..];
*/
double atof(const char *nptr);

/*@
requires \valid(nptr);
assigns \result \from nptr[..];
*/
int atoi(const char *nptr);

/*@
requires \valid(nptr);
assigns \result \from nptr[..];
*/
long int atol(const char *nptr);

/*@
requires \valid(nptr);
assigns \result \from nptr[..];
*/
long long int atoll(const char *nptr);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
double strtod(const char * restrict nptr, char ** restrict endptr);
/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
float strtof(const char * restrict nptr, char ** restrict endptr);
/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..];
ensures endptr != \null ==> \valid(*endptr);
*/
long double strtold(const char * restrict nptr, char ** restrict endptr);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..], base;
ensures endptr != \null ==> \valid(*endptr);
*/
long int strtol(const char * restrict nptr, char ** restrict endptr, int base);
/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..], base;
ensures endptr != \null ==> \valid(*endptr);
*/
long long int strtoll(const char * restrict nptr, char ** restrict endptr, int base);
/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..], base;
ensures endptr != \null ==> \valid(*endptr);
*/
unsigned long int strtoul(const char * restrict nptr, char ** restrict endptr, int base);
/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..], base;
ensures endptr != \null ==> \valid(*endptr);
*/
unsigned long long int strtoull(const char * restrict nptr, char ** restrict endptr, int base);

/*@
axiomatic Rand {
    logic int rand(unsigned seed);
    
    axiom rand_bounds: \forall unsigned x; 0 <= rand(x) <= RAND_MAX;
}

axiomatic SRand {
    logic unsigned int srand_seed(unsigned int input);
}
*/

//@ ghost unsigned __fc_random_counter __attribute__((unused)) __attribute__((FRAMA_C_MODEL));
const unsigned long __fc_rand_max = __FC_RAND_MAX;

/* ISO C: 7.20.2 */
/*@
assigns \result \from __fc_random_counter;
assigns __fc_random_counter;
ensures __fc_random_counter != \old(__fc_random_counter);
ensures \result == rand(\old(__fc_random_counter));
*/
int rand(void);

/*@
assigns __fc_random_counter \from seed;
ensures __fc_random_counter == srand_seed(seed);
*/
void srand(unsigned int seed);

/* ISO C: 7.20.3.1 */

/*@ requires no_overflow: (size * nmemb) == (size_t)(size * nmemb);
  @ allocates \result;
  @ assigns __fc_heap_status \from size, nmemb, __fc_heap_status;
  @ assigns \result \from size, nmemb, __fc_heap_status;
  @ behavior allocation:
  @   assumes is_allocable((size_t)(size * nmemb));
  @   assigns __fc_heap_status \from size, nmemb, __fc_heap_status;
  @   assigns \result \from size, nmemb, __fc_heap_status;
  @   ensures \fresh(\result,size);
  @   ensures all_zero: \forall integer i; (0 <= i < ((size * nmemb)/sizeof(char))) ==> ((char*)\result)[i] == 0;
  @ behavior no_allocation:
  @   assumes !is_allocable((size_t)(size * nmemb));
  @   assigns \result \from \nothing;
  @   allocates \nothing;
  @   ensures \result==\null;
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
void *calloc(size_t nmemb, size_t size);

/*@ allocates \result;
  @ assigns __fc_heap_status \from size, __fc_heap_status;
  @ assigns \result \from size, __fc_heap_status;
  @ behavior allocation:
  @   assumes is_allocable(size);
  @   assigns __fc_heap_status \from size, __fc_heap_status;
  @   assigns \result \from size, __fc_heap_status;
  @   ensures \fresh(\result,size);
  @ behavior no_allocation:
  @   assumes !is_allocable(size);
  @   assigns \result \from \nothing;
  @   allocates \nothing;
  @   ensures \result==\null;
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
void *malloc(size_t size);

/*@ frees p;
  @ assigns  __fc_heap_status \from __fc_heap_status;
  @ behavior deallocation:
  @   assumes  p!=\null;
  @   requires freeable:\freeable(p);
  @   assigns  __fc_heap_status \from __fc_heap_status;
  @   ensures  \allocable(p);
  @ behavior no_deallocation:
  @   assumes  p==\null;
  @   assigns  \nothing;
  @   frees    \nothing;
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
void free(void *p);

#ifdef FRAMA_C_MALLOC_POSITION
#define __FRAMA_C_STRINGIFY(x) #x
#define __FRAMA_C_XSTRINGIFY(x) __FRAMA_C_STRINGIFY(x)
#define FRAMA_C_LOCALIZE_WARNING (" file " __FILE__ " line " __FRAMA_C_XSTRINGIFY(__LINE__))
#define malloc(x) (__Frama_C_malloc_at_pos(x,__FILE__ "_function_" __func__ "_line_" __FRAMA_C_XSTRINGIFY(__LINE__)))
#define free(x) (__Frama_C_free_at_pos(x,FRAMA_C_LOCALIZE_WARNING))
void *__Frama_C_malloc_at_pos(size_t size,const char* file);
void __Frama_C_free_at_pos(void* ptr,const char* pos);
#endif

/*@
   requires ptr == \null || \freeable(ptr);
   allocates \result;
   frees     ptr;
   assigns   __fc_heap_status \from __fc_heap_status;
   assigns   \result \from size, ptr, __fc_heap_status;

   behavior alloc:
     assumes   is_allocable(size);
     allocates \result;
     assigns   \result \from size, __fc_heap_status;
     ensures   \fresh(\result,size);

   behavior dealloc:
     assumes   ptr != \null;
     assumes   is_allocable(size);
     requires  \freeable(ptr);
     frees     ptr;
     ensures   \allocable(ptr);
     ensures   \result == \null || \freeable(\result);

   behavior fail:
     assumes !is_allocable(size);
     allocates \nothing;
     frees     \nothing;
     assigns   \result \from size, __fc_heap_status;
     ensures   \result == \null;

   complete behaviors;
   disjoint behaviors alloc, fail;
   disjoint behaviors dealloc, fail;
  */
void *realloc(void *ptr, size_t size);


/* ISO C: 7.20.4 */

/*@ assigns \nothing;
  @ ensures \false; */
void abort(void);

/*@ assigns \result \from \nothing ;*/
int atexit(void (*func)(void));

/*@ assigns \result \from \nothing ;*/
int at_quick_exit(void (*func)(void));

/*@
  assigns \nothing;
  ensures \false;
*/
void exit(int status) __attribute__ ((noreturn));

/*@
  assigns \nothing;
  ensures \false;
*/
void _Exit(int status) __attribute__ ((__noreturn__));

/*@ assigns \nothing ;
  ensures \result == \null || \valid(\result) ;
 */
char *getenv(const char *name);

/*@
  assigns \nothing;
  ensures \false; */
void quick_exit(int status) __attribute__ ((__noreturn__));

/*@ assigns \result \from string[..]; */
int system(const char *string);

/* ISO C: 7.20.5 */

/*@
requires \valid((char*)key);
requires \valid(((char*)base)+(0..(size*nmemb-1)));
requires compar != \null;
//TODO: require that compar acts like it should
//TODO: require that base be sorted according to compar
behavior found:
    //assigns ((char*)\result)[..] \from key, ((char*)base)[..], nmemb, size, compar; //FIXME: this line causes a crash when uncommented
    ensures base <= \result <= base+(nmemb*size-1);
behavior not_found:
    ensures \result == \null;
disjoint behaviors; complete behaviors;
*/
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

/*@
requires \valid(((char*)base)+(0..(size*nmemb-1)));
requires compar != \null;
//assigns ((char*)\base)[..] \from ((char*)base)[..], nmemb, size, compar; //FIXME: this line causes a crash when uncommented
*/
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

/* ISO C: 7.20.6 */

/* ISO C: 7.20.7 */
/*@ assigns \result \from s[0..], n ;*/
int mblen(const char *s, size_t n);

/*@
    assigns \result, pwc[0..n-1] \from s[0..n-1], n ;
    ensures (s != \null && *s == '\0') ==> (\result == 0);
    ensures (s != \null && *s != '\0') ==> (\result == -1 || \result > 0);
    ensures \result <= n;
    ensures \result <= MB_CUR_MAX;
*/
int mbtowc(wchar_t * restrict pwc,
     const char * restrict s,
     size_t n);

/*@
    assigns \result, s[0..] \from wc ;
    ensures (s != \null) ==> ((\result == -1) || (0 < \result < MB_CUR_MAX));
*/
int wctomb(char *s, wchar_t wc);

/* ISO C: 7.20.8 */

/*@
    requires \separated(pwcs, s);
    assigns \result, pwcs[0..n-1] \from s[0..n-1], n ;
    ensures (\result == (size_t)(-1)) || (0 <= \result < n);
*/
size_t mbstowcs(wchar_t * restrict pwcs,
     const char * restrict s,
     size_t n);

/*@
    assigns \result, s[0..n-1] \from pwcs[0..n-1] , n ;
    ensures (\result == (size_t)(-1)) || (0 <= \result < n);
*/
size_t wcstombs(char * restrict s,
     const wchar_t * restrict pwcs,
     size_t n);

/* POSIX */

/*@
requires \valid(s);
assigns \result \from s[..];
ensures \result >= 0;
*/
long a64l(const char *s);

/*@
requires value >= 0;
assigns \result \from value;
ensures \valid(\result);
*/
char *l64a(long value);

//@ ghost short __gt_fc_rand48_seed[7];

/*@
assigns \result, __gt_fc_rand48_seed[0..2] \from __gt_fc_rand48_seed[0..6];
ensures  0 <= \result < 1;
*/
double drand48(void);

/*@
requires \valid(xsubi+(0..2));
assigns \result, xsubi[0..2] \from xsubi[0..2], __gt_fc_rand48_seed[3..6];
ensures  0 <= \result < 1;
*/
double erand48(unsigned short xsubi[3]);

/*@
requires \valid(xsubi+(0..2));
assigns \result, xsubi[0..2] \from xsubi[0..2], __gt_fc_rand48_seed[3..6];
ensures  -2147483648 <= \result < 2147483648;
*/
long jrand48(unsigned short xsubi[3]);

/*@
requires \valid(param+(0..6));
assigns __gt_fc_rand48_seed[0..6] \from param[0..6];
*/
void lcong48(unsigned short param[7]);

/*@
assigns \result, __gt_fc_rand48_seed[0..2] \from __gt_fc_rand48_seed[0..6];
ensures  0 <= \result < 2147483648;
*/
long lrand48(void);

/*@
assigns \result, __gt_fc_rand48_seed[0..2] \from __gt_fc_rand48_seed[0..6];
ensures  -2147483648 <= \result < 2147483648;
*/
long mrand48(void);

/*@
requires \valid(xsubi+(0..2));
assigns \result, xsubi[0..2] \from xsubi[0..2], __gt_fc_rand48_seed[3..6];
ensures  0 <= \result < 2147483648;
*/
long nrand48(unsigned short xsubi[3]);

/*@
requires \valid(seed16v+(0..2));
assigns __gt_fc_rand48_seed[0..2] \from seed16v[0..2];
ensures \valid(\result+(0..2));
*/
unsigned short *seed48(unsigned short seed16v[3]);

/*@
assigns __gt_fc_rand48_seed[0..2] \from seedval;
*/
void srand48(long seedval);

/*@
requires \valid(optionp);
requires \valid(keylistp);
requires \valid(valuep);
assigns \result, *valuep, *optionp \from *optionp, *keylistp;
ensures \result >= -1;
*/
int getsubopt(char **optionp, char * const *keylistp, char **valuep);

/*@
assigns \result, errno \from fildes;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int grantpt(int fildes);

//@ ghost size_t __gt_fc_random_state_size;
//@ ghost char* __gt_fc_random_state;

/*@
requires \valid(state+(0..size-1));
assigns \result, __gt_fc_random_state_size, __gt_fc_random_state \from seed, state[0..size-1], size;
ensures size < 8 ==> \result == \null;
ensures \result != \null ==> \result == state;
ensures \result != \null ==> (__gt_fc_random_state_size == size);
ensures \result != \null ==> (__gt_fc_random_state == state);
*/
char *initstate(unsigned seed, char *state, size_t size);

/*@
assigns \result, __gt_fc_random_state[0..__gt_fc_random_state_size-1] \from __gt_fc_random_state[0..__gt_fc_random_state_size-1], __gt_fc_random_state_size;
*/
long random(void);

/*@
requires \valid(state+(0..__gt_fc_random_state_size-1));
assigns \result, __gt_fc_random_state_size, __gt_fc_random_state \from state[0..__gt_fc_random_state_size-1];
ensures \result != \null ==> \result == state;
ensures \result != \null ==> (__gt_fc_random_state == state);
*/
char *setstate(char *state);

/*@
assigns __gt_fc_random_state[0..__gt_fc_random_state_size-1] \from __gt_fc_random_state[0..__gt_fc_random_state_size-1], __gt_fc_random_state_size, seed;
*/
void srandom(unsigned seed);

/*@
requires \valid(template);
assigns \result, template[..], errno \from template[..];
ensures \result != \null ==> \result == template;
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
char *mkdtemp(char *template);

/*@
requires \valid(template);
assigns \result, template[..], errno \from template[..];
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mkstemp(char *template);

/*@
assigns \result \from oflag;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int posix_openpt(int oflag);

/*@
assigns \result \from fildes;
ensures \result != \null ==> \valid(\result);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
char *ptsname(int fildes);

/*@
requires \valid(string);
assigns \result \from string[..];
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int putenv(char *string);

/*@
requires \valid(file_name);
requires resolved_name != \null ==> \valid(resolved_name+(0.. PATH_MAX-1));
assigns \result, resolved_name[0.. PATH_MAX-1] \from file_name[..];
ensures \result != \null ==> \valid(\result);
ensures resolved_name != \null ==> \result == resolved_name;
*/
char *realpath(const char *restrict file_name, char *restrict resolved_name);

/*@
requires \valid(envname);
requires \valid(envval);
assigns \result, errno \from envname[..], envval[..], overwrite;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setenv(const char *envname, const char *envval, int overwrite);

/*@
assigns \result, errno \from fildes;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int unlockpt(int fildes);

/*@
requires \valid(name);
assigns \result \from name[..];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int unsetenv(const char *name);

/* GNU Extensions */

#define cfree free
#define strtoq strtoll
#define wcstoq wcstoll
#define strtouq strtoull
#define wcstouq wcstoull

struct drand48_data {
    short __gt_fc_data[7];
};

struct random_data {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
};

/*@
requires \valid(template);
assigns \result, template[..], errno \from template[..];
ensures \result != \null ==> \valid(\result);
*/
char * mktemp (char *template);

/*@ allocates \result;
  @ assigns __fc_heap_status \from size, __fc_heap_status;
  @ assigns \result \from size, __fc_heap_status;
  @ behavior allocation:
  @   assumes is_allocable(size);
  @   assigns __fc_heap_status \from size, __fc_heap_status;
  @   assigns \result \from size, __fc_heap_status;
  @   ensures \fresh(\result,size);
  @ behavior no_allocation:
  @   assumes !is_allocable(size);
  @   assigns \result \from \nothing;
  @   allocates \nothing;
  @   ensures \result==\null;
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
void * aligned_alloc (size_t alignment, size_t size);

/*@ allocates \result;
  @ assigns __fc_heap_status \from size, __fc_heap_status;
  @ assigns \result \from size, __fc_heap_status;
  @ behavior allocation:
  @   assumes is_allocable(size);
  @   assigns __fc_heap_status \from size, __fc_heap_status;
  @   assigns \result \from size, __fc_heap_status;
  @   ensures \fresh(\result,size);
  @ behavior no_allocation:
  @   assumes !is_allocable(size);
  @   assigns \result \from \nothing;
  @   allocates \nothing;
  @   ensures \result==\null;
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
void * memalign (size_t boundary, size_t size);

/*@ allocates \result;
  @ assigns __fc_heap_status \from size, __fc_heap_status;
  @ assigns \result \from size, __fc_heap_status;
  @ behavior allocation:
  @   assumes is_allocable(size);
  @   assigns *memptr, __fc_heap_status \from size, __fc_heap_status;
  @   assigns \result \from size, __fc_heap_status;
  @   ensures \fresh(*memptr,size);
  @   ensures \result == 0;
  @ behavior no_allocation:
  @   assumes !is_allocable(size);
  @   assigns *memptr, \result \from \nothing;
  @   allocates \nothing;
  @   ensures *memptr==\null;
  @   ensures \result != 0;
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
int posix_memalign (void **memptr, size_t alignment, size_t size);

/*@ allocates \result;
  @ assigns __fc_heap_status \from size, __fc_heap_status;
  @ assigns \result \from size, __fc_heap_status;
  @ behavior allocation:
  @   assumes is_allocable(size);
  @   assigns __fc_heap_status \from size, __fc_heap_status;
  @   assigns \result \from size, __fc_heap_status;
  @   ensures \fresh(\result,size);
  @ behavior no_allocation:
  @   assumes !is_allocable(size);
  @   assigns \result \from \nothing;
  @   allocates \nothing;
  @   ensures \result==\null;
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
void * valloc (size_t size);

/*@ allocates \result;
  @ assigns __fc_heap_status \from size, __fc_heap_status;
  @ assigns \result \from size, __fc_heap_status;
  @ behavior allocation:
  @   assumes is_allocable(size);
  @   assigns __fc_heap_status \from size, __fc_heap_status;
  @   assigns \result \from size, __fc_heap_status;
  @   ensures \fresh(\result,size);
  @ behavior no_allocation:
  @   assumes !is_allocable(size);
  @   assigns \result \from \nothing;
  @   allocates \nothing;
  @   ensures \result==\null;
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
void * pvalloc (size_t size);

/*@
assigns errno, \result \from \nothing;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int getpt (void);

/*@
requires \valid(buf+(0..len-1));
assigns \result, buf[0..len-1] \from fildes, len;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int ptsname_r (int fildes, char *buf, size_t len);

/*@ assigns \nothing ;
  ensures \result == \null || \valid(\result) ;
 */
char * secure_getenv (const char *name);

/*@
requires \valid(name);
assigns errno, \result \from name[0..];
ensures \result != \null ==> \valid(\result);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
char * canonicalize_file_name (const char *name);

/*@
requires \valid(response);
assigns \result \from response[0..];
ensures -1 <= \result <= 1;
*/
int rpmatch (const char *response);

/*@
behavior lt_3:
    assumes nelem <= 3;
    requires \valid(loadavg+(0..nelem-1));
    assigns \result, loadavg[0..nelem-1] \from nelem;
    ensures -1 <= \result <= 3;
behavior gt_3:
    assumes nelem > 3;
    requires \valid(loadavg+(0..2));
    assigns \result, loadavg[0..2] \from nelem;
    ensures -1 <= \result <= 3;
complete behaviors; disjoint behaviors;
*/
int getloadavg (double loadavg[], int nelem);

/*@
assigns \result;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int clearenv(void);

/*@
requires \valid(buffer);
requires \valid(result);
assigns \result, buffer[0..2], *result \from buffer[0..6];
ensures  0 <= *result < 1;
ensures \result == 0;
*/
int drand48_r(struct drand48_data *restrict buffer, double *restrict result);

/*@
requires \valid(buffer);
requires \valid(result);
requires \valid(xsubi+(0..2));
assigns \result, xsubi[0..2], *result \from xsubi[0..2], buffer->__gt_fc_data[3..6];
ensures  0 <= *result < 1;
ensures \result == 0;
*/
int erand48_r(unsigned short int xsubi[3], struct drand48_data *restrict buffer, double *restrict result);

/*@
requires \valid(buffer);
requires \valid(result);
assigns \result, buffer->__gt_fc_data[0..2], *result \from buffer->__gt_fc_data[0..6];
ensures  0 <= *result < 2147483648;
ensures \result == 0;
*/
int lrand48_r(struct drand48_data *restrict buffer, long int *restrict result);

/*@
requires \valid(buffer);
requires \valid(result);
requires \valid(xsubi+(0..2));
assigns \result, xsubi[0..2], *result \from xsubi[0..2], buffer->__gt_fc_data[3..6];
ensures  0 <= *result < 2147483648;
ensures \result == 0;
*/
int nrand48_r(unsigned short int xsubi[3], struct drand48_data *restrict buffer, long int *restrict result);

/*@
requires \valid(buffer);
requires \valid(result);
assigns \result, buffer->__gt_fc_data[0..2], *result \from buffer->__gt_fc_data[0..6];
ensures  -2147483648 <= *result < 2147483648;
ensures \result == 0;
*/
int mrand48_r(struct drand48_data *restrict buffer, long int *restrict result);

/*@
requires \valid(buffer);
requires \valid(result);
requires \valid(xsubi+(0..2));
assigns \result, xsubi[0..2], *result \from xsubi[0..2], buffer->__gt_fc_data[3..6];
ensures  -2147483648 <= *result < 2147483648;
ensures \result == 0;
*/
int jrand48_r(unsigned short int xsubi[3], struct drand48_data *restrict buffer, long int *restrict result);

/*@
requires \valid(buffer);
assigns \result, buffer->__gt_fc_data[0..2] \from seedval;
ensures \result == 0;
*/
int srand48_r(long int seedval, struct drand48_data *buffer);

/*@
requires \valid(buffer);
requires \valid(seed16v+(0..2));
assigns \result, buffer->__gt_fc_data[0..2] \from seed16v[0..2];
ensures \result == 0;
*/
int seed48_r(unsigned short int seed16v[3], struct drand48_data *buffer);

/*@
requires \valid(buffer);
requires \valid(param+(0..6));
assigns __gt_fc_rand48_seed[0..6] \from param[0..6];
ensures \result == 0;
*/
int lcong48_r(unsigned short int param[7], struct drand48_data *buffer);

/*@
axiomatic RandomReentrant {
    logic boolean random_r_is_open(struct random_data * buf);
    logic size_t random_r_state_size(struct random_data * buf);
}
*/

/*@
requires buf != \null ==> \valid(buf);
requires result != \null ==> \valid(result);
requires random_r_is_open(buf);
assigns *buf, *result \from *buf;
ensures random_r_is_open(buf);
ensures random_r_state_size(buf) == \old(random_r_state_size(buf));
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int random_r(struct random_data *restrict buf, int32_t *restrict result);

/*@
requires buf != \null ==> \valid(buf);
requires random_r_is_open(buf);
assigns *buf \from *buf, seed;
ensures random_r_is_open(buf);
ensures random_r_state_size(buf) == \old(random_r_state_size(buf));
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int srandom_r(unsigned int seed, struct random_data *buf);

/*@
requires buf != \null ==> \valid(buf);
requires \valid(statebuf+(0..statelen-1));
assigns *buf, statebuf[0..statelen-1];
ensures \result == 0 ==> random_r_is_open(buf);
ensures \result == 0 ==> random_r_state_size(buf) == statelen;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int initstate_r(unsigned int seed, char *restrict statebuf, size_t statelen, struct random_data *restrict buf);

/*@
requires buf != \null ==> \valid(buf);
requires \valid(statebuf+(0..random_r_state_size(buf)-1));
assigns *buf, statebuf[0..random_r_state_size(buf)-1];
ensures random_r_is_open(buf);
ensures random_r_state_size(buf) == \old(random_r_state_size(buf));
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int setstate_r(char *restrict statebuf, struct random_data *restrict buf);

/*@
requires \valid(template);
assigns \result, template[..], errno \from template[..], flags;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mkostemp(char *template, int flags);

/*@
requires \valid(template);
assigns \result, template[..], errno \from template[..], flags;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mkostemp64(char *template, int flags);

/*@
requires \valid(template);
assigns \result, template[..], errno \from template[..], suffixlen, flags;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mkostemps(char *template, int suffixlen, int flags);

/*@
requires \valid(template);
assigns \result, template[..], errno \from template[..], suffixlen, flags;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mkostemps64(char *template, int suffixlen, int flags);

/*@
requires \valid(template);
assigns \result, template[..], errno \from template[..];
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mkstemp64(char *template);

/*@
requires \valid(template);
assigns \result, template[..], errno \from template[..], suffixlen;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mkstemps(char *template, int suffixlen);

/*@
requires \valid(template);
assigns \result, template[..], errno \from template[..], suffixlen;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mkstemps64(char *template, int suffixlen);

/*@
requires \valid(((char*)base)+(0..(size*nmemb-1)));
requires compar != \null;
*/
void qsort_r (void *base, size_t nmemb, size_t size, comparison_fn_t compar, void *arg);

/*@
requires \valid(seed);
assigns \result, *seed \from *seed;
ensures *seed != \old(*seed);
ensures \result == rand(\old(*seed));
*/
int rand_r(unsigned int *seed);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..], base, loc;
ensures endptr != \null ==> \valid(*endptr);
*/
long int strtol_l(const char *restrict nptr, char **restrict endptr, int base, locale_t loc);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..], base, loc;
ensures endptr != \null ==> \valid(*endptr);
*/
unsigned long int strtoul_l(const char *restrict nptr, char **restrict endptr, int base, locale_t  loc);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..], base, loc;
ensures endptr != \null ==> \valid(*endptr);
*/
long long int strtoll_l(const char *restrict nptr, char **restrict endptr, int base, locale_t loc);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..], base, loc;
ensures endptr != \null ==> \valid(*endptr);
*/
unsigned long long int strtoull_l(const char *restrict nptr, char **restrict endptr, int base, locale_t  loc);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..], loc;
ensures endptr != \null ==> \valid(*endptr);
*/
double strtod_l(const char *restrict nptr, char **restrict endptr, locale_t  loc);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..], loc;
ensures endptr != \null ==> \valid(*endptr);
*/
float strtof_l(const char *restrict nptr, char **restrict endptr, locale_t  loc);

/*@
requires endptr != \null ==> \valid(endptr);
requires \valid(nptr);
assigns \result, *endptr, errno \from nptr[..], loc;
ensures endptr != \null ==> \valid(*endptr);
*/
long double strtold_l(const char *restrict nptr, char **restrict endptr, locale_t loc);

/* SVID Extensions */

/*@
requires \valid(decpt);
requires \valid(neg);
assigns \result, *decpt, *neg \from value, ndigit;
ensures \valid(\result);
*/
char * ecvt (double value, int ndigit, int *decpt, int *neg);

/*@
requires \valid(decpt);
requires \valid(neg);
assigns \result, *decpt, *neg \from value, ndigit;
ensures \valid(\result);
*/
char * fcvt (double value, int ndigit, int *decpt, int *neg);

/*@
requires \valid(buf);
assigns \result, buf[0..] \from value, ndigit;
ensures \result == buf;
//FIXME: gcvt cannot be reasoned about, as it places an undefined number of characters into buf
*/
char * gcvt (double value, int ndigit, char *buf);

/*@
requires \valid(decpt);
requires \valid(neg);
assigns \result, *decpt, *neg \from value, ndigit;
ensures \valid(\result);
*/
char * qecvt (long double value, int ndigit, int *decpt, int *neg);

/*@
requires \valid(decpt);
requires \valid(neg);
assigns \result, *decpt, *neg \from value, ndigit;
ensures \valid(\result);
*/
char * qfcvt (long double value, int ndigit, int *decpt, int *neg);

/*@
requires \valid(buf);
assigns \result, buf[0..] \from value, ndigit;
ensures \result == buf;
//FIXME: gcvt cannot be reasoned about, as it places an undefined number of characters into buf
*/
char * qgcvt (long double value, int ndigit, char *buf);

/*@
requires \valid(buf+(0..len-1));
requires \valid(decpt);
requires \valid(neg);
assigns \result, *decpt, *neg, buf[0..len-1] \from value, ndigit, len;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> valid_string(buf);
*/
int ecvt_r (double value, int ndigit, int *decpt, int *neg, char *buf, size_t len);

/*@
requires \valid(buf+(0..len-1));
requires \valid(decpt);
requires \valid(neg);
assigns \result, *decpt, *neg, buf[0..len-1] \from value, ndigit, len;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> valid_string(buf);
*/
int fcvt_r (double value, int ndigit, int *decpt, int *neg, char *buf, size_t len);

/*@
requires \valid(buf+(0..len-1));
requires \valid(decpt);
requires \valid(neg);
assigns \result, *decpt, *neg, buf[0..len-1] \from value, ndigit, len;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> valid_string(buf);
*/
int qecvt_r (long double value, int ndigit, int *decpt, int *neg, char *buf, size_t len);

/*@
requires \valid(buf+(0..len-1));
requires \valid(decpt);
requires \valid(neg);
assigns \result, *decpt, *neg, buf[0..len-1] \from value, ndigit, len;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> valid_string(buf);
*/
int qfcvt_r (long double value, int ndigit, int *decpt, int *neg, char *buf, size_t len);

/* SunOS Extensions */

/*@
requires function != \null;
assigns \result;
*/
int on_exit (void (*function)(int status, void *arg), void *arg);

__END_DECLS

#endif /* STDLIB_H_ */

