#include "../../../test_common.h"
#include <math.h>
#include <errno.h>

void runSuccess() {
    asinhl(1.0L);
    asinhl(0.0L);
    asinhl(-1.0L);
    asinhl(2.0L);
    asinhl(-2.0L);
    asinhl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = asinhl(0.5L);
    // assert \sinhl(result) == 0.5;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}