#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    llround(1.0);
    llround(0.0);
    llround(43.56);
    llround(-2.5);
    llround(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long long int result;
    
    llround(anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
