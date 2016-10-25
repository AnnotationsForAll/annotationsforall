#include "../../../test_common.h"
#include <sys/mount.h>

void runSuccess() {
    umount(anystring());
}

void runFailure() {
    umount(NULL);
}

int f;
void testValues() {
    f = 2;
    
    umount(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
