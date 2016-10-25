#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    llrintl(1.0L);
    llrintl(0.0L);
    llrintl(43.56L);
    llrintl(-2.5L);
    llrintl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long long int result;
    
    llrintl(1.0L);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
