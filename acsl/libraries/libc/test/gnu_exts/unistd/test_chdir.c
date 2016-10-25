#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    chdir(anystring());
}

void runFailure() {
    chdir(NULL);
}

int f;
void testValues() {
    f = 2;
    
    chdir(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
