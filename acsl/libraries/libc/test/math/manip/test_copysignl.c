#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    copysignl(1.0L,-4.5L);
    copysignl(-1.0L,4.5L);
    copysignl(6.0L,3.7L);
    copysignl(anylongdouble(),anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    long double x,y;
    
    x = anylongdouble();
    y = anylongdouble();
    result = copysignl(x,y);
    //@ assert (y < 0) ==> (result < 0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
