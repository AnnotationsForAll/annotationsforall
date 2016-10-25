#include "../../../test_common.h"
#include <sys/swap.h>

void runSuccess() {
    swapoff(anystring());
}

void runFailure() {
    swapoff(NULL);
}

int f;
void testValues() {
    f = 2;
    
    swapoff(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
