#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    lrand48();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long result;
    
    result = lrand48();
    //@ assert 0 <= result < 2147483648;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
