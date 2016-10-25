#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    getlogin();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = getlogin();
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
