#include "../../../test_common.h"
#include <mqueue.h>

void runSuccess() {
    mq_unlink(anystring());
}

void runFailure() {
    mq_unlink(NULL);
}

int f;
void testValues() {
    f = 2;
    
    mq_unlink(anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
