#include "../../../test_common.h"
#include <math.h>
#include <limits.h>

void runSuccess() {
    ilogbf(1.0f);
    ilogbf(-1.0f);
    ilogbf(0.1f);
    ilogbf(-0.1f);
    ilogbf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = ilogbf(0.0f);
    //@ assert result == FP_ILOGB0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
