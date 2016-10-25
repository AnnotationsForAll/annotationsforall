#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    fmodl(0.1L,4.0L);
    fmodl(1.2L,0.0L);
    fmodl(2.0L,4.3L);
    fmodl(anylongdouble(),anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    fmodl(0.1L,4.0L);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
