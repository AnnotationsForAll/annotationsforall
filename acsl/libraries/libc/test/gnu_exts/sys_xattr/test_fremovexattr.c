#include "../../../test_common.h"
#include <sys/xattr.h>

void runSuccess() {
    fremovexattr(anyint(), anystring());
}

void runFailure() {
    fremovexattr(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    fremovexattr(anyint(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
