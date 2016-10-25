#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    rintl(1.0L);
    rintl(0.0L);
    rintl(43.56L);
    rintl(-2.5L);
    rintl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    rintl(1.0L);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
