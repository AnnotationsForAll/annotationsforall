#include "../../../test_common.h"
#include <dlfcn.h>

void runSuccess() {
    void* handle = dlopen(anystring(), 0);
    if (handle != NULL) {
        dlvsym(handle, anystring(), anystring());
    }
}

void runFailure() {
    dlvsym(NULL, anystring(), anystring());
}

void runFailure1() {
    void* handle = dlopen(anystring(), 0);
    if (handle != NULL) {
        dlvsym(handle, NULL, anystring());
    }
}

void runFailure2() {
    void* handle = dlopen(anystring(), 0);
    if (handle != NULL) {
        dlvsym(handle, anystring(), NULL);
    }
}

int f;
void testValues() {
    f = 2;
    void* result;
    
    void* handle = dlopen(anystring(), 0);
    if (handle != NULL) {
        result = dlvsym(handle, anystring(), anystring());
        //@ assert result == \null || \valid((char*)result);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
