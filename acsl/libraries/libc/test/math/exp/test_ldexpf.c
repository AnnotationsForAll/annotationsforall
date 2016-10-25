#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    ldexpf(1.0f, 1);
    ldexpf(0.0f, 0);
    ldexpf(-1.0f, -1);
    ldexpf(anyfloat(), 1);
    ldexpf(1.0f, anyint());
    ldexpf(anyfloat(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    ldexp(anydouble(), anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
