#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    nextafter(1.3,6.5);
    nextafter(1.0,-3.0);
    nextafter(4.5,4.5);
    nextafter(anydouble(),anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    double x,y;
    
    nextafter(anydouble(),anydouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
