#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    cosl(0.0L);
    cosl(1.0L);
    cosl(-1.0L);
    cosl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    result = cosl(0.0L);
    //@ assert -1 <= result <= 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}