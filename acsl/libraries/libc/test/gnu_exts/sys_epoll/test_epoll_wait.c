#include "../../../test_common.h"
#include <sys/epoll.h>

void runSuccess() {
    struct epoll_event buf[10];
    epoll_wait(anyint(), buf, 10, anyint());
}

void runFailure() {
    struct epoll_event buf[10];
    epoll_wait(anyint(), NULL, 10, anyint());
}

void runFailure1() {
    struct epoll_event buf[10];
    epoll_wait(anyint(), buf, 20, anyint());
}

int f;
void testValues() {
    f = 2;
    
    struct epoll_event buf[10];
    epoll_wait(anyint(), buf, 10, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
