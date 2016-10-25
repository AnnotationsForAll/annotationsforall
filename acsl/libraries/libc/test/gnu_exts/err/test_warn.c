#include "../../../test_common.h"
#include <err.h>

void runSuccess() {
    warn(anystring());
}

void runFailure() {
    warn(NULL);
}

int f;
void testValues() {
    f = 2;
    
    warn(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
