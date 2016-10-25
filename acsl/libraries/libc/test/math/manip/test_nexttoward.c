#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    nexttoward(1.3,6.5L);
    nexttoward(1.0,-3.0L);
    nexttoward(4.5,4.5L);
    nexttoward(anydouble(),anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    double x,y;
    
    x = anydouble();
    result = nexttoward(x,(long double)x);
    //@ assert result == x;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}