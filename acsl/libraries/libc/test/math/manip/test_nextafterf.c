#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    nextafterf(1.3f,6.5f);
    nextafterf(1.0f,-3.0f);
    nextafterf(4.5f,4.5f);
    nextafterf(anyfloat(),anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    float x,y;
    
    nextafterf(anyfloat(),anyfloat());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
