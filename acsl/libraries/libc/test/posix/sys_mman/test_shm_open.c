#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    shm_open(anystring(), anyint(), anyint());
}

void runFailure() {
    shm_open(NULL, anyint(), anyint());
}

int f;
void testValues() {
    f = 2;
    
    shm_open(anystring(), anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
