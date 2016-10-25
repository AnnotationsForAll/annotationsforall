#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    endservent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    endservent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
