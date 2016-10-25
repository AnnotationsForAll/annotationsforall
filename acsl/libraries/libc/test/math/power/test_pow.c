#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    pow(5.0,6.0);
    pow(1.2,6.7);
    pow(0.0,2.0);
    pow(4.45,0.0);
    pow(anydouble(),anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    pow(anydouble(),anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
