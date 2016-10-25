#include "../../test_common.h"
#include <string.h>

void runSuccess() {
    strerror(0);
    strerror(7);
    strerror(-2);
    strerror(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = strerror(anyint());
    //@ assert \valid_read(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
