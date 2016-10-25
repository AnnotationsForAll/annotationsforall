#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

void runSuccess() {
    atan(1.0);
    atan(0.0);
    atan(-1.0);
    atan(2.0);
    atan(-2.0);
    atan(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    //result = atan(0.5);
    // assert \tan(result) == 0.5;
    
    result = atan(anydouble());
    //@ assert -M_PI/2.0 <= result <= M_PI/2.0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}