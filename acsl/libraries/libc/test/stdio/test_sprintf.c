#include "../../stdio_common.h"

void runSuccess() {
    //cannot ever validate that the input buffer is long enough; there could always be an overflow
}

void runFailure() {
    sprintf(NULL, "%s", "Hello");
}

void runFailure1() {
    char buf[10];
    
    sprintf(buf, NULL, "Hello");
}

int f;
void testValues() {
    f = 2;
    int result;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
