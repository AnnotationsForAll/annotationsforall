#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    lrintl(1.0L);
    lrintl(0.0L);
    lrintl(43.56L);
    lrintl(-2.5L);
    lrintl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long int result;
    
    lrintl(1.0L);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
