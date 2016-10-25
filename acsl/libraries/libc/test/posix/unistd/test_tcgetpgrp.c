#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    tcgetpgrp(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    pid_t result;
    
    result = tcgetpgrp(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
