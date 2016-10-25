#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    char buf[10];
    mprotect(buf, 10, anyint());
}

void runFailure() {
    mprotect(NULL, 10, anyint());
}

void runFailure1() {
    char buf[10];
    mprotect(buf, 20, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    char buf[10];
    result = mprotect(buf, 10, anyint());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
