#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    significand(anydouble());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    significand(anydouble());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
