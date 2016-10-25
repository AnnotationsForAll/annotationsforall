#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    erf(0.0);
    erf(1.0);
    erf(-1.0);
    erf(56.5);
    erf(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    erf(0.0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
