#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    gethostid();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    gid_t result;
    
    gethostid();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
