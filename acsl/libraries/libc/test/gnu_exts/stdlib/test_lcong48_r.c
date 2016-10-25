#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    unsigned short param[7];
    struct drand48_data data;
    lcong48_r(param, &data);
}

void runFailure() {
    unsigned short param[7];
    struct drand48_data data;
    lcong48_r(NULL, &data);
}

void runFailure1() {
    unsigned short param[7];
    struct drand48_data data;
    lcong48_r(param, NULL);
}

int f;
void testValues() {
    f = 2;
    
    unsigned short param[7];
    struct drand48_data data;
    lcong48_r(param, &data);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
