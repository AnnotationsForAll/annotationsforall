#include "../../../test_common.h"
#include <utmp.h>

void runSuccess() {
    login_tty(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    login_tty(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
