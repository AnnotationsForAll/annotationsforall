#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    getpass(anystring());
}

void runFailure() {
    getpass(NULL);
}

int f;
void testValues() {
    f = 2;
    
    getpass(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
