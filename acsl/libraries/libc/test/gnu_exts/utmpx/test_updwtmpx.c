#include "../../../test_common.h"
#include <utmp.h>

void runSuccess() {
    struct utmpx u;
    updwtmpx(anystring(), &u);
}

void runFailure() {
    struct utmpx u;
    updwtmpx(NULL, &u);
}

void runFailure1() {
    updwtmpx(anystring(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct utmpx u;
    updwtmpx(anystring(), &u);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
