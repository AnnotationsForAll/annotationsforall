#include "../../../test_common.h"
#include <sys/mman.h>

void runSuccess() {
    posix_typed_mem_open(anystring(), anyint(), anyint());
}

void runFailure() {
    posix_typed_mem_open(NULL, anyint(), anyint());
}

int f;
void testValues() {
    f = 2;
    
    posix_typed_mem_open(anystring(), anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
