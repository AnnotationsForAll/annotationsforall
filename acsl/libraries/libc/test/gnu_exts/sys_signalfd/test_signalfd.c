#include "../../../test_common.h"
#include <sys/signalfd.h>

void runSuccess() {
    sigset_t mask;
    signalfd(anyint(), &mask, anyint());
}

void runFailure() {
    sigset_t mask;
    signalfd(anyint(), NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    sigset_t mask;
    signalfd(anyint(), &mask, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
