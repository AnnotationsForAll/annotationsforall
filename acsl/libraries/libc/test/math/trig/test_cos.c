#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    cos(0.0);
    cos(1.0);
    cos(-1.0);
    cos(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = cos(0.0);
    //@ assert -1 <= result <= 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}