#include "../../../test_common.h"
#include <fstab.h>

void runSuccess() {
    setfsent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    setfsent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
