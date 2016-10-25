#include "../../../test_common.h"
#include <sys/xattr.h>

void runSuccess() {
    lremovexattr(anystring(), anystring());
}

void runFailure() {
    lremovexattr(anystring(), NULL);
}

void runFailure1() {
    lremovexattr(NULL, anystring());
}

int f;
void testValues() {
    f = 2;
    
    lremovexattr(anystring(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
