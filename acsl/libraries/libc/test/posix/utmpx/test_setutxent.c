#include "../../../test_common.h"
#include <utmpx.h>

void runSuccess() {
    setutxent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    setutxent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
