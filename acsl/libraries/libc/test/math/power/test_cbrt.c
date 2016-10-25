#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    cbrt(1.0);
    cbrt(0.0);
    cbrt(-1.0);
    cbrt(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    cbrt(anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
