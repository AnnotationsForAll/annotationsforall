#include "../../../test_common.h"
#include <math.h>
#include <limits.h>

void runSuccess() {
    ilogbl(1.0L);
    ilogbl(-1.0L);
    ilogbl(0.1L);
    ilogbl(-0.1L);
    ilogbl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = ilogbl(0.0L);
    //@ assert result == FP_ILOGB0;
    result = ilogbl(1.0L);
    //@ assert result == 0;
    result = ilogbl(111.0L);
    //@ assert result == 6;
    result = ilogbl(0.01L);
    //@ assert result == -7;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}