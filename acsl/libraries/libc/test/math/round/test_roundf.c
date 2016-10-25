#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    roundf(1.0f);
    roundf(0.0f);
    roundf(43.56f);
    roundf(-2.5f);
    roundf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    roundf(anyfloat());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
