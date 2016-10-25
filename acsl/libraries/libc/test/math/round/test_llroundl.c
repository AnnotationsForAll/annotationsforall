#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    llroundl(1.0L);
    llroundl(0.0L);
    llroundl(43.56L);
    llroundl(-2.5L);
    llroundl(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long long int result;
    
    llroundl(anylongdouble());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
