#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    dup2(anyint(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = dup2(anyint(), anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
