#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    mrand48();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long result;
    
    result = mrand48();
    //@ assert -2147483648 <= result < 2147483648;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
