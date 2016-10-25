#include "../../../test_common.h"
#include <mqueue.h>

void runSuccess() {
    mqd_t mq = mq_open(anystring(), anyint());
    char buf[10];
    unsigned prio;
    struct timespec timespec;
    mq_timedreceive(mq, buf, 10, &prio, &timespec);
}

void runSuccess1() {
    mqd_t mq = mq_open(anystring(), anyint());
    char buf[10];
    unsigned prio;
    struct timespec timespec;
    mq_timedreceive(mq, buf, 10, NULL, &timespec);
}

void runFailure() {
    mqd_t mq = mq_open(anystring(), anyint());
    char buf[10];
    unsigned prio;
    struct timespec timespec;
    mq_timedreceive(mq, NULL, anysize(), &prio, &timespec);
}

void runFailure1() {
    mqd_t mq = mq_open(anystring(), anyint());
    char buf[10];
    unsigned prio;
    struct timespec timespec;
    mq_timedreceive(mq, buf, 20, &prio, &timespec);
}

void runFailure2() {
    mqd_t mq = mq_open(anystring(), anyint());
    char buf[10];
    unsigned prio;
    struct timespec timespec;
    mq_timedreceive(mq, buf, 10, &prio, NULL);
}

int f;
void testValues() {
    f = 2;
    
    mqd_t mq = mq_open(anystring(), anyint());
    char buf[10];
    unsigned prio;
    struct timespec timespec;
    mq_timedreceive(mq, buf, 10, &prio, &timespec);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
