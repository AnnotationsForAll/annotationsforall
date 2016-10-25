#include "../../../test_common.h"
#include <unistd.h>

void runSuccess() {
    sleep(anyuint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    unsigned int result;
    
    result = sleep(anyuint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
