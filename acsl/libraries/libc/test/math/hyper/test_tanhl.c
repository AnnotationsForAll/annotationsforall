#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    tanhl(0.0L);
    tanhl(1.0L);
    tanhl(-1.0L);
    tanhl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}