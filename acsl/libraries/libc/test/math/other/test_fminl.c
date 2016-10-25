#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    fminl(4.6L,1.1L);
    fminl(0.1L,3.4L);
    fminl(9.9L,2.1L);
    fminl(anylongdouble(),anylongdouble());
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
    result = fminl(x,y);
    //@ assert (x < y) ==> (result == x) && (x > y) ==> (result == y);
    
    x = anylongdouble();
    result = fminl(x,x);
    //@ assert result == x;
    
    x = anylongdouble();
    y = anylongdouble();
    result = fminl(x,y);
    result2 = fminl(y,x);
    //@ assert result == result2;
    
    //x = anylongdouble();
    //y = anylongdouble();
    //result = fminl(x,y);
    // assert result == \min(x, y);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
