#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    powf(5.0f,6.0f);
    powf(1.2f,6.7f);
    powf(0.0f,2.0f);
    powf(4.45f,0.0f);
    powf(anyfloat(),anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    powf(anyfloat(),anyfloat());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
