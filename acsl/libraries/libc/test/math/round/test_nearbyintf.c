#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    nearbyintf(1.0f);
    nearbyintf(0.0f);
    nearbyintf(43.56f);
    nearbyintf(-2.5f);
    nearbyintf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    nearbyintf(1.0f);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
