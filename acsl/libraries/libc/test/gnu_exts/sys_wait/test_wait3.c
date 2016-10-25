#include "../../../test_common.h"
#include <sys/wait.h>

void runSuccess() {
    union wait i;
    struct rusage u;
    wait3(&i, anyint(), &u);
}

void runSuccess1() {
    union wait i;
    struct rusage u;
    wait3(NULL, anyint(), &u);
}

void runSuccess2() {
    union wait i;
    struct rusage u;
    wait3(&i, anyint(), NULL);
}

void runSuccess3() {
    union wait i;
    struct rusage u;
    wait3(NULL, anyint(), NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    union wait i;
    struct rusage u;
    wait3(&i, anyint(), &u);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
