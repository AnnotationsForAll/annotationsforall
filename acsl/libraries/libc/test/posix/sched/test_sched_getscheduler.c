#include "../../../test_common.h"
#include <sched.h>

void runSuccess() {
    sched_getscheduler(anyint());
}

void runFailure() {
    sched_getscheduler(anyint());
}

int f;
void testValues() {
    f = 2;
    
    sched_getscheduler(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
