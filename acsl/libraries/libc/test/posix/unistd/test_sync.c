#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    sync();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    
    sync();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
