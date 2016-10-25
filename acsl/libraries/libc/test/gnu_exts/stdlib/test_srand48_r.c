#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    struct drand48_data data;
    srand48_r(anylong(), &data);
}

void runFailure() {
    struct drand48_data data;
    srand48_r(anylong(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct drand48_data data;
    srand48_r(anylong(), &data);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
