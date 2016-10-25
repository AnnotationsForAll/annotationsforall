#include "../../../test_common.h"
#include <sched.h>

void runSuccess() {
    struct timespec p;
    sched_rr_get_interval(anyint(), &p);
}

void runFailure() {
    sched_rr_get_interval(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct timespec p;
    sched_rr_get_interval(anyint(), &p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
