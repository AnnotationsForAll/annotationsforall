#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    exp(0.0);
    exp(1.0);
    exp(-1.0);
    exp(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = exp(2.0);
    // assert result == \pow(M_E, 2.0);
    result = exp(1.0);
    //@ assert result == M_E;
    result = exp(0.0);
    //@ assert result == 1;
    result = exp(-1.0);
    //@ assert result == 1 / M_E;
    //result = exp(DBL_MAX);
    // assert result == HUGE_VAL;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
