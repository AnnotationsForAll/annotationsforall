#include "../../../test_common.h"
#include <sys/timex.h>

void runSuccess() {
    struct ntptimeval t;
    ntp_gettime(&t);
}

void runFailure() {
    ntp_gettime(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct ntptimeval t;
    ntp_gettime(&t);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
