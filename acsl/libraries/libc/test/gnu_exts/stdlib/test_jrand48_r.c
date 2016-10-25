#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    unsigned short xsubi[3];
    struct drand48_data data;
    long d;
    jrand48_r(xsubi, &data, &d);
}

void runFailure() {
    unsigned short xsubi[3];
    struct drand48_data data;
    long d;
    jrand48_r(NULL, &data, &d);
}

void runFailure1() {
    unsigned short xsubi[3];
    struct drand48_data data;
    long d;
    jrand48_r(xsubi, NULL, &d);
}

void runFailure2() {
    unsigned short xsubi[3];
    struct drand48_data data;
    long d;
    jrand48_r(xsubi, &data, NULL);
}

int f;
void testValues() {
    f = 2;
    
    unsigned short xsubi[3];
    struct drand48_data data;
    long d;
    jrand48_r(xsubi, &data, &d);
    //@ assert -2147483648 <= d < 2147483648;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
