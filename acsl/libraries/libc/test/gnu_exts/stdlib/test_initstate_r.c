#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[10];
    struct random_data data;
    initstate_r(anyint(), buf, 10, &data);
}

void runFailure() {
    char buf[10];
    struct random_data data;
    initstate_r(anyint(), NULL, 10, &data);
}

void runFailure1() {
    char buf[10];
    struct random_data data;
    initstate_r(anyint(), buf, 20, &data);
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    struct random_data data;
    initstate_r(anyint(), buf, 10, &data);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
