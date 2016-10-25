#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    getgid();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    gid_t result;
    
    getgid();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
