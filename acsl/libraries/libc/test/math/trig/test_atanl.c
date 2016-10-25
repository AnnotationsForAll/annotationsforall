#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

void runSuccess() {
    atanl(1.0L);
    atanl(0.0L);
    atanl(-1.0L);
    atanl(2.0L);
    atanl(-2.0L);
    atanl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = atan(0.5L);
    // assert \tan(result) == 0.5L;
    
    result = atanl(anylongdouble());
    //@ assert -M_PI/2.0 <= result <= M_PI/2.0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}