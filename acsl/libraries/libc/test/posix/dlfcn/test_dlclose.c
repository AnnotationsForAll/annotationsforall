#include "../../../test_common.h"
#include <dlfcn.h>

/*
assigns \result;
ensures \valid((char*)\result);
*/
extern void* anyhandle();

void runSuccess() {
    char buf[] = "";
    void* handle = dlopen(buf, 0);
    if (handle != NULL) {
        dlclose(handle);
    }
}

void runFailure() {
    dlclose(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    char buf[] = "";
    void* handle = dlopen(buf, 0);
    if (handle != NULL) {
        dlclose(handle);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
