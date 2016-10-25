#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    remainderl(0.1L,4.0L);
    remainderl(1.2L,0.0L);
    remainderl(2.0L,4.3L);
    remainderl(anylongdouble(),anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    remainderl(0.1L,4.0L);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
