#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    random();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long result;
    
    result = random();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
