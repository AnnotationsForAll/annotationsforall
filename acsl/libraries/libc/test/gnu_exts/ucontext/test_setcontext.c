#include "../../../test_common.h"
#include <ucontext.h>

void runSuccess() {
    ucontext_t uc;
    if (!getcontext(&uc)) {
        setcontext(&uc);
    }
}

void runFailure() {
    setcontext(NULL);
}

void runFailure1() {
    ucontext_t uc;
    setcontext(&uc);
}

int f;
void testValues() {
    f = 2;
    
    ucontext_t uc;
    if (!getcontext(&uc)) {
        setcontext(&uc);
    }

    // getcontext() might clobber the value of f, so do not assert the value of it.
    //@ assert vacuous: \false;
}
