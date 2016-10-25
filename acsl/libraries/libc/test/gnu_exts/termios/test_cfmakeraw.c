#include "../../../test_common.h"
#include <termios.h>

void runSuccess() {
    struct termios p;
    cfmakeraw(&p);
}

void runFailure() {
    cfmakeraw(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct termios p;
    cfmakeraw(&p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
