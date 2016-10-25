#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    exp2(0.0);
    exp2(1.0);
    exp2(-1.0);
    exp2(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = exp2(2.0);
    // assert result == \pow(2, 2.0);
    result = exp2(1.0);
    // assert result == 2;

    //result = exp2(0.0);
    // assert result == 1;

    //result = exp2(-1.0);
    // assert result == 0.5;

    //result = exp2(DBL_MAX);
    // assert result == HUGE_VAL;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
