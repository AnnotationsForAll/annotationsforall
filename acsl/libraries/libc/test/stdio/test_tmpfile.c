#include "../../stdio_common.h"

void runSuccess() {
    tmpfile();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    FILE* result;
    
    result = tmpfile();
    //@ assert result == \null || \valid(result);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
