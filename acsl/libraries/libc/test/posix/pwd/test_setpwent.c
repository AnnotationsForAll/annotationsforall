#include "../../../test_common.h"
#include <pwd.h>

void runSuccess() {
    setpwent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    setpwent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
