#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    sysconf(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long int result;
    
    result = sysconf(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
