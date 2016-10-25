#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    isinff(anyfloat());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    int result;
    result = isinff(0.0f);
    //@ assert result == 0;
    result = isinff(-5.0f);
    //@ assert result == 0;
    result = isinff(3e20f);
    //@ assert result == 0;
    result = isinff(nanf(NULL));
    //@ assert result == 0;
    result = isinff(HUGE_VALF);
    //@ assert result == 1;
    //result = isinff(-HUGE_VALF);
    ////@ assert result == -1;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
