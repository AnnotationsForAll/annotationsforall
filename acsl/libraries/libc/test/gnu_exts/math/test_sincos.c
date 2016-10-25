#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    double x, y;
    sincos(anydouble(), &x, &y);
}

void runFailure() {
    sincos(anydouble(), NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    
    double x, y;
    sincos(anydouble(), &x, &y);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
