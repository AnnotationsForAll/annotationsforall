#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < -1.0 || \result > 1.0;
extern double outrange();
//@ ensures -1.0 <= \result <= 1.0;
extern double inrange();

void runSuccess() {
    acos(1.0);
    acos(0.0);
    acos(-1.0);
    acos(2.0);
    acos(-2.0);
    acos(inrange());
    acos(outrange());
    acos(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = acos(0.5);
    // assert \cos(result) == 0.5;
    
    result = acos(2.0);
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = acos(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    result = acos(inrange());
    //@ assert 0 <= result <= M_PI;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}