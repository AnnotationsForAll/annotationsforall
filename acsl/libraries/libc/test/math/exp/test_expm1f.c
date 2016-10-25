#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    expm1f(0.0f);
    expm1f(1.0f);
    expm1f(-1.0f);
//    expm1f(NAN);
    expm1f(INFINITY);
    expm1f(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = expm1f(2.0f);
    // assert result == \pow(M_E, 2.0) - 1;
    result = expm1f(1.0f);
    // assert result == M_E - 1;
//    result = expm1f(0.0f);
    // assert result == 1;
//    result = expm1f(-1.0f);
    // assert result == 1 / M_E - 1;
//    result = expm1f(FLT_MAX);
    // assert result == HUGE_VALF;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
