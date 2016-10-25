#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    j0(0.0);
    j0(43.0);
    j0(1.2);
    j0(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    j0(anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
