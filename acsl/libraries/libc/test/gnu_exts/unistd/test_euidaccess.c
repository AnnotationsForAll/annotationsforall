#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    euidaccess(anystring(), anyint());
}

void runFailure() {
    euidaccess(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    euidaccess(anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
