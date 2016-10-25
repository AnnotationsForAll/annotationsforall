#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[10];
    struct random_data data;
    if (!initstate_r(anyint(), buf, 10, &data)) {
        srandom_r(anyint(), &data);
    }
}

void runFailure() {
    char buf[10];
    struct random_data data;
    srandom_r(anyint(), &data);
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    struct random_data data;
    if (!initstate_r(anyint(), buf, 10, &data)) {
        srandom_r(anyint(), &data);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
