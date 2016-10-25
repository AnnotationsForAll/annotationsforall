#include "../../../test_common.h"
#include <err.h>

void runSuccess() {
    warnx(anystring());
}

void runFailure() {
    warnx(NULL);
}

int f;
void testValues() {
    f = 2;
    
    warnx(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
