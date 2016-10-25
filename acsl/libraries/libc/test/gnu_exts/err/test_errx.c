#include "../../../test_common.h"
#include <err.h>

void runSuccess() {
    errx(anyint(), anystring());
}

void runFailure() {
    errx(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    


    //@ assert f == 2;
    //@ assert vacuous: \false;
}
