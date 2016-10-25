#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    char buf[10];
    munmap(buf, 10);
}

void runFailure() {
    munmap(NULL, 10);
}

void runFailure1() {
    char buf[10];
    munmap(buf, 20);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    char buf[10];
    result = munmap(buf, 10);
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
