#include "../../../test_common.h"
#include <sched.h>

void runSuccess() {
    sched_getcpu();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    int result = sched_getcpu();
    //@ assert result == -1 || result >= 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
