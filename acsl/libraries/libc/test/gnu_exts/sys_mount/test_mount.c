#include "../../../test_common.h"
#include <sys/mount.h>

void runSuccess() {
    mount(anystring(), anystring(), anystring(), anyint(), anystring());
}

void runFailure() {
    mount(NULL, anystring(), anystring(), anyint(), anystring());
}

void runFailure1() {
    mount(anystring(), NULL, anystring(), anyint(), anystring());
}

void runFailure2() {
    mount(anystring(), anystring(), NULL, anyint(), anystring());
}

void runFailure3() {
    mount(anystring(), anystring(), anystring(), anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    mount(anystring(), anystring(), anystring(), anyint(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
