#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    setsid();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    pid_t result;
    
    setsid();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
