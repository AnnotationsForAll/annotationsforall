#include "../../../test_common.h"
#include <fstab.h>

void runSuccess() {
    getfsfile(anystring());
}

void runFailure() {
    getfsfile(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct fstab * result = getfsfile(anystring());
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
