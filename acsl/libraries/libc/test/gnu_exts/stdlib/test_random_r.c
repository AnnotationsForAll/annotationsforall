#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    char buf[10];
    struct random_data data;
    if (!initstate_r(anyint(), buf, 10, &data)) {
        int32_t i;
        random_r(&data, &i);
    }
}

void runFailure() {
    char buf[10];
    struct random_data data;
    int32_t i;
    random_r(&data, &i);
}

int f;
void testValues() {
    f = 2;
    
    char buf[10];
    struct random_data data;
    if (!initstate_r(anyint(), buf, 10, &data)) {
        int32_t i;
        random_r(&data, &i);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
