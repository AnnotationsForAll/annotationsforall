#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    isnanf(anyfloat());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    int result;
    result = isnanf(0.0f);
    //@ assert result == 0;
    result = isnanf(-5.0f);
    //@ assert result == 0;
    result = isnanf(3e20f);
    //@ assert result == 0;
    result = isnanf(nanf(NULL));
    //@ assert result != 0;
    result = isnanf(HUGE_VALF);
    //@ assert result == 0;
    //result = isnanf(-HUGE_VALF);
    ////@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
