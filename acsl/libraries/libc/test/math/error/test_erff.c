#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    erff(0.0f);
    erff(1.0f);
    erff(-1.0f);
    erff(56.5f);
    erff(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    erff(0.0f);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
