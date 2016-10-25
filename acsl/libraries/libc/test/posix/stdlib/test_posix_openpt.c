#include "../../../test_common.h"
#include <stdlib.h>
#include <fcntl.h>

void runSuccess() {
    posix_openpt(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = posix_openpt(anyint());
    //@ assert result >= -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
