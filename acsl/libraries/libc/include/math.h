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
// Revised from Frama-C Neon
// Updated with Frama-C Magnesium

/* ISO C: 7.12 */
#ifndef __FC_MATH
#define __FC_MATH
#include "features.h"

#include "__fc_string_axiomatic.h"
#include "__gt_fc_math_axiomatic.h"
#include "float.h"
#include "errno.h"
#include "limits.h"

__BEGIN_DECLS

typedef float float_t;
typedef double double_t;

#define MATH_ERRNO    1
#define MATH_ERREXCEPT    2

#define HUGE_VAL  (__gt_fc_huge_val(0))
#define HUGE_VALF (__gt_fc_huge_valf(0))
#define HUGE_VALL (__gt_fc_huge_vall(0))


/* The following specifications will set errno. */
#define math_errhandling    MATH_ERRNO

#define INFINITY HUGE_VALF
#define NAN nanf("1")

#define FP_ILOGB0 __FC_INT_MIN
#define FP_ILOGBNAN __FC_INT_MAX

// POSIX MACROS
# define M_E 0x1.5bf0a8b145769p1         /* e          */
# define M_LOG2E 0x1.71547652b82fep0     /* log_2 e    */
# define M_LOG10E 0x1.bcb7b1526e50ep-2   /* log_10 e   */
# define M_LN2 0x1.62e42fefa39efp-1      /* log_e 2    */
# define M_LN10 0x1.26bb1bbb55516p1      /* log_e 10   */
# define M_PI 0x1.921fb54442d18p1        /* pi         */
# define M_PI_2 0x1.921fb54442d18p0      /* pi/2       */
# define M_PI_4 0x1.921fb54442d18p-1     /* pi/4       */
# define M_1_PI 0x1.45f306dc9c883p-2     /* 1/pi       */
# define M_2_PI 0x1.45f306dc9c883p-1     /* 2/pi       */
# define M_2_SQRTPI 0x1.20dd750429b6dp0  /* 2/sqrt(pi) */
# define M_SQRT2 0x1.6a09e667f3bcdp0     /* sqrt(2)    */
# define M_SQRT1_2 0x1.6a09e667f3bcdp-1  /* 1/sqrt(2)  */

// comparison macros
#define isgreater(x,y) (((double)(x)) > ((double)(y)))
#define isgreaterequal(x,y) (((double)(x)) >= ((double)(y)))
#define isless(x,y) (((double)(x)) < ((double)(y)))
#define islessequal(x,y) (((double)(x)) <= ((double)(y)))
#define islessgreater(x,y) (((double)(x)) != ((double)(y)))
#define isunordered(x,y) (((double)(x)) == nan() || ((double)(y)) == nan())

/*
  // Provided by frama-c: unusable because uses built-ins which are not supported.
  behavior normal:
    assumes \is_finite(x) && \abs(x) <= 1;
    assigns \result;
    ensures \is_finite(\result) && \result >= 0;
  behavior edom:
    assumes \is_infinite(x) || (\is_finite(x) && \abs(x) > 1);
    assigns __FC_errno;
    ensures __FC_errno == 1;
  disjoint behaviors normal, edom;
 */
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior normal:
        assumes -1 <= x <= 1;
        ensures 0 <= \result <= M_PI;
    behavior domain_error:
        assumes x < -1 || x > 1;
        ensures __FC_errno == EDOM;
        //ensures \is_NaN(\result);
    behavior acos_one:
        assumes x == 1;
        //ensure \eq_double(\result, +0);
    disjoint behaviors normal, domain_error;
 */
double acos(double x);

/*
  // Provided by frama-c: unusable because uses built-ins which are not supported.
  behavior normal:
    assumes \is_finite(x) && \abs(x) <= 1;
    assigns \result;
    ensures \is_finite(\result) && \result >= 0;
  behavior edom:
    assumes \is_infinite(x) || (\is_finite(x) && \abs(x) > 1);
    assigns __FC_errno;
    ensures __FC_errno == 1;
  disjoint behaviors normal, edom;
 */
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior normal:
        assumes -1 <= x <= 1;
        ensures 0 <= \result <= M_PI;
    behavior domain_error:
        assumes x < -1 || x > 1;
        ensures __FC_errno == EDOM;
        //ensures \is_NaN(\result);
    behavior acos_one:
        assumes x == 1;
        //ensure \eq_double(\result, +0);
    disjoint behaviors normal, domain_error;
 */
float acosf(float x);

// Not useful because long double not supported by frama-c
/*@
  behavior normal:
    assumes \is_finite(x) && \abs(x) <= 1;
    assigns \result;
    ensures \is_finite(\result) && \result >= 0;
  behavior edom:
    assumes \is_infinite(x) || (\is_finite(x) && \abs(x) > 1);
    assigns __FC_errno;
    ensures __FC_errno == 1;
  disjoint behaviors normal, edom;
 */
long double acosl(long double x);

/*
  // Provided by frama-c: unusable because uses built-ins which are not supported.
  behavior normal:
    assumes \is_finite(x) && \abs(x) <= 1;
    assigns \result;
    ensures \is_finite(\result);
  behavior edom:
    assumes \is_infinite(x) || (\is_finite(x) && \abs(x) > 1);
    assigns __FC_errno;
    ensures __FC_errno == 1;
  disjoint behaviors normal, edom;
 */
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior normal:
        assumes -1 <= x <= 1;
        ensures (-M_PI / 2.0) <= \result <= (M_PI / 2.0);
    behavior domain_error:
        assumes x < -1 || x > 1;
        ensures __FC_errno == EDOM;
        //ensures \is_NaN(\result);
    behavior asin_zero:
        assumes x == 0; // (+) or (-)
        ensures \result == 0; // (+) or (-)
    disjoint behaviors normal, domain_error;
 */
double asin(double x);

/*
  // Provided by frama-c: unusable because uses built-ins which are not supported.
  behavior normal:
    assumes \is_finite(x) && \abs(x) <= 1;
    assigns \result;
    ensures \is_finite(\result);
  behavior edom:
    assumes \is_infinite(x) || (\is_finite(x) && \abs(x) > 1);
    assigns __FC_errno;
    ensures __FC_errno == 1;
  disjoint behaviors normal, edom;
 */
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior normal:
        assumes -1 <= x <= 1;
        ensures (-M_PI / 2.0) <= \result <= (M_PI / 2.0);
    behavior domain_error:
        assumes x < -1 || x > 1;
        ensures __FC_errno == EDOM;
        //ensures \is_NaN(\result);
    behavior asin_zero:
        assumes x == 0; // (+) or (-)
        ensures \result == 0; // (+) or (-)
    disjoint behaviors normal, domain_error;
 */
float asinf(float x);

// Not useful because long double not supported by frama-c
/*@
  behavior normal:
    assumes \is_finite(x) && \abs(x) <= 1;
    assigns \result;
    ensures \is_finite(\result);
  behavior edom:
    assumes \is_infinite(x) || (\is_finite(x) && \abs(x) > 1);
    assigns __FC_errno;
    ensures __FC_errno == 1;
  disjoint behaviors normal, edom;
 */
long double asinl(long double x);

/*@
    assigns \result \from x;
    ensures (-M_PI / 2.0) <= \result <= (M_PI / 2.0);
    behavior atan_zero:
        assumes x == 0;
        ensures \result == 0; // (+) or (-)
    behavior infinite:
        assumes is_inf_float(x);
        ensures \result == (M_PI / 2.0) || \result == (-M_PI / 2.0);
    disjoint behaviors infinite, atan_zero;
 */
float atanf(float x);

/*@
    assigns \result \from x;
    ensures (-M_PI / 2.0) <= \result <= (M_PI / 2.0);
    behavior atan_zero:
        assumes x == 0;
        ensures \result == 0; // (+) or (-)
    behavior infinite:
        assumes is_inf_dbl(x);
        ensures \result == (M_PI / 2.0) || \result == (-M_PI / 2.0);
    disjoint behaviors infinite, atan_zero;
 */
double atan(double x);

// Not useful because long double not supported by frama-c
/*@
    assigns \result \from x;
 */
long double atanl(long double x);

/*@
    assigns \result \from x, y;
    assigns __FC_errno \from x, y;  // EDOM may occur for atan2(0,0)
    behavior normal:
        assumes y != 0 || x != 0;
        ensures -M_PI <= \result <= M_PI;
//    behavior zero_plus:
//        assumes y == 0 && \eq_double(+0, x);
//        ensures \result == 0; // (+) or (-)
//    behavior zero_minus:
//        assumes y == 0 && \eq_double(-0, x);
//        ensures \result == M_PI || \result == -M_PI;
    behavior zero_negative:
        assumes y == 0 && x < 0;
        ensures \result == M_PI || \result == -M_PI;
    behavior zero_positive:
        assumes y == 0 && x > 0;
        ensures \result == 0; // (+) or (-)
    behavior negative_zero:
        assumes y < 0 && x == 0;
        ensures \result == -M_PI/2;
    behavior positive_zero:
        assumes y > 0 && x == 0;
        ensures \result == M_PI/2;
    behavior positive_ninf:
        assumes is_finite_dbl(y) && y > 0;
        assumes is_negative_inf_dbl(x);
        ensures \result == M_PI || \result == -M_PI;
    behavior positive_pinf:
        assumes is_finite_dbl(y) && y > 0;
        assumes is_positive_inf_dbl(x);
        ensures \result == 0; // (+) or (-)
    behavior inf_finite:
        assumes is_positive_inf_dbl(y) || is_negative_inf_dbl(y);
        assumes is_finite_dbl(x);
        ensures \result == M_PI/2 || \result == -M_PI/2;
    behavior inf_ninf:
        assumes is_positive_inf_dbl(y) || is_negative_inf_dbl(y);
        assumes is_negative_inf_dbl(x);
        ensures \result == 3*M_PI/4 || \result == -3*M_PI/4;
    behavior inf_pinf:
        assumes is_positive_inf_dbl(y) || is_negative_inf_dbl(y);
        assumes is_positive_inf_dbl(x);
        ensures \result == M_PI/4 || \result == M_PI/4;
 */
double atan2(double y, double x);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;  // EDOM may occur for atan2(0,0)
    behavior normal:
        assumes y != 0 || x != 0;
        ensures -M_PI <= \result <= M_PI;
//    behavior zero_plus:
//        assumes y == 0 && \eq_double(+0, x);
//        ensures \result == 0; // (+) or (-)
//    behavior zero_minus:
//        assumes y == 0 && \eq_double(-0, x);
//        ensures \result == M_PI || \result == -M_PI;
    behavior zero_negative:
        assumes y == 0 && x < 0;
        ensures \result == M_PI || \result == -M_PI;
    behavior zero_positive:
        assumes y == 0 && x > 0;
        ensures \result == 0; // (+) or (-)
    behavior negative_zero:
        assumes y < 0 && x == 0;
        ensures \result == -M_PI/2;
    behavior positive_zero:
        assumes y > 0 && x == 0;
        ensures \result == M_PI/2;
    behavior positive_ninf:
        assumes is_finite_float(y) && y > 0;
        assumes is_negative_inf_float(x);
        ensures \result == M_PI || \result == -M_PI;
    behavior positive_pinf:
        assumes is_finite_float(y) && y > 0;
        assumes is_positive_inf_float(x);
        ensures \result == 0; // (+) or (-)
    behavior inf_finite:
        assumes is_positive_inf_float(y) || is_negative_inf_float(y);
        assumes is_finite_float(x);
        ensures \result == M_PI/2 || \result == -M_PI/2;
    behavior inf_ninf:
        assumes is_positive_inf_float(y) || is_negative_inf_float(y);
        assumes is_negative_inf_float(x);
        ensures \result == 3*M_PI/4 || \result == -3*M_PI/4;
    behavior inf_pinf:
        assumes is_positive_inf_float(y) || is_negative_inf_float(y);
        assumes is_positive_inf_float(x);
        ensures \result == M_PI/4 || \result == M_PI/4;
 */
float atan2f(float y, float x);

// Not useful because long double not supported by frama-c
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;  // EDOM may occur for atan2(0,0)
 */
long double atan2l(long double y, long double x);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior normal:
        assumes is_finite_dbl(x);
        ensures -1 <= \result <= 1;
    behavior zero:
        assumes x == 0; // (+) or (-)
        ensures \result == 1;
    behavior inf:
        assumes is_inf_dbl(x);
        ensures is_NaN_dbl(\result);
    disjoint behaviors normal, inf;
    disjoint behaviors zero, inf;
 */
double cos(double x);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior normal:
        assumes is_finite_float(x);
        ensures -1 <= \result <= 1;
    behavior zero:
        assumes x == 0; // (+) or (-)
        ensures \result == 1;
    behavior inf:
        assumes is_inf_float(x);
        ensures is_NaN_float(\result);
    disjoint behaviors normal, inf;
    disjoint behaviors zero, inf;
 */
float cosf(float x);

// Not useful because long double not supported by frama-c
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
 */
long double cosl(long double x);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior normal:
        assumes is_finite_dbl(x);
        ensures -1 <= \result <= 1;
    behavior zero:
        assumes x == 0; // (+) or (-)
        ensures \result == 0; // (+) or (-)
    behavior inf:
        assumes is_inf_dbl(x);
        ensures is_NaN_dbl(\result);
 */
double sin(double x);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior normal:
        assumes is_finite_float(x);
        ensures -1 <= \result <= 1;
    behavior zero:
        assumes x == 0; // (+) or (-)
        ensures \result == 0; // (+) or (-)
    behavior inf:
        assumes is_inf_float(x);
        ensures is_NaN_float(\result);
 */
float sinf(float x);

// Not useful because long double not supported by frama-c
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
 */
long double sinl(long double x);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior zero:
        assumes x == 0; // (+) or (-)
        ensures \result == 0; // (+) or (-)
    behavior inf:
        assumes is_inf_dbl(x);
        ensures is_NaN_dbl(\result);
    disjoint behaviors zero, inf;
 */
double tan(double x);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior zero:
        assumes x == 0; // (+) or (-)
        ensures \result == 0; // (+) or (-)
    behavior inf:
        assumes is_inf_float(x);
        ensures is_NaN_float(\result);
    disjoint behaviors zero, inf;
 */
float tanf(float x);

// Not useful because long double not supported by frama-c
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
 */
long double tanl(long double x);

/*
  // Provided by frama-c: unusable because uses built-ins which are not supported.
  behavior normal:
    assumes \is_finite(x) && x >= 1;
    assigns \result;
    ensures \is_finite(\result) && \result >= 0;
  behavior infinite:
    assumes \is_plus_infinity(x);
    assigns \result;
    ensures \is_plus_infinity(\result);
  behavior edom:
    assumes \is_minus_infinity(x) || (\is_finite(x) && x < 1);
    assigns __FC_errno;
    ensures __FC_errno == 1;
  disjoint behaviors normal, infinite, edom;
 */
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior normal:
        assumes is_finite_dbl(x);
        ensures is_finite_dbl(\result) && \result >= 0;
//    behavior one:
//        assumes x == 1;
//        ensures \eq_double(\result, +0);
    behavior plus_inf:
        assumes is_positive_inf_dbl(x);
        ensures is_positive_inf_dbl(\result);
    behavior domain_error:
        assumes x < 1 || is_negative_inf_dbl(x);
        ensures __FC_errno == EDOM;
        ensures is_NaN_dbl(\result);
    disjoint behaviors normal, plus_inf, domain_error;
 */
double acosh(double x);

/*
  // Provided by frama-c: unusable because uses built-ins which are not supported.
  behavior normal:
    assumes \is_finite(x) && x >= 1;
    assigns \result;
    ensures \is_finite(\result) && \result >= 0;
  behavior infinite:
    assumes \is_plus_infinity(x);
    assigns \result;
    ensures \is_plus_infinity(\result);
  behavior edom:
    assumes \is_minus_infinity(x) || (\is_finite(x) && x < 1);
    assigns __FC_errno;
    ensures __FC_errno == 1;
  disjoint behaviors normal, infinite, edom;
 */
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior normal:
        assumes is_finite_float(x);
        ensures is_finite_float(\result) && \result >= 0;
//    behavior one:
//        assumes x == 1;
//        ensures \eq_double(\result, +0);
    behavior plus_inf:
        assumes is_positive_inf_float(x);
        ensures is_positive_inf_float(\result);
    behavior domain_error:
        assumes x < 1 || is_negative_inf_float(x);
        ensures __FC_errno == EDOM;
        ensures is_NaN_float(\result);
    disjoint behaviors normal, plus_inf, domain_error;
 */
float acoshf(float x);

/*
  // Provided by frama-c: unusable because uses built-ins which are not supported.
  behavior normal:
    assumes \is_finite(x) && x >= 1;
    assigns \result;
    ensures \is_finite(\result) && \result >= 0;
  behavior infinite:
    assumes \is_plus_infinity(x);
    assigns \result;
    ensures \is_plus_infinity(\result);
  behavior edom:
    assumes \is_minus_infinity(x) || (\is_finite(x) && x < 1);
    assigns __FC_errno;
    ensures __FC_errno == 1;
  disjoint behaviors normal, infinite, edom;
 */
// Not useful because long double not supported by frama-c
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
 */
long double acoshl(long double x);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior zero:
        assumes x == 0; // (+) or (-)
        ensures \result == 0; // (+) or (-)
    behavior inf:
        assumes is_inf_dbl(x);
        ensures is_inf_dbl(\result);
    disjoint behaviors zero, inf;
 */
double asinh(double x);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    behavior zero:
        assumes x == 0; // (+) or (-)
        ensures \result == 0; // (+) or (-)
    behavior inf:
        assumes is_inf_dbl(x);
        ensures is_inf_dbl(\result);
    disjoint behaviors zero, inf;
 */
float asinhf(float x);

// Not useful because long double not supported by frama-c
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
 */
long double asinhl(long double x);

/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 0.0;

    behavior domain_error:
        assumes x < -1 || x > 1;
        ensures __FC_errno == EDOM;
        ensures is_NaN_dbl(\result);
    behavior div_zero:
        assumes x == 1 || x == -1;
        ensures is_inf_dbl(\result);
 @*/
double atanh(double x);

/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 0.0;

    behavior domain_error:
        assumes x < -1 || x > 1;
        ensures __FC_errno == EDOM;
        ensures is_NaN_float(\result);
    behavior div_zero:
        assumes x == 1 || x == -1;
        ensures is_inf_float(\result);
 @*/
float atanhf(float x);

// Not useful because long double not supported by frama-c
/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 0.0;
 @*/
long double atanhl(long double x);

/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 1.0;
 @*/
double cosh(double x);

/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 1.0;
 @*/
float coshf(float x);

// Not useful because long double not supported by frama-c
/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 1.0;
 @*/
long double coshl(long double x);

/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 0.0;
 @*/
double sinh(double x);

/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 0.0;
 @*/
float sinhf(float x);

// Not useful because long double not supported by frama-c
/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 0.0;
 @*/
long double sinhl(long double x);

/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 0.0;
 @*/
double tanh(double x);

/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 0.0;
 @*/
float tanhf(float x);

// Not useful because long double not supported by frama-c
/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 0.0;
 @*/
long double tanhl(long double x);

/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 1.0;
 @ ensures x == 1 ==> \result == M_E;
 @ ensures x == -1 ==> \result == 1.0/M_E;
 @*/
double exp(double x);

/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @ ensures x == 0 ==> \result == 1.0;
 @ ensures x == 1 ==> \result == M_E;
 @ ensures x == -1 ==> \result == 1.0/M_E;
 @*/
float expf(float x);

// Not useful because long double not supported by frama-c
/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 */
long double expl(long double x);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    ensures x == 0 ==> \result == 1.0;
    // exp2(-INF) = +0
    ensures is_positive_inf_dbl(x) ==> is_positive_inf_dbl(\result);
 */
double exp2(double x);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    ensures x == 0 ==> \result == 1.0;
    // exp2(-INF) = +0
    ensures is_positive_inf_float(x) ==> is_positive_inf_float(\result);
 */
float exp2f(float x);

// Not useful because long double not supported by frama-c
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
*/
long double exp2l(long double x);

/*@
    assigns \result, __FC_errno \from x;
    ensures x == 0 ==> \result == 0; // (+) or (-)
    ensures is_negative_inf_dbl(x) ==> \result == -1;
    ensures is_positive_inf_dbl(x) ==> is_positive_inf_dbl(\result);
 */
double expm1(double x);

/*@
    assigns \result, __FC_errno \from x;
    ensures x == 0 ==> \result == 0; // (+) or (-)
    ensures is_negative_inf_float(x) ==> \result == -1;
    ensures is_positive_inf_float(x) ==> is_positive_inf_float(\result);
 */
float expm1f(float x);

// Not useful because long double not supported by frama-c
/*@
    assigns \result, __FC_errno \from x;
*/
long double expm1l(long double x);

/*@
    requires !is_NaN_dbl(value);
    requires \valid(exp);
    assigns \result, *exp, __FC_errno;
    ensures (\result == 0) || (0.5 <= \result < 1);
//    ensures value == \result * \pow(2, *exp);
    ensures value == 0 ==> (\result == 0 && *exp == 0);
    ensures is_negative_inf_dbl(value) ==> \result == -1;
    ensures is_positive_inf_dbl(value) ==> is_positive_inf_dbl(\result);
 */
double frexp(double value, int *exp);

/*@
    requires !is_NaN_float(value);
    requires \valid(exp);
    assigns \result, *exp, __FC_errno;
    ensures (\result == 0) || (0.5 <= \result < 1);
//    ensures value == \result * \pow(2, *exp);
    ensures value == 0 ==> (\result == 0 && *exp == 0);
    ensures is_negative_inf_float(value) ==> \result == -1;
    ensures is_positive_inf_float(value) ==> is_positive_inf_float(\result);
 */
float frexpf(float value, int *exp);

// Not useful because long double not supported by frama-c
/*@
    assigns \result, *exp, __FC_errno;
*/
long double frexpl(long double value, int *exp);

/*@
    assigns \result, __FC_errno \from x;
    ensures x == 0 ==> \result == FP_ILOGB0;
    ensures is_inf_dbl(x) ==> \result == INT_MAX;
    ensures is_NaN_dbl(x) ==> \result == FP_ILOGBNAN;
*/
int ilogb(double x);

// Not useful because long double not supported by frama-c
/*@
    assigns \result, __FC_errno \from x;
    ensures x == 0 ==> \result == FP_ILOGB0;
    ensures is_inf_dbl(x) ==> \result == INT_MAX;
    ensures is_NaN_dbl(x) ==> \result == FP_ILOGBNAN;
*/
int ilogbf(float x);

/*@
    assigns \result, __FC_errno \from x;
*/
int ilogbl(long double x);

/*@
    assigns \result, __FC_errno \from x;
*/
double ldexp(double x, int exp);

/*@
    assigns \result, __FC_errno \from x;
*/
float ldexpf(float x, int exp);

// Not useful because long double not supported by frama-c
/*@
    assigns \result, __FC_errno \from x;
*/
long double ldexpl(long double x, int exp);

/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
   behavior normal:
     assumes x > 0;
     ensures x == 1.0 ==> \result == 0;
     ensures __FC_errno == \old(errno);
   behavior domain_error:
     assumes x < 0;
     ensures __FC_errno == EDOM;
   behavior range_error:
     assumes x == 0;
     ensures __FC_errno == ERANGE;
 */
double log(double x);

/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
   behavior normal:
     assumes x > 0;
     ensures x == 1.0 ==> \result == 0;
     ensures __FC_errno == \old(errno);
   behavior domain_error:
     assumes x < 0;
     ensures __FC_errno == EDOM;
   behavior range_error:
     assumes x == 0;
     ensures __FC_errno == ERANGE;
 */
float logf(float x);

// Not useful because long double not supported by frama-c
/*@
 @ assigns \result \from x;
 @ assigns __FC_errno \from x;
 @*/
long double logl(long double x);

/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
   ensures x == 1.0 ==> \result == 0;
   ensures x == 10.0 ==> \result == 1;
   behavior domain_error:
     assumes x < 0;
     ensures __FC_errno == EDOM;
   behavior range_error:
     assumes x == 0;
     ensures __FC_errno == ERANGE;
 */
double log10(double x);

/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
   ensures x == 1.0 ==> \result == 0;
   ensures x == 10.0 ==> \result == 1;
   behavior domain_error:
     assumes x < 0;
     ensures __FC_errno == EDOM;
   behavior range_error:
     assumes x == 0;
     ensures __FC_errno == ERANGE;
 */
float log10f(float x);

// Not useful because long double not supported by frama-c
/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
*/
long double log10l(long double x);

/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
   ensures x == 0 ==> \result == 0; // (+) or (-)
   ensures is_positive_inf_dbl(x) ==> is_positive_inf_dbl(\result);
   behavior domain_error:
     assumes x < -1;
     ensures __FC_errno == EDOM;
     ensures is_NaN_dbl(\result);
   behavior range_error:
     assumes x == -1;
     ensures __FC_errno == ERANGE;
     ensures is_negative_inf_dbl(\result);
 */
double log1p(double x);

/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
   ensures x == 0 ==> \result == 0; // (+) or (-)
   ensures is_positive_inf_float(x) ==> is_positive_inf_float(\result);
   behavior domain_error:
     assumes x < -1;
     ensures __FC_errno == EDOM;
     ensures is_NaN_float(\result);
   behavior range_error:
     assumes x == -1;
     ensures __FC_errno == ERANGE;
     ensures is_negative_inf_float(\result);
 */
float log1pf(float x);

// Not useful because long double not supported by frama-c
/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
*/
long double log1pl(long double x);

/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
   ensures x == 0 ==> is_negative_inf_dbl(\result);
   //ensure \eq_double(\result, +0);
   ensures x == 1 ==> \result == 0; // Weaker form of above
   ensures is_positive_inf_dbl(x) ==> is_positive_inf_dbl(\result);
   behavior domain_error:
     assumes x < 0;
     ensures __FC_errno == EDOM;
     ensures is_NaN_dbl(\result);
   behavior range_error:
     assumes x == 0;
     ensures __FC_errno == ERANGE;
 */
double log2(double x);

/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
   ensures x == 0 ==> is_negative_inf_float(\result);
   //ensure \eq_double(\result, +0);
   ensures x == 1 ==> \result == 0; // Weaker form of above
   ensures is_positive_inf_float(x) ==> is_positive_inf_float(\result);
   behavior domain_error:
     assumes x < 0;
     ensures __FC_errno == EDOM;
     ensures is_NaN_float(\result);
   behavior range_error:
     assumes x == 0;
     ensures __FC_errno == ERANGE;
 */
float log2f(float x);

// Not useful because long double not supported by frama-c
/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
*/
long double log2l(long double x);

/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
   behavior zero:
     assumes x == 0;    // (+) or (-)
     ensures is_negative_inf_dbl(\result);
     ensures __FC_errno == EDOM || __FC_errno == ERANGE;
   behavior inf:
     assumes is_inf_dbl(x);
     ensures is_positive_inf_dbl(\result);
 */
double logb(double x);

/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
   behavior zero:
     assumes x == 0;    // (+) or (-)
     ensures is_negative_inf_float(\result);
     ensures __FC_errno == EDOM || __FC_errno == ERANGE;
   behavior inf:
     assumes is_inf_float(x);
     ensures is_positive_inf_float(\result);
 */
float logbf(float x);

// Not useful because long double not supported by frama-c
/*@
   assigns \result \from x;
   assigns __FC_errno \from x;
*/
long double logbl(long double x);

/*@
    assigns \result \from value;
    assigns *iptr \from value;
    assigns __FC_errno \from value;
    behavior inf:
        assumes is_inf_dbl(value);
        ensures \result == 0;
        ensures is_inf_dbl(*iptr);
    behavior nan:
        assumes is_NaN_dbl(value);
        ensures is_NaN_dbl(\result);
        ensures is_NaN_dbl(*iptr);
*/
double modf(double value, double *iptr);

/*@
    assigns \result \from value;
    assigns *iptr \from value;
    assigns __FC_errno \from value;
    behavior inf:
        assumes is_inf_float(value);
        ensures \result == 0;
        ensures is_inf_float(*iptr);
    behavior nan:
        assumes is_NaN_float(value);
        ensures is_NaN_float(\result);
        ensures is_NaN_float(*iptr);
*/
float modff(float value, float *iptr);

// Not useful because long double not supported by frama-c
/*@
    assigns \result \from value;
    assigns *iptr \from value;
    assigns __FC_errno \from value;
*/
long double modfl(long double value, long double *iptr);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    ensures x == 0 ==> \result == 0; // (+) or (-)
    ensures n == 0 ==> \result == x;
    ensures is_inf_dbl(x) ==> is_inf_dbl(\result);
*/
double scalbn(double x, int n);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    ensures x == 0 ==> \result == 0; // (+) or (-)
    ensures n == 0 ==> \result == x;
    ensures is_inf_float(x) ==> is_inf_float(\result);
*/
float scalbnf(float x, int n);

// Not useful because long double not supported by frama-c
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
*/
long double scalbnl(long double x, int n);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    ensures x == 0 ==> \result == 0; // (+) or (-)
    ensures n == 0 ==> \result == x;
    ensures is_inf_dbl(x) ==> is_inf_dbl(\result);
*/
double scalbln(double x, long int n);

/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
    ensures x == 0 ==> \result == 0; // (+) or (-)
    ensures n == 0 ==> \result == x;
    ensures is_inf_float(x) ==> is_inf_float(\result);
*/
float scalblnf(float x, long int n);

// Not useful because long double not supported by frama-c
/*@
    assigns \result \from x;
    assigns __FC_errno \from x;
*/
long double scalblnl(long double x, long int n);

/*@
assigns \result, errno \from x;
behavior inf:
    assumes is_inf_dbl(x);
    ensures \result == x;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(x);
behavior zero:
    assumes x == 0.0;
    ensures \result == 0.0;
behavior one:
    assumes x == 1.0;
    ensures \result == 1.0;
*/
double cbrt(double x);

/*@
assigns \result, errno \from x;
behavior inf:
    assumes is_inf_float(x);
    ensures \result == x;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(x);
behavior zero:
    assumes x == 0.0;
    ensures \result == 0.0;
behavior one:
    assumes x == 1.0;
    ensures \result == 1.0;
*/
float cbrtf(float x);

/*@
assigns \result, errno \from x;
*/
long double cbrtl(long double x);

/*@
assigns \result, errno \from x;
behavior inf:
    assumes is_inf_dbl(x);
    ensures is_positive_inf_dbl(\result);
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(x);
behavior g_zero:
    assumes x > 0.0;
    ensures \result == x;
behavior l_zero:
    assumes x < 0.0;
    ensures \result == -x;
behavior zero:
    assumes x == 0.0;
    ensures \result == 0.0;
*/
double fabs(double x);

/*@
assigns \result, errno \from x;
behavior inf:
    assumes is_inf_float(x);
    ensures is_positive_inf_float(\result);
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior g_zero:
    assumes x > 0.0;
    ensures \result == x;
behavior l_zero:
    assumes x < 0.0;
    ensures \result == -x;
behavior zero:
    assumes x == 0.0;
    ensures \result == 0.0;
*/
float fabsf(float x);

/*@
assigns \result, errno \from x;
*/
long double fabsl(long double x);

/*@
assigns \result, errno \from x, y;
behavior inf:
    assumes is_inf_dbl(x) || is_inf_dbl(y);
    ensures is_positive_inf_dbl(\result);
behavior nan:
    assumes (is_NaN_dbl(x) || is_NaN_dbl(y)) && !(is_inf_dbl(x) || is_inf_dbl(y));
    ensures is_NaN_dbl(\result);
behavior normal:
    assumes is_finite_dbl(x) && is_finite_dbl(y);
    ensures \result >= 0.0;
*/
double hypot(double x, double y);

/*@
assigns \result, errno \from x, y;
behavior inf:
    assumes is_inf_float(x) || is_inf_float(y);
    ensures is_positive_inf_float(\result);
behavior nan:
    assumes (is_NaN_float(x) || is_NaN_float(y)) && !(is_inf_float(x) || is_inf_float(y));
    ensures is_NaN_float(\result);
behavior normal:
    assumes is_finite_float(x) && is_finite_float(y);
    ensures \result >= 0.0;
*/
float hypotf(float x, float y);

/*@
assigns \result, errno \from x, y;
*/
long double hypotl(long double x, long double y);

/*@
assigns \result, errno \from x, y;
behavior frac_neg:
    assumes x < 0.0 && ((int)y) != y;
    ensures errno == EDOM;
behavior neg_zero:
    assumes y < 0.0 && x == 0.0;
    ensures \result == HUGE_VAL;
behavior nan:
    assumes (is_NaN_dbl(x) || is_NaN_dbl(y)) && x != 1.0 && y != 0.0;
    ensures is_NaN_dbl(\result);
behavior one:
    assumes x == 1.0;
    ensures \result == 1.0;
behavior zero:
    assumes y == 0.0;
    ensures \result == 1.0;
behavior none_inf:
    assumes x == -1.0 && is_inf_dbl(y);
    ensures \result == 1.0;
behavior abs_one_ninf:
    assumes -1.0 < x < 1.0 && is_negative_inf_dbl(y);
    ensures is_positive_inf_dbl(\result);
behavior nabs_one_ninf:
    assumes (x < -1.0 || x > 1.0) && is_negative_inf_dbl(y);
    ensures \result == 0.0;
behavior abs_one_inf:
    assumes -1.0 < x < 1.0 && is_positive_inf_dbl(y);
    ensures \result == 0.0;
behavior nabs_one_inf:
    assumes (x < -1.0 || x > 1.0) && is_positive_inf_dbl(y);
    ensures is_positive_inf_dbl(\result);
behavior inf_less_zero:
    assumes is_positive_inf_dbl(x) && y < 0;
    ensures \result == 0.0;
behavior inf_greater_zero:
    assumes is_positive_inf_dbl(x) && y > 0;
    ensures is_positive_inf_dbl(\result);
*/
double pow(double x, double y);

/*@
assigns \result, errno \from x, y;
behavior frac_neg:
    assumes x < 0.0 && ((int)y) != y;
    ensures errno == EDOM;
behavior neg_zero:
    assumes y < 0.0 && x == 0.0;
    ensures \result == HUGE_VAL;
behavior nan:
    assumes (is_NaN_float(x) || is_NaN_float(y)) && x != 1.0 && y != 0.0;
    ensures is_NaN_float(\result);
behavior one:
    assumes x == 1.0;
    ensures \result == 1.0;
behavior zero:
    assumes y == 0.0;
    ensures \result == 1.0;
behavior none_inf:
    assumes x == -1.0 && is_inf_float(y);
    ensures \result == 1.0;
behavior abs_one_ninf:
    assumes -1.0 < x < 1.0 && is_negative_inf_float(y);
    ensures is_positive_inf_float(\result);
behavior nabs_one_ninf:
    assumes (x < -1.0 || x > 1.0) && is_negative_inf_float(y);
    ensures \result == 0.0;
behavior abs_one_inf:
    assumes -1.0 < x < 1.0 && is_positive_inf_float(y);
    ensures \result == 0.0;
behavior nabs_one_inf:
    assumes (x < -1.0 || x > 1.0) && is_positive_inf_float(y);
    ensures is_positive_inf_float(\result);
behavior inf_less_zero:
    assumes is_positive_inf_float(x) && y < 0;
    ensures \result == 0.0;
behavior inf_greater_zero:
    assumes is_positive_inf_float(x) && y > 0;
    ensures is_positive_inf_float(\result);
*/
float powf(float x, float y);

/*@
assigns \result, errno \from x, y;
*/
long double powl(long double x, long double y);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(\result);
behavior zero_inf:
    assumes x == 0.0 || is_positive_inf_dbl(x);
    ensures \result == x;
behavior neg:
    assumes x < 0.0;
    ensures errno == EDOM;
behavior normal:
    assumes is_finite_dbl(x) && x >= 0.0;
    ensures 0.0 <= \result <= x;
*/
double sqrt(double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior zero_inf:
    assumes x == 0.0 || is_positive_inf_float(x);
    ensures \result == x;
behavior neg:
    assumes x < 0.0;
    ensures errno == EDOM;
behavior normal:
    assumes is_finite_float(x) && x >= 0.0;
    ensures 0.0 <= \result <= x;
*/
float sqrtf(float x);

/*@
assigns \result, errno \from x;
*/
long double sqrtl(long double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(\result);
behavior inf:
    assumes is_positive_inf_dbl(x);
    ensures \result == 1.0;
behavior ninf:
    assumes is_negative_inf_dbl(x);
    ensures \result == -1.0;
behavior zero:
    assumes x == 0.0;
    ensures \result == x;
*/
double erf(double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior inf:
    assumes is_positive_inf_float(x);
    ensures \result == 1.0;
behavior ninf:
    assumes is_negative_inf_float(x);
    ensures \result == -1.0;
behavior zero:
    assumes x == 0.0;
    ensures \result == x;
*/
float erff(float x);

/*@
assigns \result, errno \from x;
*/
long double erfl(long double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(\result);
behavior inf:
    assumes is_positive_inf_dbl(x);
    ensures \result == 0.0;
behavior ninf:
    assumes is_negative_inf_dbl(x);
    ensures \result == 2.0;
behavior zero:
    assumes x == 0.0;
    ensures \result == 1.0;
*/
double erfc(double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior inf:
    assumes is_positive_inf_float(x);
    ensures \result == 0.0;
behavior ninf:
    assumes is_negative_inf_float(x);
    ensures \result == 2.0;
behavior zero:
    assumes x == 0.0;
    ensures \result == 1.0;
*/
float erfcf(float x);

/*@
assigns \result, errno \from x;
*/
long double erfcl(long double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(\result);
behavior inf:
    assumes is_inf_dbl(x);
    ensures is_positive_inf_dbl(\result);
behavior small:
    assumes x == 1.0 || x == 2.0;
    ensures \result == 0.0;
behavior neg:
    assumes x < 0.0;
    ensures errno == ERANGE;
    ensures \result == HUGE_VAL;
*/
double lgamma(double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior inf:
    assumes is_inf_float(x);
    ensures is_positive_inf_float(\result);
behavior small:
    assumes x == 1.0 || x == 2.0;
    ensures \result == 0.0;
behavior neg:
    assumes x < 0.0;
    ensures errno == ERANGE;
    ensures \result == HUGE_VALF;
*/
float lgammaf(float x);

/*@
assigns \result, errno \from x;
*/
long double lgammal(long double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(\result);
behavior inf:
    assumes is_positive_inf_dbl(x);
    ensures \result == x;
behavior ninf:
    assumes is_negative_inf_dbl(x);
    ensures is_NaN_dbl(\result);
    ensures errno == EDOM;
behavior zero:
    assumes x == 0.0;
    ensures \result == HUGE_VAL;
*/
double tgamma(double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior inf:
    assumes is_positive_inf_float(x);
    ensures \result == x;
behavior ninf:
    assumes is_negative_inf_float(x);
    ensures is_NaN_float(\result);
    ensures errno == EDOM;
behavior zero:
    assumes x == 0.0;
    ensures \result == HUGE_VALF;
*/
float tgammaf(float x);

/*@
assigns \result, errno \from x;
*/
long double tgammal(long double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(\result);
behavior zero_inf:
    assumes x == 0 || is_inf_dbl(x);
    ensures \result == x;
behavior normal:
    assumes is_finite_dbl(x);
    ensures \result >= x;
    ensures \result < 0 <==> x < 0;
*/
double ceil(double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior zero_inf:
    assumes x == 0 || is_inf_float(x);
    ensures \result == x;
behavior normal:
    assumes is_finite_float(x);
    ensures \result >= x;
    ensures \result < 0 <==> x < 0;
*/
float ceilf(float x);

/*@
assigns \result, errno \from x;
*/
long double ceill(long double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(\result);
behavior zero_inf:
    assumes x == 0 || is_inf_dbl(x);
    ensures \result == x;
behavior normal:
    assumes is_finite_dbl(x);
    ensures \result <= x;
    ensures \result < 0 <==> x < 0;
*/
double floor(double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior zero_inf:
    assumes x == 0 || is_inf_float(x);
    ensures \result == x;
behavior normal:
    assumes is_finite_float(x);
    ensures \result <= x;
    ensures \result < 0 <==> x < 0;
*/
float floorf(float x);

/*@
assigns \result, errno \from x;
*/
long double floorl(long double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(\result);
behavior zero_inf:
    assumes x == 0 || is_inf_dbl(x);
    ensures \result == x;
behavior normal:
    assumes is_finite_dbl(x);
    ensures \result < 0 <==> x < 0;
*/
double nearbyint(double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior zero_inf:
    assumes x == 0 || is_inf_float(x);
    ensures \result == x;
behavior normal:
    assumes is_finite_float(x);
    ensures \result < 0 <==> x < 0;
*/
float nearbyintf(float x);

/*@
assigns \result, errno \from x;
*/
long double nearbyintl(long double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(\result);
behavior zero_inf:
    assumes x == 0 || is_inf_dbl(x);
    ensures \result == x;
behavior normal:
    assumes is_finite_dbl(x);
    ensures \result < 0 <==> x < 0;
*/
double rint(double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior zero_inf:
    assumes x == 0 || is_inf_float(x);
    ensures \result == x;
behavior normal:
    assumes is_finite_float(x);
    ensures \result < 0 <==> x < 0;
*/
float rintf(float x);

/*@
assigns \result, errno \from x;
*/
long double rintl(long double x);

/*@
assigns \result, errno \from x;
*/
long int lrint(double x);

/*@
assigns \result, errno \from x;
*/
long int lrintf(float x);

/*@
assigns \result, errno \from x;
*/
long int lrintl(long double x);

/*@
assigns \result, errno \from x;
*/
long long int llrint(double x);

/*@
assigns \result, errno \from x;
*/
long long int llrintf(float x);

/*@
assigns \result, errno \from x;
*/
long long int llrintl(long double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(\result);
behavior zero_inf:
    assumes x == 0 || is_inf_dbl(x);
    ensures \result == x;
behavior normal:
    assumes is_finite_dbl(x);
    ensures \result < 0 <==> x < 0;
*/
double round(double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior zero_inf:
    assumes x == 0 || is_inf_float(x);
    ensures \result == x;
behavior normal:
    assumes is_finite_float(x);
    ensures \result < 0 <==> x < 0;
*/
float roundf(float x);

/*@
assigns \result, errno \from x;
*/
long double roundl(long double x);

/*@
assigns \result, errno \from x;
*/
long int lround(double x);

/*@
assigns \result, errno \from x;
*/
long int lroundf(float x);

/*@
assigns \result, errno \from x;
*/
long int lroundl(long double x);

/*@
assigns \result, errno \from x;
*/
long long int llround(double x);

/*@
assigns \result, errno \from x;
*/
long long int llroundf(float x);

/*@
assigns \result, errno \from x;
*/
long long int llroundl(long double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(\result);
behavior zero_inf:
    assumes x == 0 || is_inf_dbl(x);
    ensures \result == x;
behavior normal:
    assumes is_finite_dbl(x);
    ensures \result <= x;
    ensures \result < 0 <==> x < 0;
*/
double trunc(double x);

/*@
assigns \result, errno \from x;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior zero_inf:
    assumes x == 0 || is_inf_float(x);
    ensures \result == x;
behavior normal:
    assumes is_finite_float(x);
    ensures \result <= x;
    ensures \result < 0 <==> x < 0;
*/
float truncf(float x);

/*@
assigns \result, errno \from x;
*/
long double truncl(long double x);

/*@
assigns \result, errno \from x, y;
behavior nan:
    assumes is_NaN_dbl(x) || is_NaN_dbl(y);
    ensures is_NaN_dbl(\result);
behavior y_zero:
    assumes y == 0.0;
    ensures errno == EDOM;
    ensures is_NaN_dbl(\result);
behavior x_inf:
    assumes is_inf_dbl(x);
    ensures errno == EDOM;
    ensures is_NaN_dbl(\result);
behavior zero_nzero:
    assumes x == 0.0 && y != 0.0;
    ensures \result == 0.0;
    ensures errno == \old(errno);
behavior ninf_inf:
    assumes is_finite_dbl(x) && is_inf_dbl(y);
    ensures \result == x;
    ensures errno == \old(errno);
*/
double fmod(double x, double y);

/*@
assigns \result, errno \from x, y;
behavior nan:
    assumes is_NaN_float(x) || is_NaN_float(y);
    ensures is_NaN_float(\result);
behavior y_zero:
    assumes y == 0.0;
    ensures errno == EDOM;
    ensures is_NaN_float(\result);
behavior x_inf:
    assumes is_inf_float(x);
    ensures errno == EDOM;
    ensures is_NaN_float(\result);
behavior zero_nzero:
    assumes x == 0.0 && y != 0.0;
    ensures \result == 0.0;
    ensures errno == \old(errno);
behavior ninf_inf:
    assumes is_finite_float(x) && is_inf_float(y);
    ensures \result == x;
    ensures errno == \old(errno);
*/
float fmodf(float x, float y);

/*@
assigns \result, errno \from x;
*/
long double fmodl(long double x, long double y);

/*@
assigns \result, errno \from x, y;
behavior nan:
    assumes is_NaN_dbl(x) || is_NaN_dbl(y);
    ensures is_NaN_dbl(\result);
behavior edom:
    assumes (y == 0.0 && !is_NaN_dbl(x)) || (is_inf_dbl(x) && !is_NaN_dbl(y));
    ensures errno == EDOM;
    ensures is_NaN_dbl(\result);
*/
double remainder(double x, double y);

/*@
assigns \result, errno \from x, y;
behavior nan:
    assumes is_NaN_float(x) || is_NaN_float(y);
    ensures is_NaN_float(\result);
behavior edom:
    assumes (y == 0.0 && !is_NaN_float(x)) || (is_inf_float(x) && !is_NaN_float(y));
    ensures errno == EDOM;
    ensures is_NaN_float(\result);
*/
float remainderf(float x, float y);

/*@
assigns \result, errno \from x, y;
*/
long double remainderl(long double x, long double y);

/*@
requires \valid(quo);
assigns \result, *quo, errno \from x, y;
behavior nan:
    assumes is_NaN_dbl(x) || is_NaN_dbl(y);
    ensures is_NaN_dbl(\result);
behavior edom:
    assumes (y == 0.0 && !is_NaN_dbl(x)) || (x == 0.0 && !is_NaN_dbl(y));
    ensures errno == EDOM;
    ensures is_NaN_dbl(\result);
*/
double remquo(double x, double y, int *quo);

/*@
requires \valid(quo);
assigns \result, *quo, errno \from x, y;
behavior nan:
    assumes is_NaN_float(x) || is_NaN_float(y);
    ensures is_NaN_float(\result);
behavior edom:
    assumes (y == 0.0 && !is_NaN_float(x)) || (x == 0.0 && !is_NaN_float(y));
    ensures errno == EDOM;
    ensures is_NaN_float(\result);
*/
float remquof(float x, float y, int *quo);

/*@
assigns \result, *quo, errno \from x, y;
*/
long double remquol(long double x, long double y, int *quo);

//@ logic boolean signBit(double y) = y < 0.0 || y == -0.0; // FIXME - 0 and NaN also have signbits
//@ logic boolean signBitf(float y) = y < 0.0 || y == -0.0; // FIXME - 0 and NaN also have signbits
//@ logic boolean signBitl(long double y) = y < 0; // FIXME

/*@
    ensures \abs(\result) == \abs(x);
    ensures signBit(y) <==> signBit(\result);
    assigns \result \from x,y;
*/
double copysign(double x, double y);
/*@
    ensures \abs(\result) == \abs(x);
    ensures signBitf(y) <==> signBitf(\result);
    assigns \result \from x,y;
*/
float copysignf(float x, float y);
/*@
    ensures \abs(\result) == \abs(x);
    ensures signBitl(y) <==> signBitl(\result);
    assigns \result \from x,y;
*/
long double copysignl(long double x, long double y);

/*@
  requires valid_read_string_or_null(tagp) || tagp == \null;
  assigns \result;
//  ensures \is_NaN(\result);
  ensures is_NaN_dbl(\result);
 */
double nan(const char *tagp);

/*@
  requires valid_read_string_or_null(tagp);
  assigns \result;
  ensures is_NaN_float(\result);
 */
float nanf(const char *tagp);

/*@
  requires valid_read_string_or_null(tagp);
  assigns \result;
  ensures \is_NaN(\result);
 */
long double nanl(const char *tagp);

/*@
assigns \result, errno \from x, y;
behavior nan:
    assumes is_NaN_dbl(x) || is_NaN_dbl(y);
    ensures is_NaN_dbl(\result);
*/
double nextafter(double x, double y);

/*@
assigns \result, errno \from x, y;
behavior nan:
    assumes is_NaN_float(x) || is_NaN_float(y);
    ensures is_NaN_float(\result);
*/
float nextafterf(float x, float y);

/*@
assigns \result, errno \from x, y;
*/
long double nextafterl(long double x, long double y);

/*@
assigns \result, errno \from x, y;
*/
double nexttoward(double x, long double y);

/*@
assigns \result, errno \from x, y;
*/
float nexttowardf(float x, long double y);

/*@
assigns \result, errno \from x, y;
*/
long double nexttowardl(long double x, long double y);

/*@
    assigns \result \from x, y;
    assigns __FC_errno \from x, y;
    behavior positive:
        assumes x > y;
        ensures \result == x - y;
    behavior zero:
        assumes x <= y;
        ensures \result == 0; // +0
*/
double fdim(double x, double y);

/*@
    assigns \result \from x, y;
    assigns __FC_errno \from x, y;
    behavior positive:
        assumes x > y;
        ensures \result == x - y;
    behavior zero:
        assumes x <= y;
        ensures \result == 0; // +0
*/
float fdimf(float x, float y);

// Not useful because long double not supported by frama-c
/*@
    assigns \result \from x, y;
    assigns __FC_errno \from x, y;
*/
long double fdiml(long double x, long double y);

/*@
    assigns \result \from x, y;
    assigns __FC_errno \from x, y;
    behavior NaN:
        assumes is_NaN_dbl(x) && is_NaN_dbl(y);
        ensures is_NaN_dbl(y);
    behavior is_x:
        assumes x >= y || is_NaN_dbl(y);
        ensures \result == x;
    behavior is_y:
        assumes y >= x || is_NaN_dbl(x);
        ensures \result == y;
*/
double fmax(double x, double y);

/*@
    assigns \result \from x, y;
    assigns __FC_errno \from x, y;
    behavior NaN:
        assumes is_NaN_float(x) && is_NaN_float(y);
        ensures is_NaN_float(y);
    behavior is_x:
        assumes x >= y || is_NaN_float(y);
        ensures \result == x;
    behavior is_y:
        assumes y >= x || is_NaN_float(x);
        ensures \result == y;
*/
float fmaxf(float x, float y);

/*@
assigns \result, errno \from x, y;
*/
long double fmaxl(long double x, long double y);

/*@
assigns \result \from x, y;
assigns errno \from x, y;
behavior NaN:
    assumes is_NaN_dbl(x) && is_NaN_dbl(y);
    ensures is_NaN_dbl(y);
behavior is_x:
    assumes x <= y || is_NaN_dbl(y);
    ensures \result == x;
behavior is_y:
    assumes y <= x || is_NaN_dbl(x);
    ensures \result == y;
*/
double fmin(double x, double y);

/*@
assigns \result \from x, y;
assigns errno \from x, y;
behavior NaN:
    assumes is_NaN_float(x) && is_NaN_float(y);
    ensures is_NaN_float(y);
behavior is_x:
    assumes x <= y || is_NaN_float(y);
    ensures \result == x;
behavior is_y:
    assumes y <= x || is_NaN_float(x);
    ensures \result == y;
*/
float fminf(float x, float y);

/*@
assigns \result, errno \from x, y;
*/
long double fminl(long double x, long double y);

/*@
assigns \result, errno \from x, y, z;
ensures \result == (x * y) + z;
*/
double fma(double x, double y, double z);

/*@
assigns \result, errno \from x, y, z;
ensures \result == (x * y) + z;
*/
float fmaf(float x, float y, float z);

/*@
assigns \result, errno \from x, y, z;
ensures \result == (x * y) + z;
*/
long double fmal(long double x, long double y, long double z);

/* POSIX */

/*@
assigns \result, __FC_errno \from x;
*/
double j0(double x);

/*@
assigns \result, __FC_errno \from x;
*/
double j1(double x);

/*@
assigns \result, __FC_errno \from x, n;
*/
double jn(int n, double x);

/*@
assigns \result, __FC_errno \from x;
ensures x < 0.0 ==> (is_NaN_dbl(\result) || \result == -HUGE_VAL);
ensures x == 0.0 ==> \result == -HUGE_VAL;
*/
double y0(double x);

/*@
assigns \result, __FC_errno \from x;
ensures x < 0.0 ==> (is_NaN_dbl(\result) || \result == -HUGE_VAL);
ensures x == 0.0 ==> \result == -HUGE_VAL;
*/
double y1(double x);

/*@
assigns \result, __FC_errno \from x, n;
ensures x < 0.0 ==> (is_NaN_dbl(\result) || \result == -HUGE_VAL);
ensures x == 0.0 ==> \result == -HUGE_VAL;
*/
double yn(int n, double x);

/* GNU Extensions */

/*@
requires \valid(sinx);
requires \valid(cosx);
assigns errno, *sinx, *cosx \from x;
ensures !is_NaN_dbl(*sinx) ==> -1 <= *sinx <= 1;
ensures !is_NaN_dbl(*cosx) ==> -1 <= *cosx <= 1;
*/
void sincos(double x, double *sinx, double *cosx);

/*@
requires \valid(sinx);
requires \valid(cosx);
assigns errno, *sinx, *cosx \from x;
ensures !is_NaN_float(*sinx) ==> -1 <= *sinx <= 1;
ensures !is_NaN_float(*cosx) ==> -1 <= *cosx <= 1;
*/
void sincosf(float x, float *sinx, float *cosx);

/*@
requires \valid(sinx);
requires \valid(cosx);
assigns errno, *sinx, *cosx \from x;
*/
void sincosl(long double x, long double *sinx, long double *cosx);

/*@
requires \valid(signp);
assigns *signp, \result, errno \from x, *signp;
behavior nan:
    assumes is_NaN_dbl(x);
    ensures is_NaN_dbl(\result);
behavior inf:
    assumes is_inf_dbl(x);
    ensures is_positive_inf_dbl(\result);
behavior small:
    assumes x == 1.0 || x == 2.0;
    ensures \result == 0.0;
behavior neg:
    assumes x < 0.0;
    ensures errno == ERANGE;
    ensures \result == HUGE_VAL;
*/
double lgamma_r(double x, int *signp);

/*@
requires \valid(signp);
assigns *signp, \result, errno \from x, *signp;
behavior nan:
    assumes is_NaN_float(x);
    ensures is_NaN_float(\result);
behavior inf:
    assumes is_inf_float(x);
    ensures is_positive_inf_float(\result);
behavior small:
    assumes x == 1.0 || x == 2.0;
    ensures \result == 0.0;
behavior neg:
    assumes x < 0.0;
    ensures errno == ERANGE;
    ensures \result == HUGE_VALF;
*/
float lgammaf_r(float x, int *signp);

/*@
requires \valid(signp);
assigns *signp, \result, errno \from x, *signp;
*/
long double lgammal_r(long double x, int *signp);

/*@
assigns errno, \result \from x;
ensures !is_NaN_dbl(x) ==> 1 <= \result < 2;
*/
double significand(double x);

/*@
assigns errno, \result \from x;
ensures !is_NaN_float(x) ==> 1 <= \result < 2;
*/
float significandf(float x);

/*@
assigns errno, \result \from x;
*/
long double significandl(long double x);

/*@
assigns \result \from x;
ensures is_finite_dbl(x) ==> \result != 0;
ensures is_inf_dbl(x) || is_NaN_dbl(x) ==> \result == 0;
*/
int finite(double x);

/*@
assigns \result \from x;
ensures is_finite_float(x) ==> \result != 0;
ensures is_inf_float(x) || is_NaN_float(x) ==> \result == 0;
*/
int finitef(float x);

/*@
assigns \result \from x;
*/
int finitel(long double x);

/*@
assigns \result \from x;
ensures is_positive_inf_dbl(x) ==> \result == 1;
ensures is_negative_inf_dbl(x) ==> \result == -1;
ensures is_finite_dbl(x) || is_NaN_dbl(x) ==> \result == 0;
*/
int isinf(double x);

/*@
assigns \result \from x;
ensures is_positive_inf_float(x) ==> \result == 1;
ensures is_negative_inf_float(x) ==> \result == -1;
ensures is_finite_float(x) || is_NaN_float(x) ==> \result == 0;
*/
int isinff(float x);

/*@
assigns \result \from x;
*/
int isinfl(long double x);

/*@
assigns \result \from x;
ensures is_NaN_dbl(x) ==> \result != 0;
ensures is_inf_dbl(x) || is_finite_dbl(x) ==> \result == 0;
*/
int isnan(double x);

/*@
assigns \result \from x;
ensures is_NaN_float(x) ==> \result != 0;
ensures is_inf_float(x) || is_finite_float(x) ==> \result == 0;
*/
int isnanf(float x);

/*@
assigns \result \from x;
*/
int isnanl(long double x);

/*@
assigns errno, \result \from error;
ensures error == ERANGE ==> \result == HUGE_VAL && errno == ERANGE;
ensures error == -ERANGE ==> \result == -HUGE_VAL && errno == ERANGE;
ensures error != ERANGE && error != -ERANGE ==> is_NaN_dbl(\result) && errno == EDOM;
*/
double infnan(int error);

__END_DECLS

#endif
