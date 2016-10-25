#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    sigset_t set;
    sigisemptyset(&set);
}

void runFailure() {
    sigisemptyset(NULL);
}

int f;
void testValues() {
    f = 2;
    
    sigset_t set;
    sigisemptyset(&set);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
