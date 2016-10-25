#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    nexttowardl(1.3L,6.5L);
    nexttowardl(1.0L,-3.0L);
    nexttowardl(4.5L,4.5L);
    nexttowardl(anylongdouble(),anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    long double x,y;
    
    x = anylongdouble();
    result = nexttowardl(x,(long double)x);
    //@ assert result == x;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}