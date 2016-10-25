#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    truncf(1.0f);
    truncf(0.0f);
    truncf(43.56f);
    truncf(-2.5f);
    truncf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    truncf(1.0f);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
