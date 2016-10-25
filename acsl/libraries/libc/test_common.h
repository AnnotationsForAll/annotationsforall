/*
 * This file contains some useful helper functions for all ACSL test files.
 */

#ifndef __TEST_COMMON
#define __TEST_COMMON

#include <__fc_string_axiomatic.h>
#include <stddef.h>

#ifndef M_PI //M_PI is not a C standard constant, but some headers have it already
#define M_PI 3.14159265358979323846
#endif

#ifndef M_E
#define M_E 2.7182818284590452354
#endif

//@ assigns \result;
extern int anyint();
//@ assigns \result;
extern long int anylong();
//@ assigns \result;
extern long long int anylonglong();
//@ assigns \result;
extern float anyfloat();
//@ assigns \result;
extern double anydouble();
//@ assigns \result;
extern long double anylongdouble();
//@ assigns \result;
extern unsigned int anyuint();
//@ assigns \result;
extern unsigned long int anyulong();
//@ assigns \result;
extern unsigned long long int anyulonglong();
//@ assigns \result;
extern size_t anysize();
//@ assigns \result; ensures valid_string(\result); ensures \result != \null;
extern char* anystring();

#include "extra_axioms.h"

#endif
