#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    exp2f(0.0f);
    exp2f(1.0f);
    exp2f(-1.0f);
//    exp2f(NAN);
    exp2f(INFINITY);
    exp2f(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = exp2f(2.0f);
    // assert result == \pow(2, 2.0);
    result = exp2f(1.0f);
    // assert result == 2;

//    result = exp2f(0.0f);
    // assert result == 1;

//    result = exp2f(-1.0f);
    // assert result == 0.5f;

    //result = exp2f(FLT_MAX);
    // assert result == HUGE_VALF;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
