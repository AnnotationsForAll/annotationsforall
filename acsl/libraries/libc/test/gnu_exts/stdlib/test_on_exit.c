#include "../../../test_common.h"
#include <stdlib.h>

void any_on_exit(int status, void *arg);

void runSuccess() {
    void* arg;
    on_exit(any_on_exit, arg);
}

void runFailure() {
    void* arg;
    on_exit(NULL, arg);
}

int f;
void testValues() {
    f = 2;
    
    void* arg;
    on_exit(any_on_exit, arg);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
