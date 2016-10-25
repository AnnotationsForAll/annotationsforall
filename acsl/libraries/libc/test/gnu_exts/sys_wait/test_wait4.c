#include "../../../unistd_common.h"
#include <sys/wait.h>

void runSuccess() {
    union wait i;
    struct rusage u;
    wait4(VALID_PID, &i, anyint(), &u);
}

void runSuccess1() {
    union wait i;
    struct rusage u;
    wait4(VALID_PID, NULL, anyint(), &u);
}

void runSuccess2() {
    union wait i;
    struct rusage u;
    wait4(VALID_PID, &i, anyint(), NULL);
}

void runSuccess3() {
    union wait i;
    struct rusage u;
    wait4(VALID_PID, NULL, anyint(), NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    union wait i;
    struct rusage u;
    wait4(VALID_PID, &i, anyint(), &u);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
