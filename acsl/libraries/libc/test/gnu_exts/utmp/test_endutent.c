#include "../../../test_common.h"
#include <utmp.h>

void runSuccess() {
    endutent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    endutent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
