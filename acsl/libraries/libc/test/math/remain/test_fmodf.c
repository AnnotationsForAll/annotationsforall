#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    fmodf(0.1f,4.0f);
    fmodf(1.2f,0.0f);
    fmodf(2.0f,4.3f);
    fmodf(anyfloat(),anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    fmodf(0.1f,4.0f);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
