#include "../../../test_common.h"
#include <sys/epoll.h>

void runSuccess() {
    struct epoll_event ev;
    epoll_ctl(anyint(), EPOLL_CTL_ADD, anyint(), &ev);
}

void runSuccess1() {
    struct epoll_event ev;
    epoll_ctl(anyint(), EPOLL_CTL_DEL, anyint(), &ev);
}

void runSuccess2() {
    struct epoll_event ev;
    epoll_ctl(anyint(), EPOLL_CTL_DEL, anyint(), NULL);
}

void runSuccess3() {
    struct epoll_event ev;
    epoll_ctl(anyint(), EPOLL_CTL_MOD, anyint(), &ev);
}

void runFailure() {
    struct epoll_event ev;
    epoll_ctl(anyint(), EPOLL_CTL_ADD, anyint(), NULL);
}

void runFailure1() {
    struct epoll_event ev;
    epoll_ctl(anyint(), EPOLL_CTL_MOD, anyint(), NULL);
}

void runFailure2() {
    struct epoll_event ev;
    epoll_ctl(anyint(), anyint(), anyint(), &ev);
}

int f;
void testValues() {
    f = 2;
    
    struct epoll_event ev;
    epoll_ctl(anyint(), EPOLL_CTL_ADD, anyint(), &ev);
    epoll_ctl(anyint(), EPOLL_CTL_MOD, anyint(), &ev);
    epoll_ctl(anyint(), EPOLL_CTL_DEL, anyint(), NULL);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
