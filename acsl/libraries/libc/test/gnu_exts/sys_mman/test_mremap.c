#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    char buf[10];
    mremap(buf, 10, 20, anyint());
}

void runFailure() {
    mremap(NULL, 10, 20, anyint());
}

void runFailure1() {
    char buf[10];
    mremap(buf, 30, 50, anyint());
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    mremap(buf, 10, 20, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
