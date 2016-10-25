#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    struct mmsghdr buf[10];
    sendmmsg(anyint(), buf, 10, anyint());
}

void runFailure() {
    struct mmsghdr buf[10];
    sendmmsg(anyint(), NULL, 10, anyint());
}

void runFailure1() {
    struct mmsghdr buf[10];
    sendmmsg(anyint(), buf, 20, anyint());
}

int f;
void testValues() {
    f = 2;

    struct mmsghdr buf[10];
    int result = sendmmsg(anyint(), buf, 10, anyint());
    //@ assert -1 <= result <= 10;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
