#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
    clearenv();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    clearenv();

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
