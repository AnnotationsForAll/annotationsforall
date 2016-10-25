#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    ceilf(1.0f);
    ceilf(0.0f);
    ceilf(43.56f);
    ceilf(-2.5f);
    ceilf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    ceilf(anyfloat());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
