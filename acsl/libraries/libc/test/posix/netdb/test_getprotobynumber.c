#include "../../../test_common.h"
#include <netdb.h>
#include <stdint.h>

void runSuccess() {
    getprotobynumber(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct protoent * result;
    
    result = getprotobynumber(anyint());
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
