#include "../../../test_common.h"
#include <sys/socket.h>

void runSuccess() {
    struct mmsghdr buf[10];
    struct timespec time;
    recvmmsg(anyint(), buf, 10, anyint(), &time);
}

void runSuccess1() {
    struct mmsghdr buf[10];
    struct timespec time;
    recvmmsg(anyint(), buf, 10, anyint(), NULL);
}

void runFailure() {
    struct mmsghdr buf[10];
    struct timespec time;
    recvmmsg(anyint(), NULL, 10, anyint(), &time);
}

void runFailure1() {
    struct mmsghdr buf[10];
    struct timespec time;
    recvmmsg(anyint(), buf, 20, anyint(), &time);
}

int f;
void testValues() {
    f = 2;

    struct mmsghdr buf[10];
    struct timespec time;
    int result = recvmmsg(anyint(), buf, 10, anyint(), &time);
    //@ assert -1 <= result <= 10;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
