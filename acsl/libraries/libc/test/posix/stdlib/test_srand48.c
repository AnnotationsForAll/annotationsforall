#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    srand48(anylong());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    srand48(anylong());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
