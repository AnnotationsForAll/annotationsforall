#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    isnan(anydouble());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    int result;
    result = isnan(0.0);
    //@ assert result == 0;
    result = isnan(-5.0);
    //@ assert result == 0;
    result = isnan(3e20);
    //@ assert result == 0;
    result = isnan(nan(NULL));
    //@ assert result != 0;
    result = isnan(HUGE_VAL);
    //@ assert result == 0;
    //result = isnan(-HUGE_VAL);
    ////@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
