#include "../../../test_common.h"
#include <netdb.h>
#include <stdint.h>

void runSuccess() {
    getnetent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    struct netent * result;
    
    result = getnetent();
    //@ assert result == \null || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
