#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    revoke(anystring());
}

void runFailure() {
    revoke(NULL);
}

int f;
void testValues() {
    f = 2;
    
    revoke(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
