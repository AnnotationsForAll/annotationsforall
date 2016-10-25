#include "../../../test_common.h"
#include <gshadow.h>

void runSuccess() {
    endsgent();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    endsgent();
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
