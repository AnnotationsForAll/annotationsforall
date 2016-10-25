#include "../../../test_common.h"
#include <grp.h>

void runSuccess() {
    setgrent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    setgrent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
