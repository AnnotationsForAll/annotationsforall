#include "../../../test_common.h"
#include <math.h>
#include <limits.h>

void runSuccess() {
    logb(1.0L);
    logb(-1.0L);
    logb(0.1L);
    logb(-0.1L);
    logb(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    result = logb(1.0L);
    //@ assert result == 0;
    result = logb(111.0L);
    //@ assert result == 6;
    result = logb(0.01L);
    //@ assert result == -7;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}