#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    lround(1.0);
    lround(0.0);
    lround(43.56);
    lround(-2.5);
    lround(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long int result;
    
    lround(anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
