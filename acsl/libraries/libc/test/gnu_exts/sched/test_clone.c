#include "../../../test_common.h"
#include <sched.h>

void any_func(void*);

void runSuccess() {
    void* arg;
    clone(any_func, anystring(), anyint(), arg);
}

void runFailure() {
    void* arg;
    clone(NULL, anystring(), anyint(), arg);
}

void runFailure1() {
    void* arg;
    clone(any_func, NULL, anyint(), arg);
}

int f;
void testValues() {
    f = 2;
    
    void* arg;
    clone(any_func, anystring(), anyint(), arg);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
