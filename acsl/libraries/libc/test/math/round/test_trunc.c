#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    trunc(1.0);
    trunc(0.0);
    trunc(43.56);
    trunc(-2.5);
    trunc(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    trunc(1.0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
