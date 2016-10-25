#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    endnetent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    endnetent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
