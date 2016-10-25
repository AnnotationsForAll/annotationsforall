#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    tan(0.0);
    tan(1.0);
    tan(-1.0);
    tan(anydouble());
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