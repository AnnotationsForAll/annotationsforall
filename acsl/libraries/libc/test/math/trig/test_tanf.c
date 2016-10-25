#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    tanf(0.0f);
    tanf(1.0f);
    tanf(-1.0f);
    tanf(anyfloat());
//    tanf(NAN);
    tanf(INFINITY);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
