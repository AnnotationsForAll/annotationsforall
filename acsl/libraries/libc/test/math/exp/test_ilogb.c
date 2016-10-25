#include "../../../test_common.h"
#include <math.h>
#include <limits.h>

void runSuccess() {
    ilogb(1.0);
    ilogb(-1.0);
    ilogb(0.1);
    ilogb(-0.1);
    ilogb(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = ilogb(0.0);
    //@ assert result == FP_ILOGB0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
