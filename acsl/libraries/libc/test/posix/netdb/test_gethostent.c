#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    gethostent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct hostent * result;
    
    result = gethostent();
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
