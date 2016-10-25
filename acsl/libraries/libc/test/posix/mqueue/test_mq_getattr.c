#include "../../../test_common.h"
#include <mqueue.h>

void runSuccess() {
    mqd_t mq = mq_open(anystring(), anyint());
    struct mq_attr attrs;
    mq_getattr(mq, &attrs);
}

void runFailure() {
    mqd_t mq = mq_open(anystring(), anyint());
    struct mq_attr attrs;
    mq_getattr(mq, NULL);
}

int f;
void testValues() {
    f = 2;
    
    mqd_t mq = mq_open(anystring(), anyint());
    struct mq_attr attrs;
    mq_getattr(mq, &attrs);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
