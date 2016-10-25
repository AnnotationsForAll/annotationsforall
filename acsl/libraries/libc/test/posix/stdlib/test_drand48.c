#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    drand48();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = drand48();
    //@ assert 0 <= result < 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
