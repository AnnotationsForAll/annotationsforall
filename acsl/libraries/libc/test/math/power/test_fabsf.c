#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    fabsf(1.0f);
    fabsf(0.0f);
    fabsf(-1.0f);
    fabsf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    fabsf(anyfloat());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
