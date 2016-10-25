#include "../../../test_common.h"
#include <sys/xattr.h>

void runSuccess() {
    removexattr(anystring(), anystring());
}

void runFailure() {
    removexattr(anystring(), NULL);
}

void runFailure1() {
    removexattr(NULL, anystring());
}

int f;
void testValues() {
    f = 2;
    
    removexattr(anystring(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
