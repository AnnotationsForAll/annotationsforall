#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    lgamma(0.0);
    lgamma(1.0);
    lgamma(-1.0);
    lgamma(56.5);
    lgamma(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    lgamma(anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
