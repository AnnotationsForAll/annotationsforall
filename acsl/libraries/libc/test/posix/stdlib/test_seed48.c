#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    unsigned short xsubi[3];
    xsubi[0] = (unsigned short) anyint();
    xsubi[1] = (unsigned short) anyint();
    xsubi[2] = (unsigned short) anyint();
    
    seed48(xsubi);
}

void runFailure() {
    seed48(NULL);
}

int f;
void testValues() {
    f = 2;
    unsigned short * result;
    unsigned short xsubi[3];
    xsubi[0] = (unsigned short) anyint();
    xsubi[1] = (unsigned short) anyint();
    xsubi[2] = (unsigned short) anyint();
    
    result = seed48(xsubi);
    //@ assert \valid_read(xsubi+(0..2));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
