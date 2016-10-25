/*
 * values.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_VALUES_H_
#define LIBC_VALUES_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "limits.h"
#include "float.h"

#define BITSPERBYTE CHAR_BIT

#define _TYPEBITS(type) (sizeof (type) * CHAR_BIT)

#define CHARBITS   _TYPEBITS (char)
#define SHORTBITS  _TYPEBITS (short int)
#define INTBITS    _TYPEBITS (int)
#define LONGBITS   _TYPEBITS (long int)
#define PTRBITS    _TYPEBITS (char *)
#define DOUBLEBITS _TYPEBITS (double)
#define FLOATBITS  _TYPEBITS (float)

#define MINSHORT SHRT_MIN
#define MININT   INT_MIN
#define MINLONG  LONG_MIN

#define MAXSHORT SHRT_MAX
#define MAXINT   INT_MAX
#define MAXLONG  LONG_MAX

#define HIBITS MINSHORT
#define HIBITL MINLONG

#define MAXDOUBLE DBL_MAX
#define MAXFLOAT  FLT_MAX
#define MINDOUBLE DBL_MIN
#define MINFLOAT  FLT_MIN
#define DMINEXP   DBL_MIN_EXP
#define FMINEXP   FLT_MIN_EXP
#define DMAXEXP   DBL_MAX_EXP
#define FMAXEXP   FLT_MAX_EXP

#endif /* LIBC_VALUES_H_ */
