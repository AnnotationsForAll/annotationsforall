#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    lroundl(1.0L);
    lroundl(0.0L);
    lroundl(43.56L);
    lroundl(-2.5L);
    lroundl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long int result;
    
    lroundl(anylongdouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
