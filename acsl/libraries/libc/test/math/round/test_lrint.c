#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    lrint(1.0);
    lrint(0.0);
    lrint(43.56);
    lrint(-2.5);
    lrint(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long int result;
    
    lrint(1.0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
