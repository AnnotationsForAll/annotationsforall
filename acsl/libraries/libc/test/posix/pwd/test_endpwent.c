#include "../../../test_common.h"
#include <pwd.h>

void runSuccess() {
    endpwent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    endpwent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
