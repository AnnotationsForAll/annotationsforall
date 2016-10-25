#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    herror(anystring());
}

void runFailure() {
    herror(NULL);
}

int f;
void testValues() {
    f = 2;
    
    herror(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
