#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    getpid();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    pid_t result;
    
    getpid();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
