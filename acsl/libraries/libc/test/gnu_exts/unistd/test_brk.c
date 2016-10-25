#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    void* addr = sbrk(0);
    if (addr != ((void*)-1)) {
        brk(addr);
    }
}

void runFailure() {
    brk(NULL);
}

int f;
void testValues() {
    f = 2;
    
    void* addr = sbrk(0);
    if (addr != ((void*)-1)) {
        brk(addr);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
