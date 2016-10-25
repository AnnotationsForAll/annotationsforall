#include "../../../stdio_common.h"
#include <mntent.h>

void runSuccess() {
    setmntent(anystring(), anystring());
}

void runFailure() {
    setmntent(NULL, anystring());
}

void runFailure1() {
    setmntent(anystring(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    setmntent(anystring(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
