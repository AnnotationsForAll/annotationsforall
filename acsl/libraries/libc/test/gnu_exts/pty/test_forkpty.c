#include "../../../test_common.h"
#include <pty.h>

void runSuccess() {
    int amaster;
    forkpty(&amaster, NULL, NULL, NULL);
}

void runSuccess1() {
    int amaster;
    char name[1];
    struct termios term;
    struct winsize win;
    forkpty(&amaster, name, &term, &win);
}

void runFailure() {
    forkpty(NULL, NULL, NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    
    int amaster;
    char name[1];
    struct termios term;
    struct winsize win;
    forkpty(&amaster, name, &term, &win);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
