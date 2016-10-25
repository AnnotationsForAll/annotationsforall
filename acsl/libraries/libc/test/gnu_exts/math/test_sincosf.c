#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    float x, y;
    sincosf(anyfloat(), &x, &y);
}

void runFailure() {
    sincosf(anyfloat(), NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    
    float x, y;
    sincosf(anyfloat(), &x, &y);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
