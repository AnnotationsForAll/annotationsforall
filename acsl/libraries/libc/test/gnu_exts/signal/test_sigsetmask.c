#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    sigsetmask(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sigsetmask(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
