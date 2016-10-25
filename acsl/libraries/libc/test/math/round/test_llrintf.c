#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    llrintf(1.0f);
    llrintf(0.0f);
    llrintf(43.56f);
    llrintf(-2.5f);
    llrintf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long long int result;
    
    llrintf(1.0f);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
