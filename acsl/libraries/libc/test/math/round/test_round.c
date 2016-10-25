#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    round(1.0);
    round(0.0);
    round(43.56);
    round(-2.5);
    round(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    round(anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
