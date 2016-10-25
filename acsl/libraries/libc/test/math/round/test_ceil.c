#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    ceil(1.0);
    ceil(0.0);
    ceil(43.56);
    ceil(-2.5);
    ceil(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    ceil(anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
