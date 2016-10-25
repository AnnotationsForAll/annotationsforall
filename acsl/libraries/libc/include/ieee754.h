/*
 * ieee754.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_IEEE754_H_
#define LIBC_IEEE754_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "endian.h"

/*
 This header describes the IEEE 754 floating-point format, so on systems that use this format,
 programmers can simply decompose floats and doubles into the structs provided, instead of using <float.h> to make guesses.

 TODO: This should probably be machdep-dependent, because not all systems need to use IEEE 754 as their floating-point format.

 Frama-C will probably have problems proving if you use this header.
 For instance, putting a double in a union, changing the bitfields, and taking it out will render the value unknowable by Frama-C.
 Type invariants could address this issue, but currently, they are not implemented. TODO: add type invariants, as described above.
 */

#define IEEE754_FLOAT_BIAS       0x7f
#define IEEE754_DOUBLE_BIAS      0x3ff
#define IEEE854_LONG_DOUBLE_BIAS 0x3fff

union ieee754_float {
    float f;
    struct {
#if BYTE_ORDER == BIG_ENDIAN
        unsigned int negative:1;
        unsigned int exponent:8;
        unsigned int mantissa:23;
#else
        unsigned int mantissa :23;
        unsigned int exponent :8;
        unsigned int negative :1;
#endif
    } ieee;
    struct {
#if BYTE_ORDER == BIG_ENDIAN
        unsigned int negative:1;
        unsigned int exponent:8;
        unsigned int quiet_nan:1;
        unsigned int mantissa:22;
#else
        unsigned int mantissa :22;
        unsigned int quiet_nan :1;
        unsigned int exponent :8;
        unsigned int negative :1;
#endif
    } ieee_nan;
};

union ieee754_double {
    double d;
    struct {
#if BYTE_ORDER == BIG_ENDIAN
        unsigned int negative:1;
        unsigned int exponent:11;
        unsigned int mantissa0:20;
        unsigned int mantissa1:32;
#else
# if FLOAT_WORD_ORDER == BIG_ENDIAN
        unsigned int mantissa0:20;
        unsigned int exponent:11;
        unsigned int negative:1;
        unsigned int mantissa1:32;
# else
        unsigned int mantissa1 :32;
        unsigned int mantissa0 :20;
        unsigned int exponent :11;
        unsigned int negative :1;
# endif
#endif
    } ieee;
    struct {
#if BYTE_ORDER == BIG_ENDIAN
        unsigned int negative:1;
        unsigned int exponent:11;
        unsigned int quiet_nan:1;
        unsigned int mantissa0:19;
        unsigned int mantissa1:32;
#else
# if FLOAT_WORD_ORDER == BIG_ENDIAN
        unsigned int mantissa0:19;
        unsigned int quiet_nan:1;
        unsigned int exponent:11;
        unsigned int negative:1;
        unsigned int mantissa1:32;
# else
        unsigned int mantissa1 :32;
        unsigned int mantissa0 :19;
        unsigned int quiet_nan :1;
        unsigned int exponent :11;
        unsigned int negative :1;
# endif
#endif
    } ieee_nan;
};

union ieee854_long_double {
    long double d;
    struct {
#if BYTE_ORDER == BIG_ENDIAN
        unsigned int negative:1;
        unsigned int exponent:15;
        unsigned int empty:16;
        unsigned int mantissa0:32;
        unsigned int mantissa1:32;
#else
# if FLOAT_WORD_ORDER == BIG_ENDIAN
        unsigned int exponent:15;
        unsigned int negative:1;
        unsigned int empty:16;
        unsigned int mantissa0:32;
        unsigned int mantissa1:32;
# else
        unsigned int mantissa1 :32;
        unsigned int mantissa0 :32;
        unsigned int exponent :15;
        unsigned int negative :1;
        unsigned int empty :16;
# endif
#endif
    } ieee;
    struct {
#if BYTE_ORDER == BIG_ENDIAN
        unsigned int negative:1;
        unsigned int exponent:15;
        unsigned int empty:16;
        unsigned int one:1;
        unsigned int quiet_nan:1;
        unsigned int mantissa0:30;
        unsigned int mantissa1:32;
#else
# if FLOAT_WORD_ORDER == BIG_ENDIAN
        unsigned int exponent:15;
        unsigned int negative:1;
        unsigned int empty:16;
        unsigned int mantissa0:30;
        unsigned int quiet_nan:1;
        unsigned int one:1;
        unsigned int mantissa1:32;
# else
        unsigned int mantissa1 :32;
        unsigned int mantissa0 :30;
        unsigned int quiet_nan :1;
        unsigned int one :1;
        unsigned int exponent :15;
        unsigned int negative :1;
        unsigned int empty :16;
# endif
#endif
    } ieee_nan;
};

#endif /* LIBC_IEEE754_H_ */
