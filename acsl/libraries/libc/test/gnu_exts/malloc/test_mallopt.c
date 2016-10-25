#include "../../../test_common.h"
#include <malloc.h>

void runSuccess() {
    mallopt(M_MMAP_MAX, anyint());
    mallopt(M_MMAP_THRESHOLD, anyint());
    mallopt(M_TRIM_THRESHOLD, anyint());
    mallopt(M_TOP_PAD, anyint());
    mallopt(M_PERTURB, anyint());
}

void runFailure() {
    mallopt(anyint(), anyint());
}

int f;
void testValues() {
    f = 2;
    
    mallopt(M_MMAP_MAX, anyint());
    mallopt(M_MMAP_THRESHOLD, anyint());
    mallopt(M_TRIM_THRESHOLD, anyint());
    mallopt(M_TOP_PAD, anyint());
    mallopt(M_PERTURB, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
