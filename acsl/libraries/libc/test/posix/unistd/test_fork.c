#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    fork();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    fork();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
