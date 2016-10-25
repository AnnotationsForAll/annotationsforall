#include "../../../test_common.h"
#include <dlfcn.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    void* handle = dlopen(buf, 0);
    if (handle != NULL) {
        dlsym(handle, buf);
    }
}

void runFailure() {
    dlsym(NULL,NULL);
}

int f;
void testValues() {
    f = 2;
    void* result;
    
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    void* handle = dlopen(buf, 0);
    if (handle != NULL) {
        result = dlsym(handle, buf);
        //@ assert result == \null || \valid((char*)result);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
