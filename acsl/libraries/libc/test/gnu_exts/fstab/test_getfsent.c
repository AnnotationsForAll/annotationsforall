#include "../../../test_common.h"
#include <fstab.h>

void runSuccess() {
    getfsent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    
    struct fstab * result = getfsent();
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
