#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

void runSuccess() {
    atanf(1.0f);
    atanf(0.0f);
    atanf(-1.0f);
    atanf(2.0f);
    atanf(-2.0f);
    atanf(INFINITY);
//    atanf(NAN);
    atanf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    //result = atanf(0.5f);
    // assert \tan(result) == 0.5f;
    
    result = atanf(anyfloat());
    //@ assert -M_PI/2.0 <= result <= M_PI/2.0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
