#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    alarm(anyuint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    unsigned int result;
    
    alarm(anyuint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
