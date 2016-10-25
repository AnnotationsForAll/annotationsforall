#include "../../../test_common.h"
#include <grp.h>

void runSuccess() {
    endgrent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    endgrent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
