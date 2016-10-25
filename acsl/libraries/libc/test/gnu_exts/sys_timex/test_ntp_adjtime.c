#include "../../../test_common.h"
#include <sys/timex.h>

void runSuccess() {
    struct timex t;
    ntp_adjtime(&t);
}

void runFailure() {
    ntp_adjtime(NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct timex t;
    ntp_adjtime(&t);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
