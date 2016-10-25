#include "../../../test_common.h"
#include <grp.h>

void runSuccess() {
    getgrent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct group * result;
    
    result = getgrent();
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
