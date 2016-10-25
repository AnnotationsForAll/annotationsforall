#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    struct drand48_data data;
    long d;
    lrand48_r(&data, &d);
}

void runFailure() {
    struct drand48_data data;
    long d;
    lrand48_r(NULL, &d);
}

void runFailure1() {
    struct drand48_data data;
    long d;
    lrand48_r(&data, NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct drand48_data data;
    long d;
    lrand48_r(&data, &d);
    //@ assert 0 <= d < 2147483648;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
