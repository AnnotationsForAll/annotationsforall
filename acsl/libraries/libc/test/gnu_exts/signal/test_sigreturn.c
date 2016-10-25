#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    struct sigcontext sc;
    sigreturn(&sc);
}

void runFailure() {
    struct sigcontext sc;
    sigreturn(NULL);
}

int f;
void testValues() {
    f = 2;
    


    //@ assert f == 2;
    //@ assert vacuous: \false;
}
