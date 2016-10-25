#include "../../../test_common.h"
#include <strings.h>

void runSuccess() {
    ffs(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = ffs(0);
    //@ assert result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
