#include "../../../test_common.h"
#include <mqueue.h>

void runSuccess() {
    mqd_t mq = mq_open(anystring(), anyint());
    char buf[10];
    unsigned prio;
    mq_receive(mq, buf, 10, &prio);
}

void runSuccess1() {
    mqd_t mq = mq_open(anystring(), anyint());
    char buf[10];
    unsigned prio;
    mq_receive(mq, buf, 10, NULL);
}

void runFailure() {
    mqd_t mq = mq_open(anystring(), anyint());
    char buf[10];
    unsigned prio;
    mq_receive(mq, NULL, anysize(), &prio);
}

void runFailure1() {
    mqd_t mq = mq_open(anystring(), anyint());
    char buf[10];
    unsigned prio;
    mq_receive(mq, buf, 20, &prio);
}

int f;
void testValues() {
    f = 2;
    
    mqd_t mq = mq_open(anystring(), anyint());
    char buf[10];
    unsigned prio;
    mq_receive(mq, buf, 10, &prio);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
