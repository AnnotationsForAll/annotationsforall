#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    fpathconf(anyint(), anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long int result;
    
    fpathconf(anyint(), anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
