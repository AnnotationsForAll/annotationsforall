#include "../../../test_common.h"
#include <sys/timerfd.h>

void runSuccess() {
    clockid_t c;
    timerfd_create(c, anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    clockid_t c;
    timerfd_create(c, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
