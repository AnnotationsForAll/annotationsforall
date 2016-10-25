#include "../../../test_common.h"
#include <mqueue.h>

void runSuccess() {
    mqd_t mq = mq_open(anystring(), anyint());
    struct mq_attr attrs;
    struct mq_attr oattrs;
    mq_setattr(mq, &attrs, &oattrs);
}

void runSuccess1() {
    mqd_t mq = mq_open(anystring(), anyint());
    struct mq_attr attrs;
    struct mq_attr oattrs;
    mq_setattr(mq, &attrs, NULL);
}

void runFailure() {
    mqd_t mq = mq_open(anystring(), anyint());
    struct mq_attr attrs;
    mq_setattr(mq, NULL, &attrs);
}

int f;
void testValues() {
    f = 2;
    
    mqd_t mq = mq_open(anystring(), anyint());
    struct mq_attr attrs;
    struct mq_attr oattrs;
    mq_setattr(mq, &attrs, &oattrs);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
