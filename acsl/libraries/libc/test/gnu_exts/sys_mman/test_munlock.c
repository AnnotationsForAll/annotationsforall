#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    char buf[10];
    munlock(buf, 10);
}

void runFailure() {
    munlock(NULL, 10);
}

void runFailure1() {
    char buf[10];
    munlock(buf, 30);
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    munlock(buf, 10);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
