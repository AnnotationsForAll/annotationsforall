#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    rintf(1.0f);
    rintf(0.0f);
    rintf(43.56f);
    rintf(-2.5f);
    rintf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    rintf(1.0f);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
