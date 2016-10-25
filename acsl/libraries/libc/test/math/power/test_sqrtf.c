#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    sqrtf(1.0f);
    sqrtf(0.0f);
    sqrtf(-1.0f);
    sqrtf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    sqrtf(anyfloat());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
