#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < 1.0;
extern long double outrange();
//@ ensures \result >= 1.0;
extern long double inrange();

void runSuccess() {
    acoshl(1.0L);
    acoshl(0.0L);
    acoshl(-1.0L);
    acoshl(2.0L);
    acoshl(-2.0L);
    acoshl(inrange());
    acoshl(outrange());
    acoshl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = acoshl(0.5L);
    // assert \coshl(result) == 0.5;
    
    result = acoshl(2.0L);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = acoshl(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = acoshl(inrange());
    //@ assert result >= 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}