#include "../../../test_common.h"
#include <signal.h>

void anyaction(int);

void runSuccess() {
    bsd_signal(anyint(), anyaction);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    bsd_signal(anyint(), anyaction);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
