#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    int p;
    lgammal_r(0.0L, &p);
    lgammal_r(1.0L, &p);
    lgammal_r(-1.0L, &p);
    lgammal_r(56.5L, &p);
    lgammal_r(anylongdouble(), &p);
}

void runFailure() {
    lgammal_r(anylongdouble(), NULL);
}

int f;
void testValues() {
    f = 2;
    double result;
    
    int p;
    lgammal_r(anylongdouble(), &p);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
