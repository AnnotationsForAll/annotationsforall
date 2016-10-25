#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    j1(0.0);
    j1(43.0);
    j1(1.2);
    j1(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    j1(anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
