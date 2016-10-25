#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    getpgrp();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    pid_t result;
    
    getpgrp();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
