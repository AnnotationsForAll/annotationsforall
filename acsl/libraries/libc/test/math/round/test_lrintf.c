#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    lrintf(1.0f);
    lrintf(0.0f);
    lrintf(43.56f);
    lrintf(-2.5f);
    lrintf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long int result;
    
    lrintf(1.0f);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
