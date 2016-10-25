#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    cbrtf(1.0f);
    cbrtf(0.0f);
    cbrtf(-1.0f);
    cbrtf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    cbrtf(anyfloat());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
