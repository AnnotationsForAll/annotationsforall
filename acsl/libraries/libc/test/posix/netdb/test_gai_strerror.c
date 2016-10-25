#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    gai_strerror(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = gai_strerror(anyint());
    //@ assert \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
