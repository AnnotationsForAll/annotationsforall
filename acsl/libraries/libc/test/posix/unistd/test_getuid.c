#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    getuid();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    uid_t result;
    
    getuid();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
