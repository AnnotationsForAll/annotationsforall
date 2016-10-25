#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    int fds[2];
    pipe2(fds, anyint());
}

void runFailure() {
    int fds[2];
    pipe2(NULL, anyint());
}

void runFailure1() {
    int fds[1];
    pipe2(fds, anyint());
}

int f;
void testValues() {
    f = 2;
    
    int fds[2];
    pipe2(fds, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
