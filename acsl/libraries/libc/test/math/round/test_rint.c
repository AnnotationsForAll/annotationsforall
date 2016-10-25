#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    rint(1.0);
    rint(0.0);
    rint(43.56);
    rint(-2.5);
    rint(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    rint(1.0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
