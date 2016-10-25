#include "../../../test_common.h"
#include <sched.h>

void runSuccess() {
    sched_get_priority_min(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sched_get_priority_min(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
