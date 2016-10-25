#include "../../../test_common.h"
#include <err.h>

void runSuccess() {
    err(anyint(), anystring());
}

void runFailure() {
    err(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    


    //@ assert f == 2;
    //@ assert vacuous: \false;
}
