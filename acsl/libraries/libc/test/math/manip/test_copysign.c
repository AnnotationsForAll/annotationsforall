#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    copysign(1.0,-4.5);
    copysign(-1.0,4.5);
    copysign(6.0,3.7);
    copysign(anydouble(),anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    double x,y;
    
    x = 100;
    y = -200;
    result = copysign(x,y);
    //@ assert result < 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
