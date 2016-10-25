#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    floor(1.0);
    floor(0.0);
    floor(43.56);
    floor(-2.5);
    floor(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    floor(anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
