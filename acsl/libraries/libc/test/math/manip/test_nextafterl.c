#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    nextafterl(1.3L,6.5L);
    nextafterl(1.0L,-3.0L);
    nextafterl(4.5L,4.5L);
    nextafterl(anylongdouble(),anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    long double x,y;
    
    nextafterl(anylongdouble(),anylongdouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
