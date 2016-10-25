#include "../../../test_common.h"
#include <sys/time.h>

void runSuccess() {
    struct itimerval t;
    getitimer(ITIMER_REAL, &t);
}

void runFailure() {
    getitimer(ITIMER_PROF, NULL);
}

void runFailure1() {
    struct itimerval t;
    getitimer(anyint(), &t);
}

int f;
void testValues() {
    f = 2;
    
    struct itimerval t;
    getitimer(ITIMER_REAL, &t);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
