#include "../../../test_common.h"
#include <math.h>
#include <limits.h>

void runSuccess() {
    logbf(1.0f);
    logbf(-1.0f);
    logbf(0.1f);
    logbf(-0.1f);
    logbf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    result = logbf(1.0f);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
