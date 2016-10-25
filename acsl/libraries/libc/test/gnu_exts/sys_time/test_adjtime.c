#include "../../../test_common.h"
#include <sys/time.h>

void runSuccess() {
    struct timeval d1;
    struct timeval d2;
    adjtime(&d1, &d2);
}

void runSuccess1() {
    struct timeval d1;
    adjtime(&d1, NULL);
}

void runFailure() {
    adjtime(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct timeval d1;
    struct timeval d2;
    adjtime(&d1, &d2);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
