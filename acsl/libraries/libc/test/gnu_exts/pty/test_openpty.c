#include "../../../test_common.h"
#include <pty.h>

void runSuccess() {
    int amaster, aslave;
    openpty(&amaster, &aslave, NULL, NULL, NULL);
}

void runSuccess1() {
    int amaster, aslave;
    char name[1];
    struct termios term;
    struct winsize win;
    openpty(&amaster, &aslave, name, &term, &win);
}

void runFailure() {
    openpty(NULL, NULL, NULL, NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    
    int amaster, aslave;
    char name[1];
    struct termios term;
    struct winsize win;
    openpty(&amaster, &aslave, name, &term, &win);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
