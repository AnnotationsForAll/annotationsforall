#include "../../../test_common.h"
#include <gshadow.h>

void runSuccess() {
    setsgent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    setsgent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
