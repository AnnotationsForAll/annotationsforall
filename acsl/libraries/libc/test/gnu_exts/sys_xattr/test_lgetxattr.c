#include "../../../test_common.h"
#include <sys/xattr.h>

void runSuccess() {
    char buf[10];
    lgetxattr(anystring(), anystring(), buf, 10);
}

void runFailure() {
    char buf[10];
    lgetxattr(anystring(), NULL, buf, 10);
}

void runFailure1() {
    char buf[10];
    lgetxattr(anystring(), anystring(), NULL, 10);
}

void runFailure2() {
    char buf[10];
    lgetxattr(anystring(), anystring(), buf, 20);
}

void runFailure3() {
    char buf[10];
    lgetxattr(NULL, anystring(), buf, 10);
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    lgetxattr(anystring(), anystring(), buf, 10);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
