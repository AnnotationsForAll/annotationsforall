#include "../../../test_common.h"
#include <sched.h>

void runSuccess() {
    struct sched_param p;
    sched_setparam(anyint(), &p);
}

void runFailure() {
    sched_setparam(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct sched_param p;
    sched_setparam(anyint(), &p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
