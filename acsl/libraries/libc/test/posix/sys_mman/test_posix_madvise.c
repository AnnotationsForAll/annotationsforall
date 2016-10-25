#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    void* addr;
    posix_madvise(addr, anysize(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    void* addr;
    posix_madvise(addr, anysize(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
