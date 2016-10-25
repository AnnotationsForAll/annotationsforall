#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    setnetent(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    setnetent(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
