#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    unsigned short xsubi[3];
    
    nrand48(xsubi);
}

void runFailure() {
    nrand48(NULL);
}

int f;
void testValues() {
    f = 2;
    long result;
    unsigned short xsubi[3];
    
    result = nrand48(xsubi);
    //@ assert 0 <= result < 2147483648;
    //@ assert \valid_read(xsubi+(0..2));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
