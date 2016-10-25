#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    roundl(1.0L);
    roundl(0.0L);
    roundl(43.56L);
    roundl(-2.5L);
    roundl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    roundl(anylongdouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
