#include "../../../test_common.h"
#include <sys/mount.h>

void runSuccess() {
    umount2(anystring(), anyint());
}

void runFailure() {
    umount2(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    umount2(anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
