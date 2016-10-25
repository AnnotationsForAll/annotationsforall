#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    pause();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = pause();
    //@ assert result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
