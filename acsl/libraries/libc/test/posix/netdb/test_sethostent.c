#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    sethostent(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    sethostent(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
