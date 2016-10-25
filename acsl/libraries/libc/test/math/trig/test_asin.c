#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < -1.0 || \result > 1.0;
extern double outrange();
//@ ensures -1.0 <= \result <= 1.0;
extern double inrange();

void runSuccess() {
    asin(1.0);
    asin(0.0);
    asin(-1.0);
    asin(2.0);
    asin(-2.0);
    asin(inrange());
    asin(outrange());
    asin(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = asin(0.5);
    // assert \sin(result) == 0.5;
    
    result = asin(2.0);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = asin(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = asin(inrange());
    //@ assert -M_PI/2.0 <= result <= M_PI/2.0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}