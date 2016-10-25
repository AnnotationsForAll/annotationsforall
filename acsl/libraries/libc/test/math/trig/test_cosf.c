#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    cosf(0.0f);
    cosf(1.0f);
    cosf(-1.0f);
    cosf(anyfloat());
//    cosf(NAN);
    cosf(INFINITY);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    result = cosf(0.0f);
    //@ assert -1 <= result <= 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
