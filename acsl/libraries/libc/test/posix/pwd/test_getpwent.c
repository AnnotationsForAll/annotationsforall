#include "../../../test_common.h"
#include <pwd.h>

void runSuccess() {
    getpwent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct passwd * result;
    
    result = getpwent();
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
