#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    nice(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = nice(anyint());
    //@ assert result <= sysconf(_SC_NZERO)-1 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
