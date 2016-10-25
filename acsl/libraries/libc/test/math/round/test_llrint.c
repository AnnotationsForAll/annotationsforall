#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    llrint(1.0);
    llrint(0.0);
    llrint(43.56);
    llrint(-2.5);
    llrint(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long long int result;
    
    llrint(1.0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
