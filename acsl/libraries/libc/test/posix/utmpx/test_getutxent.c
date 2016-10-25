#include "../../../test_common.h"
#include <utmpx.h>

void runSuccess() {
    getutxent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct utmpx * result;
    
    result = getutxent();
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
