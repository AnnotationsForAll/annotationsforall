#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    sinf(0.0f);
    sinf(1.0f);
    sinf(-1.0f);
    sinf(anyfloat());
//    sinf(NAN);
    sinf(INFINITY);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    result = sinf(0.0f);
    //@ assert -1 <= result <= 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
