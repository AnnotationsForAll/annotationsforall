#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    ttyname(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = ttyname(anyint());
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
