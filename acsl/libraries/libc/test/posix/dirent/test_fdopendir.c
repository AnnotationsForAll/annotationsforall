#include "../../../test_common.h"
#include <dirent.h>
#include <errno.h>

void runSuccess() {
    fdopendir(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    DIR* result;
    
    result = fdopendir(anyint());
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
