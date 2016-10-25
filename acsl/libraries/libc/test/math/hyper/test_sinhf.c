#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    sinhf(0.0f);
    sinhf(1.0f);
    sinhf(-1.0f);
    sinhf(anyfloat());
//    sinhf(NAN);
    sinhf(INFINITY);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    result = sinhf(0.0f);
    //@ assert result == 0.0;
    result = sinhf(2.5f);
    // assert result == \sinh(2.5);
    //result = sinhf(FLT_MAX);
    // assert result == HUGE_VALF;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
