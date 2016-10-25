#include "../../../test_common.h"
#include <dlfcn.h>

void runSuccess() {
    Dl_info info;
    dladdr(anystring(), &info);
}

void runSuccess1() {
    Dl_info info;
    dladdr(NULL, &info);
}

void runFailure() {
    Dl_info info;
    dladdr(anystring(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    Dl_info info;
    int result = dladdr(anystring(), &info);
    //@ assert result != 0 ==> valid_string(info.dli_fname);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
