#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    sqrt(1.0);
    sqrt(0.0);
    sqrt(-1.0);
    sqrt(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    sqrt(anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
