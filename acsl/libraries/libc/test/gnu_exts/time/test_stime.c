#include "../../../test_common.h"
#include <time.h>

void runSuccess() {
    time_t t;
    stime(&t);
}

void runFailure() {
    stime(NULL);
}

int f;
void testValues() {
    f = 2;
    
    time_t t;
    stime(&t);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
