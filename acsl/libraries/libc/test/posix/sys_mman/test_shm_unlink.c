#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    shm_unlink(anystring());
}

void runFailure() {
    shm_unlink(NULL);
}

int f;
void testValues() {
    f = 2;
    
    shm_unlink(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
