#include "../../../test_common.h"
#include <ucontext.h>

void runSuccess() {
    ucontext_t uc;
    if (!getcontext(&uc)) {
        ucontext_t oc;
        swapcontext(&oc, &uc);
    }
}

void runFailure() {
    ucontext_t uc;
    if (!getcontext(&uc)) {
        ucontext_t oc;
        swapcontext(NULL, &uc);
    }
}

void runFailure1() {
    ucontext_t oc;
    swapcontext(&oc, NULL);
}

void runFailure2() {
    ucontext_t uc;
    ucontext_t oc;
    swapcontext(&oc, &uc);
}

int f;
void testValues() {
    f = 2;
    
    ucontext_t uc;
    if (!getcontext(&uc)) {
        ucontext_t oc;
        swapcontext(&oc, &uc);
    }

    // getcontext() might clobber the value of f, so do not assert the value of it.
    //@ assert vacuous: \false;
}
