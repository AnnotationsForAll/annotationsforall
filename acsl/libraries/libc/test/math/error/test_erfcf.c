#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    erfcf(0.0f);
    erfcf(1.0f);
    erfcf(-1.0f);
    erfcf(56.5f);
    erfcf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    erfcf(anyfloat());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
