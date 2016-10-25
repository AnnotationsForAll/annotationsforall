#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    sqrtl(1.0L);
    sqrtl(0.0L);
    sqrtl(-1.0L);
    sqrtl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    sqrtl(anylongdouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
