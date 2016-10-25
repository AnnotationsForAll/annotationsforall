#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    isinf(anydouble());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    int result;
    result = isinf(0.0);
    //@ assert result == 0;
    result = isinf(-5.0);
    //@ assert result == 0;
    result = isinf(3e20);
    //@ assert result == 0;
    result = isinf(nan(NULL));
    //@ assert result == 0;
    result = isinf(HUGE_VAL);
    //@ assert result == 1;
    //result = isinf(-HUGE_VAL);
    ////@ assert result == -1;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
