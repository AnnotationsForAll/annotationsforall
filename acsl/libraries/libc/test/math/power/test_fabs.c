#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    fabs(1.0);
    fabs(0.0);
    fabs(-1.0);
    fabs(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    fabs(anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
