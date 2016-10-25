#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    chroot(anystring());
}

void runFailure() {
    chroot(NULL);
}

int f;
void testValues() {
    f = 2;
    
    chroot(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
