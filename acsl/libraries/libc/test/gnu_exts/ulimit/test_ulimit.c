#include "../../../test_common.h"
#include <ulimit.h>

void runSuccess() {
    ulimit(GETFSIZE);
}

void runSuccess1() {
    ulimit(SETFSIZE, anysize());
}

void runFailure() {
    ulimit(anyint());
}

int f;
void testValues() {
    f = 2;
    
    long result = ulimit(GETFSIZE);
    //@ assert result >= -1;

    ulimit(SETFSIZE, anysize());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
