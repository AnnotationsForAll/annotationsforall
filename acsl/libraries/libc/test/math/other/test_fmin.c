#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    fmin(4.6,1.1);
    fmin(0.1,3.4);
    fmin(9.9,2.1);
    fmin(anydouble(),anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result,result2;
    double x,y;
    
    x = anydouble();
    y = anydouble();
    result = fmin(x,y);
    //@ assert (x < y) ==> (result == x) && (x > y) ==> (result == y);
    
    x = anydouble();
    result = fmin(x,x);
    //@ assert result == x;
    
    x = anydouble();
    y = anydouble();
    result = fmin(x,y);
    result2 = fmin(y,x);
    //@ assert result == result2;
    
    //x = anydouble();
    //y = anydouble();
    //result = fmin(x,y);
    // assert result == \min(x, y);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
