#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    coshf(0.0f);
    coshf(1.0f);
    coshf(-1.0f);
    coshf(anyfloat());
//    coshf(NAN);
    coshf(INFINITY);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    result = coshf(0.0f);
    //@ assert result == 1.0;
    result = coshf(2.5f);
    // assert result == \cosh(2.5);
    //result = coshf(FLT_MAX);
    // assert result == HUGE_VALF;
    // assert (math_errhandling & MATH_ERRNO) ==> (errno == ERANGE);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
