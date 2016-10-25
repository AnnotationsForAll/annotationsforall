#include "../../../test_common.h"
#include <mqueue.h>

void runSuccess() {
    mqd_t mq = mq_open(anystring(), anyint());
    struct sigevent sigev;
    mq_notify(mq, &sigev);
}

void runSuccess1() {
    mqd_t mq = mq_open(anystring(), anyint());
    struct sigevent sigev;
    mq_notify(mq, NULL);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    mqd_t mq = mq_open(anystring(), anyint());
    struct sigevent sigev;
    mq_notify(mq, &sigev);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
