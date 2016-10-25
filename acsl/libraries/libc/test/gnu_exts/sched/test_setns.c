#include "../../../test_common.h"
#include <sched.h>

void runSuccess() {
    setns(anyint(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    setns(anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
