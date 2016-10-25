#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    powl(5.0L,6.0L);
    powl(1.2L,6.7L);
    powl(0.0L,2.0L);
    powl(4.45L,0.0L);
    powl(anylongdouble(),anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    powl(anylongdouble(),anylongdouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
