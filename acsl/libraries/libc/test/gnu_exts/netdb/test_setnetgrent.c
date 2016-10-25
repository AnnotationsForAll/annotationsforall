#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    setnetgrent(anystring());
}

void runFailure() {
    setnetgrent(NULL);
}

int f;
void testValues() {
    f = 2;
    
    setnetgrent(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
