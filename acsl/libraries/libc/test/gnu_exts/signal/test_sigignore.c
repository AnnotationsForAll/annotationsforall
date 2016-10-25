#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    sigignore(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sigignore(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
