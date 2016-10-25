#include "../../../test_common.h"
#include <ucontext.h>

void runSuccess() {
    ucontext_t uc;
    if (!getcontext(&uc)) {
        makecontext(&uc, runSuccess, 0);
    }
}

void runFailure() {
    makecontext(NULL, runFailure, 0);
}

void runFailure1() {
    ucontext_t uc;
    makecontext(&uc, runFailure, 0);
}

void runFailure2() {
    ucontext_t uc;
    if (!getcontext(&uc)) {
        makecontext(&uc, NULL, 0);
    }
}

int f;
void testValues() {
    f = 2;
    
    ucontext_t uc;
    if (!getcontext(&uc)) {
        makecontext(&uc, testValues, 0);
    }

    // getcontext() might clobber the value of f, so do not assert the value of it.
    //@ assert vacuous: \false;
}
