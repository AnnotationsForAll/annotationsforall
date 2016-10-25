#include "../../../test_common.h"
#include <fstab.h>

void runSuccess() {
    endfsent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    endfsent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
