#include "../../../test_common.h"
#include <utmp.h>

void runSuccess() {
    struct utmp u;
    updwtmp(anystring(), &u);
}

void runFailure() {
    struct utmp u;
    updwtmp(NULL, &u);
}

void runFailure1() {
    updwtmp(anystring(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct utmp u;
    updwtmp(anystring(), &u);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
