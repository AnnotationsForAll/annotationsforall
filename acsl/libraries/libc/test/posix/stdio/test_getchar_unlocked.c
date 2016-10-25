#include "../../../stdio_common.h"

void runSuccess() {
    getchar_unlocked();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = getchar_unlocked();
    //@ assert result == EOF || (unsigned char)result == result;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
