#include "../../../test_common.h"
#include <mqueue.h>

void runSuccess() {
    mq_open(anystring(), anyint());
}

void runFailure() {
    mq_open(NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    mq_open(anystring(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
