#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    getegid();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    gid_t result;
    
    getegid();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
