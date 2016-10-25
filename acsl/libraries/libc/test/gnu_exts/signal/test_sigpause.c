#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    sigpause(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sigpause(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
