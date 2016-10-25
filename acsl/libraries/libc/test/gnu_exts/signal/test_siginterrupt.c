#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    siginterrupt(anyint(), anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    siginterrupt(anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
