#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    nearbyint(1.0);
    nearbyint(0.0);
    nearbyint(43.56);
    nearbyint(-2.5);
    nearbyint(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    nearbyint(1.0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
