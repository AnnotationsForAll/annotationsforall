#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    cbrtl(1.0L);
    cbrtl(0.0L);
    cbrtl(-1.0L);
    cbrtl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    cbrtl(anylongdouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
