#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    unsigned short xsubi[3];
    
    erand48(xsubi);
}

void runFailure() {
    erand48(NULL);
}

int f;
void testValues() {
    f = 2;
    double result;
    unsigned short xsubi[3];
    
    result = erand48(xsubi);
    //@ assert 0 <= result < 1;
    //@ assert \valid_read(xsubi+(0..2));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
