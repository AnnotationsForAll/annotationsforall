#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    fmaxl(4.6L,1.1L);
    fmaxl(0.1L,3.4L);
    fmaxl(9.9L,2.1L);
    fmaxl(anylongdouble(),anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result,result2;
    long double x,y;
    
    x = anylongdouble();
    y = anylongdouble();
    result = fmaxl(x,y);
    //@ assert (x > y) ==> (result == x) && (x < y) ==> (result == y);
    
    x = anylongdouble();
    result = fmaxl(x,x);
    //@ assert result == x;
    
    x = anylongdouble();
    y = anylongdouble();
    result = fmaxl(x,y);
    result2 = fmaxl(y,x);
    //@ assert result == result2;
    
    //x = anylongdouble();
    //y = anylongdouble();
    //result = fmaxl(x,y);
    // assert result == \max(x, y);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
