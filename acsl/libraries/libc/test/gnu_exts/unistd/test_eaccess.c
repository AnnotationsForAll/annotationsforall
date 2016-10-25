#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    eaccess(anystring(), anyint());
}

void runFailure() {
    eaccess(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    eaccess(anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
