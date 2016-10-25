#include "../../../test_common.h"
#include <signal.h>

void anyaction(int);

void runSuccess() {
    sysv_signal(anyint(), anyaction);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sysv_signal(anyint(), anyaction);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
