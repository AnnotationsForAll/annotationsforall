#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    sigset_t set[3];
    sigandset(&set[0], &set[1], &set[2]);
}

void runFailure() {
    sigset_t set[3];
    sigandset(NULL, &set[1], &set[2]);
}

void runFailure1() {
    sigset_t set[3];
    sigandset(&set[0], NULL, &set[2]);
}

void runFailure2() {
    sigset_t set[3];
    sigandset(&set[0], &set[1], NULL);
}

int f;
void testValues() {
    f = 2;
    
    sigset_t set[3];
    sigandset(&set[0], &set[1], &set[2]);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
