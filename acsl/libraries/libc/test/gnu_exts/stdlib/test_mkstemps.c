#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    mkstemps(anystring(), anyint());
}

void runFailure() {
    mkstemps(NULL, anyint());
}

int f;
void testValues() {
    f = 2;

    mkstemps(anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
