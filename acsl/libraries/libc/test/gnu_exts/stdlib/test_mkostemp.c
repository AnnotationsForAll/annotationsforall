#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    mkostemp(anystring(), anyint());
}

void runFailure() {
    mkostemp(NULL, anyint());
}

int f;
void testValues() {
    f = 2;

    mkostemp(anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
