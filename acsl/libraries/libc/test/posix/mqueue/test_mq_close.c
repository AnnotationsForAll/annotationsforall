#include "../../../test_common.h"
#include <mqueue.h>

void runSuccess() {
    mqd_t mq = mq_open(anystring(), anyint());
    mq_close(mq);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    mqd_t mq = mq_open(anystring(), anyint());
    mq_close(mq);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
