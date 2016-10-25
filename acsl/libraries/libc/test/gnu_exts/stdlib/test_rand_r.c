#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    unsigned i;
    rand_r(&i);
}

void runFailure() {
    rand_r(NULL);
}

int f;
void testValues() {
    f = 2;
    
    unsigned i;
    int result = rand_r(&i);
    //@ assert 0 <= result <= RAND_MAX;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
