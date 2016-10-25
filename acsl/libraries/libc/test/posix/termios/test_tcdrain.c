#include "../../../test_common.h"
#include <termios.h>

void runSuccess() {
    tcdrain(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = tcdrain(anyint());
    //@ assert result == -1 || result == 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
