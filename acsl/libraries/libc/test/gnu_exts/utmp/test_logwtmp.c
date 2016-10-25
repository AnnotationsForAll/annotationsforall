#include "../../../test_common.h"
#include <utmp.h>

void runSuccess() {
    logwtmp(anystring(), anystring(), anystring());
}

void runFailure() {
    logwtmp(NULL, anystring(), anystring());
}

void runFailure1() {
    logwtmp(anystring(), NULL, anystring());
}

void runFailure2() {
    logwtmp(anystring(), anystring(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    logwtmp(anystring(), anystring(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
