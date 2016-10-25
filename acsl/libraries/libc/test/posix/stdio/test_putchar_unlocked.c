#include "../../../stdio_common.h"

void runSuccess() {
    putchar_unlocked(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    putchar_unlocked(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
