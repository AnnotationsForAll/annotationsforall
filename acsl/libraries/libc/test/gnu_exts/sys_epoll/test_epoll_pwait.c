#include "../../../test_common.h"
#include <sys/epoll.h>

void runSuccess() {
    struct epoll_event buf[10];
    sigset_t sig;
    epoll_pwait(anyint(), buf, 10, anyint(), &sig);
}

void runSuccess1() {
    struct epoll_event buf[10];
    sigset_t sig;
    epoll_pwait(anyint(), buf, 10, anyint(), NULL);
}

void runFailure() {
    struct epoll_event buf[10];
    sigset_t sig;
    epoll_pwait(anyint(), NULL, 10, anyint(), &sig);
}

void runFailure1() {
    struct epoll_event buf[10];
    sigset_t sig;
    epoll_pwait(anyint(), buf, 20, anyint(), &sig);
}

int f;
void testValues() {
    f = 2;
    
    struct epoll_event buf[10];
    sigset_t sig;
    epoll_pwait(anyint(), buf, 10, anyint(), &sig);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
