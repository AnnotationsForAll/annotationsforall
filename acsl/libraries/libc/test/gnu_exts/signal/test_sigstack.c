#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    struct sigstack ss;
    struct sigstack oss;
    sigstack(&ss, &oss);
}

void runSuccess1() {
    struct sigstack ss;
    struct sigstack oss;
    sigstack(&ss, NULL);
}

void runFailure() {
    struct sigstack ss;
    struct sigstack oss;
    sigstack(NULL, &oss);
}

int f;
void testValues() {
    f = 2;
    
    struct sigstack ss;
    struct sigstack oss;
    sigstack(&ss, &oss);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
