#include "../../test_common.h"
#include <time.h>

void runSuccess() {
    struct timespec time;
    timespec_get(&time, anyint());
}

void runFailure() {
    struct timespec time;
    timespec_get(NULL, anyint());
}

int f;
void testValues() {
    f = 2;

    struct timespec time;
    timespec_get(&time, TIME_UTC);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
