#include "../../../test_common.h"
#include <netdb.h>
#include <stdint.h>

void runSuccess() {
    getprotoent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct protoent * result;
    
    result = getprotoent();
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
