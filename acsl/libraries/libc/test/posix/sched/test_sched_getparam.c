#include "../../../test_common.h"
#include <sched.h>

void runSuccess() {
    struct sched_param p;
    sched_getparam(anyint(), &p);
}

void runFailure() {
    sched_getparam(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct sched_param p;
    sched_getparam(anyint(), &p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
