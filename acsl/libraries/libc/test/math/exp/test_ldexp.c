#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    ldexp(1.0, 1);
    ldexp(0.0, 0);
    ldexp(-1.0, -1);
    ldexp(anydouble(), 1);
    ldexp(1.0, anyint());
    ldexp(anydouble(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    ldexp(anydouble(), anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
