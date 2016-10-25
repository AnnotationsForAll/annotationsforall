#include "../../../test_common.h"
#include <fstab.h>

void runSuccess() {
    getfsspec(anystring());
}

void runFailure() {
    getfsspec(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct fstab * result = getfsspec(anystring());
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
