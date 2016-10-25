#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    remainder(0.1,4.0);
    remainder(1.2,0.0);
    remainder(2.0,4.3);
    remainder(anydouble(),anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    remainder(0.1,4.0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
