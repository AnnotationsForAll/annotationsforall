#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    fmal(1.0L,2.0L,3.0L);
    fmal(5.6L,7.5L,6.8L);
    fmal(anylongdouble(),anylongdouble(),anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    long double x,y,z;
    
    result = fmal(1.0L,2.0L,3.0L);
    //@ assert result == 5.0;
    
    x = anylongdouble();
    y = anylongdouble();
    z = anylongdouble();
    result = fmal(x,y,z);
    //@ assert result == (x*y)+z;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
