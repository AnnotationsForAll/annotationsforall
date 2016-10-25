#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    geteuid();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    uid_t result;
    
    geteuid();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
