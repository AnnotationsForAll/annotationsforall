#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    erfl(0.0L);
    erfl(1.0L);
    erfl(-1.0L);
    erfl(56.5L);
    erfl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    erfl(0.0L);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
