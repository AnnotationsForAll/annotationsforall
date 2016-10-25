#include "../../../test_common.h"
#include <termios.h>

void runSuccess() {
    tcgetsid(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = tcgetsid(anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
