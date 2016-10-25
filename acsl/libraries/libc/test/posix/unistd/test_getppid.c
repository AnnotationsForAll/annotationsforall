#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    getppid();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    pid_t result;
    
    getppid();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
