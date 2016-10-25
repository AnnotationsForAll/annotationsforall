#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    expm1(0.0);
    expm1(1.0);
    expm1(-1.0);
    expm1(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = expm1(2.0);
    // assert result == \pow(M_E, 2.0) - 1;
    result = expm1(1.0);
    // assert result == M_E - 1;
//    result = expm1(0.0);
    // assert result == 1;
//    result = expm1(-1.0);
    // assert result == 1 / M_E - 1;
//    result = expm1(DBL_MAX);
    // assert result == HUGE_VAL;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
