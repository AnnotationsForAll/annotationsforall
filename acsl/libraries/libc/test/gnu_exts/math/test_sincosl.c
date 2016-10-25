#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    double x, y;
    sincosl(anylongdouble(), &x, &y);
}

void runFailure() {
    sincosl(anylongdouble(), NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    
    double x, y;
    sincosl(anylongdouble(), &x, &y);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
