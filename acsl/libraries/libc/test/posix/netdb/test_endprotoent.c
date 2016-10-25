#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    endprotoent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    endprotoent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
