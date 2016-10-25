#include "../../../test_common.h"
#include <mcheck.h>

void runSuccess() {
    mprobe(anystring());
}

void runFailure() {
    mprobe(NULL);
}

int f;
void testValues() {
    f = 2;
    
    mprobe(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
