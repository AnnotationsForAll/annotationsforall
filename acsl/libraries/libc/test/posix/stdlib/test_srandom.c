#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    srandom(anyuint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long result;
    
    srandom(anyuint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
