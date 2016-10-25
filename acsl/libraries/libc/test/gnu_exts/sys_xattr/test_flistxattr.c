#include "../../../test_common.h"
#include <sys/xattr.h>

void runSuccess() {
    char buf[10];
    flistxattr(anyint(), buf, 10);
}

void runFailure() {
    char buf[10];
    flistxattr(anyint(), NULL, 10);
}

void runFailure1() {
    char buf[10];
    flistxattr(anyint(), buf, 20);
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    flistxattr(anyint(), buf, 10);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
