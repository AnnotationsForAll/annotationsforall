#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    unsigned short xsubi[3];
    struct drand48_data data;
    seed48_r(xsubi, &data);
}

void runFailure() {
    unsigned short xsubi[3];
    struct drand48_data data;
    seed48_r(NULL, &data);
}

void runFailure1() {
    unsigned short xsubi[3];
    struct drand48_data data;
    seed48_r(xsubi, NULL);
}

int f;
void testValues() {
    f = 2;
    
    unsigned short xsubi[3];
    struct drand48_data data;
    seed48_r(xsubi, &data);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
