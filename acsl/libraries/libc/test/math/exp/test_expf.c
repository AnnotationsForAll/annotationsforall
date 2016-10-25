#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    expf(0.0f);
    expf(1.0f);
    expf(-1.0f);
//    expf(NAN);
    expf(INFINITY);
    expf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = expf(2.0f);
    // assert result == \pow(M_E, 2.0);
    result = expf(1.0f);
    //@ assert result == M_E;
    result = expf(0.0f);
    //@ assert result == 1;
    result = expf(-1.0f);
    //@ assert result == 1 / M_E;
    //result = expf(FLT_MAX);
    // assert result == HUGE_VALF;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
