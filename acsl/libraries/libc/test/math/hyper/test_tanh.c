#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    tanh(0.0);
    tanh(1.0);
    tanh(-1.0);
    tanh(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}