#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    cosh(0.0);
    cosh(1.0);
    cosh(-1.0);
    cosh(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = cosh(0.0);
    //@ assert result == 1.0;
    result = cosh(2.5);
    // assert result == \cosh(2.5);
    //result = cosh(DBL_MAX);
    // assert result == HUGE_VAL;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
