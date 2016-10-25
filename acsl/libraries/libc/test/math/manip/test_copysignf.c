#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    copysignf(1.0f,-4.5f);
    copysignf(-1.0f,4.5f);
    copysignf(6.0f,3.7f);
    copysignf(anyfloat(),anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    float x,y;
    
    x = 100;
    y = -200;
    result = copysign(x,y);
    //@ assert result < 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
