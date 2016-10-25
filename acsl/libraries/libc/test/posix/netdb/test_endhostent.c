#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    endhostent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    endhostent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
