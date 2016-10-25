#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    setprotoent(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    setprotoent(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
