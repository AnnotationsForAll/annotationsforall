#include "../../test_common.h"
#include <setjmp.h>

void runSuccess() {
    jmp_buf env;
    setjmp(env);
}

void runFailure() {
}

int f;
void testValues() {
    f = 2;
    int result;

    jmp_buf env;
    result = setjmp(env);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
