#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

void runSuccess() {
    asinhf(1.0);
    asinhf(0.0);
    asinhf(-1.0);
    asinhf(2.0);
    asinhf(-2.0);
    asinhf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    result = asinhf(2.0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
