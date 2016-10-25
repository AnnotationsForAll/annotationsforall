#include "../../../test_common.h"
#include <math.h>
#include <float.h>
#include <errno.h>

void runSuccess() {
    lgammal(0.0L);
    lgammal(1.0L);
    lgammal(-1.0L);
    lgammal(56.5L);
    lgammal(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    lgammal(anylongdouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
