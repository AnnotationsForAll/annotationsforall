#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[64];
    setkey(buf);
}

void runFailure() {
    setkey(NULL);
}

void runFailure1() {
    char buf[5];
    setkey(buf);
}


int f;
void testValues() {
    f = 2;
    char* result;
    char buf[64];
    
    setkey(buf);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
