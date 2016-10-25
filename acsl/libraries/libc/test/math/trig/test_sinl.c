#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    sinl(0.0L);
    sinl(1.0L);
    sinl(-1.0L);
    sinl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    result = sinl(0.0L);
    //@ assert -1 <= result <= 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}