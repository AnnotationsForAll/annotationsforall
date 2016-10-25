#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    lgammaf(0.0f);
    lgammaf(1.0f);
    lgammaf(-1.0f);
    lgammaf(56.5f);
    lgammaf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    lgammaf(anyfloat());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
