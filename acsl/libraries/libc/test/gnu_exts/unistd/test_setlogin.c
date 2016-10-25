#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    setlogin(anystring());
}

void runFailure() {
    setlogin(NULL);
}

int f;
void testValues() {
    f = 2;
    
    setlogin(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
