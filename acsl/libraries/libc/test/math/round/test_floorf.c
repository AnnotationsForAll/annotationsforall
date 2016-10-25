#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    floorf(1.0f);
    floorf(0.0f);
    floorf(43.56f);
    floorf(-2.5f);
    floorf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    floorf(anyfloat());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
