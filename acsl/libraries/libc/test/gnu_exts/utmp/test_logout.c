#include "../../../test_common.h"
#include <utmp.h>

void runSuccess() {
    logout(anystring());
}

void runFailure() {
    logout(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    logout(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
