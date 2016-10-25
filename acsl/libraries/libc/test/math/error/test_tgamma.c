#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    tgamma(0.0);
    tgamma(1.0);
    tgamma(-1.0);
    tgamma(56.5);
    tgamma(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    tgamma(0.0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
