#include "../../../test_common.h"
#include <dlfcn.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    dlopen(buf, RTLD_GLOBAL);
}

void runSuccess1() {
    dlopen(NULL, RTLD_LOCAL);
}

int f;
void testValues() {
    f = 2;
    void* result;
    
    result = dlopen(NULL, RTLD_GLOBAL);
    //@ assert result == \null || \valid((char*)result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
