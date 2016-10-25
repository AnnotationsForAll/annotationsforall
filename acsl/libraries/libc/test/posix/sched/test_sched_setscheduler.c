#include "../../../test_common.h"
#include <sched.h>

void runSuccess() {
    struct sched_param p;
    sched_setscheduler(anyint(), anyint(), &p);
}

void runFailure() {
    sched_setscheduler(anyint(), anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct sched_param p;
    sched_setscheduler(anyint(), anyint(), &p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
