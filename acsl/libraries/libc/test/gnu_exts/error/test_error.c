#include "../../../test_common.h"
#include <error.h>

void runSuccess() {
    error(anyint(), anyint(), anystring());
}

void runFailure() {
    error(anyint(), anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    error(0, anyint(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
