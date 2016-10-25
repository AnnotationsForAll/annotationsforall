#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    unsigned short xsubi[7];
    xsubi[0] = (unsigned short) anyint();
    xsubi[1] = (unsigned short) anyint();
    xsubi[2] = (unsigned short) anyint();
    xsubi[3] = (unsigned short) anyint();
    xsubi[4] = (unsigned short) anyint();
    xsubi[5] = (unsigned short) anyint();
    xsubi[6] = (unsigned short) anyint();
    
    lcong48(xsubi);
}

void runFailure() {
    lcong48(NULL);
}

int f;
void testValues() {
    f = 2;
    long result;
    unsigned short xsubi[7];
    xsubi[0] = (unsigned short) anyint();
    xsubi[1] = (unsigned short) anyint();
    xsubi[2] = (unsigned short) anyint();
    xsubi[3] = (unsigned short) anyint();
    xsubi[4] = (unsigned short) anyint();
    xsubi[5] = (unsigned short) anyint();
    xsubi[6] = (unsigned short) anyint();
    
    lcong48(xsubi);
    //@ assert \valid_read(xsubi+(0..6));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
