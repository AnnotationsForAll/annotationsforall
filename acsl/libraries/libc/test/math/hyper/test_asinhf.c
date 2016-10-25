#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

void runSuccess() {
    asinhf(1.0f);
    asinhf(0.0f);
    asinhf(-1.0f);
    asinhf(2.0f);
    asinhf(-2.0f);
//    asinhf(NAN);
    asinhf(INFINITY);
    asinhf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = asinhf(0.5f);
    // assert \sinhf(result) == 0.5;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
