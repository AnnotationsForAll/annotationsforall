#include "../../../test_common.h"
#include <signal.h>

void anyaction(int);

void runSuccess() {
    sigset(anyint(), anyaction);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sigset(anyint(), anyaction);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
