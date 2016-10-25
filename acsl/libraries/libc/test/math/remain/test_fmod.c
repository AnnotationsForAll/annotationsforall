#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    fmod(0.1,4.0);
    fmod(1.2,0.0);
    fmod(2.0,4.3);
    fmod(anydouble(),anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    fmod(0.1,4.0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
