#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    truncl(1.0L);
    truncl(0.0L);
    truncl(43.56L);
    truncl(-2.5L);
    truncl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    truncl(1.0L);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
