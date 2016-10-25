#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    tgammaf(0.0f);
    tgammaf(1.0f);
    tgammaf(-1.0f);
    tgammaf(56.5f);
    tgammaf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    float result;
    
    tgammaf(0.0f);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
