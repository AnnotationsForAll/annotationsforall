#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    int p;
    lgamma_r(0.0, &p);
    lgamma_r(1.0, &p);
    lgamma_r(-1.0, &p);
    lgamma_r(56.5, &p);
    lgamma_r(anydouble(), &p);
}

void runFailure() {
    lgamma_r(anydouble(), NULL);
}

int f;
void testValues() {
    f = 2;
    double result;
    
    int p;
    lgamma_r(anydouble(), &p);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
