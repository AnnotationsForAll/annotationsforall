#include "../../../test_common.h"
#include <sys/timerfd.h>

void runSuccess() {
    struct itimerspec t;
    timerfd_gettime(anyint(), &t);
}

void runFailure() {
    struct itimerspec t;
    timerfd_gettime(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct itimerspec t;
    timerfd_gettime(anyint(), &t);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
