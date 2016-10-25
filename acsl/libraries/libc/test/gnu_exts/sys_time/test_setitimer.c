#include "../../../test_common.h"
#include <sys/time.h>

void runSuccess() {
    struct itimerval t;
    setitimer(ITIMER_REAL, &t, NULL);
}

void runSuccess1() {
    struct itimerval t1, t2;
    setitimer(ITIMER_VIRTUAL, &t1, &t2);
}

void runFailure() {
    setitimer(ITIMER_PROF, NULL, NULL);
}

void runFailure1() {
    struct itimerval t1, t2;
    setitimer(anyint(), &t1, &t2);
}

int f;
void testValues() {
    f = 2;
    
    struct itimerval t1, t2;
    setitimer(ITIMER_VIRTUAL, &t1, &t2);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
