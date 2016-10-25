#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    jn(5, 0.0);
    jn(32, 43.0);
    jn(-2, 1.2);
    jn(anyint(), anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    jn(anyint(), anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
