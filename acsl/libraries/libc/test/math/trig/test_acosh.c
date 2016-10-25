#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

//@ ensures \result < 1.0;
extern double outrange();
//@ ensures \result >= 1.0;
extern double inrange();

void runSuccess() {
    acosh(1.0);
    acosh(0.0);
    acosh(-1.0);
    acosh(2.0);
    acosh(-2.0);
    acosh(inrange());
    acosh(outrange());
    acosh(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = acosh(0.5);
    // assert \cosh(result) == 0.5;
    
    result = acosh(2.0);
    //@ assert result >= 0;
    errno = 0;
    
    result = acosh(outrange());
    //@ assert (math_errhandling & MATH_ERRNO) ==> (errno == EDOM);
    errno = 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
