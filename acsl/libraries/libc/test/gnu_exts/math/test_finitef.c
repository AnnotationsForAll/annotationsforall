#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    finitef(anyfloat());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    int result;
    result = finitef(0.0f);
    //@ assert result != 0;
    result = finitef(-5.0f);
    //@ assert result != 0;
    result = finitef(3e20f);
    //@ assert result != 0;
    result = finitef(nanf(NULL));
    //@ assert result == 0;
    result = finitef(HUGE_VALF);
    //@ assert result == 0;
    //result = finitef(-HUGE_VALF);
    ////@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
