#include "../../../test_common.h"
#include <math.h>
#include <limits.h>

void runSuccess() {
    logb(1.0);
    logb(-1.0);
    logb(0.1);
    logb(-0.1);
    logb(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = logb(1.0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
