#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    setservent(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    setservent(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
