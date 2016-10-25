#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    setpgrp();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    pid_t result;
    
    setpgrp();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
