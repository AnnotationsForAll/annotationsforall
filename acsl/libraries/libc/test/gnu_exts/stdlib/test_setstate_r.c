#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[10];
    struct random_data data;
    char buf2[10];
    if (!initstate_r(anyint(), buf, 10, &data)) {
        setstate_r(buf2, &data);
    }
}

void runFailure() {
    char buf[10];
    struct random_data data;
    char buf2[10];
    setstate_r(buf2, &data);
}

void runFailure1() {
    char buf[10];
    struct random_data data;
    char buf2[5];
    if (!initstate_r(anyint(), buf, 10, &data)) {
        setstate_r(buf2, &data);
    }
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    struct random_data data;
    char buf2[10];
    if (!initstate_r(anyint(), buf, 10, &data)) {
        setstate_r(buf2, &data);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
