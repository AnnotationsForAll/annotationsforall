#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    mkostemps(anystring(), anyint(), anyint());
}

void runFailure() {
    mkostemps(NULL, anyint(), anyint());
}

int f;
void testValues() {
    f = 2;

    mkostemps(anystring(), anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
