#include "../../../test_common.h"
#include <fcntl.h>

void runSuccess() {
    fcntl(anyint(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    fcntl(anyint(), anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
