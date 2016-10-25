#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    remainderf(0.1f,4.0f);
    remainderf(1.2f,0.0f);
    remainderf(2.0f,4.3f);
    remainderf(anyfloat(),anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    remainderf(0.1f,4.0f);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
