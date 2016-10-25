#include "../../../test_common.h"
#include <ucontext.h>

void runSuccess() {
    ucontext_t uc;
    getcontext(&uc);
}

void runFailure() {
    getcontext(NULL);
}

int f;
void testValues() {
    f = 2;
    
    ucontext_t uc;
    getcontext(&uc);

    // getcontext() might clobber the value of f, so do not assert the value of it.
    //@ assert vacuous: \false;
}
