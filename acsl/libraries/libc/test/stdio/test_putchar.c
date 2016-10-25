#include "../../stdio_common.h"

void runSuccess() {
    putchar(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    putchar(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
