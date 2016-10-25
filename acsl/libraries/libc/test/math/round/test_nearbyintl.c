#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    nearbyintl(1.0L);
    nearbyintl(0.0L);
    nearbyintl(43.56L);
    nearbyintl(-2.5L);
    nearbyintl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    nearbyintl(1.0L);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
