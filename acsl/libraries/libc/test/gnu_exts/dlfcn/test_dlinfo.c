#include "../../../test_common.h"
#include <dlfcn.h>

void runSuccess() {
    void* handle = dlopen(anystring(), 0);
    if (handle != NULL) {
        Lmid_t lmid;
        dlinfo(handle, RTLD_DI_LMID, &lmid);
    }
}

void runFailure() {
    Lmid_t lmid;
    dlinfo(NULL, RTLD_DI_LMID, &lmid);
}

int f;
void testValues() {
    f = 2;
    
    void* handle = dlopen(anystring(), 0);
    if (handle != NULL) {
        Lmid_t lmid;
        dlinfo(handle, RTLD_DI_LMID, &lmid);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
