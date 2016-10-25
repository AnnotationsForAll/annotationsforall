#include "../../../test_common.h"
#include <sys/timeb.h>

void runSuccess() {
    struct timeb t;
    ftime(&t);
}

void runFailure() {
    ftime(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct timeb t;
    ftime(&t);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
