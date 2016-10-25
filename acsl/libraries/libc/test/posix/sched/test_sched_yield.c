#include "../../../test_common.h"
#include <sched.h>

void runSuccess() {
    sched_yield();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sched_yield();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
