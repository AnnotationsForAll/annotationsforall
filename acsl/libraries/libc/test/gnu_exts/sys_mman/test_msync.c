#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    char buf[10];
    msync(buf, 10, anyint());
}

void runSuccess1() {
    char buf[10];
    msync(buf, 5, anyint());
}

void runFailure() {
    msync(NULL, 10, anyint());
}

void runFailure1() {
    char buf[10];
    msync(buf, 30, anyint());
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    msync(buf, 10, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
