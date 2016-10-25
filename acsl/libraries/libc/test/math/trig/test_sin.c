#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    sin(0.0);
    sin(1.0);
    sin(-1.0);
    sin(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = sin(0.0);
    //@ assert -1 <= result <= 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}