#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    fma(1.0,2.0,3.0);
    fma(5.6,7.5,6.8);
    fma(anydouble(),anydouble(),anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    double x,y,z;
    
    result = fma(1.0,2.0,3.0);
    //@ assert result == 5.0;
    
    x = anydouble();
    y = anydouble();
    z = anydouble();
    result = fma(x,y,z);
    //@ assert result == (x*y)+z;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
