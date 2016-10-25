#include "../../../test_common.h"
#include <signal.h>

void runSuccess() {
    sigrelse(anyint());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    sigrelse(anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
