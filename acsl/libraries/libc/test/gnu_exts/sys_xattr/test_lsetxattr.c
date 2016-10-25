#include "../../../test_common.h"
#include <sys/xattr.h>

void runSuccess() {
    char buf[10];
    lsetxattr(anystring(), anystring(), buf, 10, anyint());
}

void runFailure() {
    char buf[10];
    lsetxattr(anystring(), NULL, buf, 10, anyint());
}

void runFailure1() {
    char buf[10];
    lsetxattr(anystring(), anystring(), NULL, 10, anyint());
}

void runFailure2() {
    char buf[10];
    lsetxattr(anystring(), anystring(), buf, 20, anyint());
}

void runFailure3() {
    char buf[10];
    lsetxattr(NULL, anystring(), buf, 10, anyint());
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    lsetxattr(anystring(), anystring(), buf, 10, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
