#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    gsignal(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    gsignal(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
