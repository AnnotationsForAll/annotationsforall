#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    fabsl(1.0L);
    fabsl(0.0L);
    fabsl(-1.0L);
    fabsl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    fabsl(anylongdouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
