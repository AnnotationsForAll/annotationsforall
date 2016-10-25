#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    ceill(1.0L);
    ceill(0.0L);
    ceill(43.56L);
    ceill(-2.5L);
    ceill(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    ceill(anylongdouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
