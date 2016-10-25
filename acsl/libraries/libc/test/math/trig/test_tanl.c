#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    tanl(0.0L);
    tanl(1.0L);
    tanl(-1.0L);
    tanl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}