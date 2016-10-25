#include "../../../test_common.h"
#include <sys/timerfd.h>

void runSuccess() {
    struct itimerspec t1;
    struct itimerspec t2;
    timerfd_settime(anyint(), anyint(), &t1, &t2);
}

void runSuccess1() {
    struct itimerspec t1;
    struct itimerspec t2;
    timerfd_settime(anyint(), anyint(), &t1, NULL);
}

void runFailure() {
    struct itimerspec t1;
    struct itimerspec t2;
    timerfd_settime(anyint(), anyint(), NULL, &t2);
}

int f;
void testValues() {
    f = 2;
    
    struct itimerspec t1;
    struct itimerspec t2;
    timerfd_settime(anyint(), anyint(), &t1, &t2);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
