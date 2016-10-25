#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    tanhf(0.0f);
    tanhf(1.0f);
    tanhf(-1.0f);
    tanhf(anyfloat());
//    tanhf(NAN);
    tanhf(INFINITY);
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
