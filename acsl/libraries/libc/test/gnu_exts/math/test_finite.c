#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    finite(anydouble());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    int result;
    result = finite(0.0);
    //@ assert result != 0;
    result = finite(-5.0);
    //@ assert result != 0;
    result = finite(3e20);
    //@ assert result != 0;
    result = finite(nan(NULL));
    //@ assert result == 0;
    result = finite(HUGE_VAL);
    //@ assert result == 0;
    //result = finite(-HUGE_VAL);
    ////@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
