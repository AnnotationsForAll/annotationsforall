#include "../../test_common.h"
#include <setjmp.h>

void runSuccess() {
    sigjmp_buf env;
    sigsetjmp(env, 0);
}

void runFailure() {
}

int f;
void testValues() {
    f = 2;
    int result;

    sigjmp_buf env;
    result = sigsetjmp(env, 0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
