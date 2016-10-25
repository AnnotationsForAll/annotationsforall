#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    int p;
    lgammaf_r(0.0f, &p);
    lgammaf_r(1.0f, &p);
    lgammaf_r(-1.0f, &p);
    lgammaf_r(56.5f, &p);
    lgammaf_r(anyfloat(), &p);
}

void runFailure() {
    lgammaf_r(anyfloat(), NULL);
}

int f;
void testValues() {
    f = 2;
    float result;
    
    int p;
    lgammaf_r(anyfloat(), &p);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
