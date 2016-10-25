#include "../../../test_common.h"
#include <sys/swap.h>

void runSuccess() {
    swapon(anystring(), anyint());
}

void runFailure() {
    swapon(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    swapon(anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
