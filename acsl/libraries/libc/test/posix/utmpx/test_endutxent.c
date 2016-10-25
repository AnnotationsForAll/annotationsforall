#include "../../../test_common.h"
#include <utmpx.h>

void runSuccess() {
    endutxent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    endutxent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
