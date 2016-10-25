#include "../../../test_common.h"
#include <utmp.h>

void runSuccess() {
    getutent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct utmp * result;
    
    result = getutent();
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
