#include "../../../test_common.h"
#include <signal.h>

void anyaction(int);

void runSuccess() {
    ssignal(anyint(), anyaction);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    ssignal(anyint(), anyaction);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
