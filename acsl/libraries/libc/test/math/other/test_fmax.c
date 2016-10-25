#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    fmax(4.6,1.1);
    fmax(0.1,3.4);
    fmax(9.9,2.1);
    fmax(anydouble(),anydouble());
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
    result = fmax(x,y);
    //@ assert (x > y) ==> (result == x) && (x < y) ==> (result == y);
    
    x = anydouble();
    result = fmax(x,x);
    //@ assert result == x;
    
    x = anydouble();
    y = anydouble();
    result = fmax(x,y);
    result2 = fmax(y,x);
    //@ assert x >= y ==> (result == x && result2 == x);
    //@ assert x <= y ==> (result == y && result2 == y);
    //@ assert result == result2;
    
    //x = anydouble();
    //y = anydouble();
    //result = fmax(x,y);
    // assert result == \max(x, y);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
