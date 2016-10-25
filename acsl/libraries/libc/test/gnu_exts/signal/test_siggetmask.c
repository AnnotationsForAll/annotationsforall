#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    siggetmask();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    siggetmask();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
