#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    isatty(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isatty(anyint());
    //@ assert result == 1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
