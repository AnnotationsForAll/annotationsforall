#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    sighold(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sighold(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
