#include "../../../test_common.h"
#include <sched.h>

void runSuccess() {
    sched_get_priority_max(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sched_get_priority_max(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
