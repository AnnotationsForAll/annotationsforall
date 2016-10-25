#include "../../../test_common.h"
#include <sched.h>

void runSuccess() {
    cpu_set_t p;
    sched_getaffinity(anyint(), sizeof(cpu_set_t), &p);
}

void runFailure() {
    cpu_set_t p;
    sched_getaffinity(anyint(), sizeof(cpu_set_t), NULL);
}

int f;
void testValues() {
    f = 2;
    
    cpu_set_t p;
    sched_getaffinity(anyint(), sizeof(cpu_set_t), &p);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
