#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    sigblock(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sigblock(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
