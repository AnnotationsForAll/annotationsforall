#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    hypot(1.0, 1.0);
    hypot(1.0, 0.0);
    hypot(8.3, 5.0);
    hypot(0.0, 121.1);
    hypot(anydouble(), anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    double x,y;
    
    hypot(anydouble(), anydouble());
    
    //x = anydouble();
    //y = anydouble();
    //result = hypot(x,y);
    // assert result == \sqrt(\pow(x,2)+\pow(y,2));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
