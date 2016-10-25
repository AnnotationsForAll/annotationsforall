#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    rpmatch(anystring());
}

void runFailure() {
    rpmatch(NULL);
}

int f;
void testValues() {
    f = 2;
    
    rpmatch(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
