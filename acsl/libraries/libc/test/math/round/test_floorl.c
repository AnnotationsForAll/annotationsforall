#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    floorl(1.0L);
    floorl(0.0L);
    floorl(43.56L);
    floorl(-2.5L);
    floorl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    floorl(anylongdouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
