#include "../../../test_common.h"
#include <dlfcn.h>

void runSuccess() {
    dlerror();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = dlerror();
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
