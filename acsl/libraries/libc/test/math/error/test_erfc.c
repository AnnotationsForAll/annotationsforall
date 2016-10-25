#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    erfc(0.0);
    erfc(1.0);
    erfc(-1.0);
    erfc(56.5);
    erfc(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    erfc(anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
