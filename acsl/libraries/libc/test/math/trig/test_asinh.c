#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

void runSuccess() {
    asinh(1.0);
    asinh(0.0);
    asinh(-1.0);
    asinh(2.0);
    asinh(-2.0);
    asinh(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = asinh(2.0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
