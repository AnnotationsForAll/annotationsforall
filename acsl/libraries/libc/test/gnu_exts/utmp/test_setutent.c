#include "../../../test_common.h"
#include <utmp.h>

void runSuccess() {
    setutent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    setutent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
