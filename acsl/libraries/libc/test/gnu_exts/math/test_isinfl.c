#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    isinfl(anylongdouble());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    int result;
    result = isinfl(0.0L);
    //@ assert result == 0;
    result = isinfl(-5.0L);
    //@ assert result == 0;
    result = isinfl(3e20L);
    //@ assert result == 0;
    result = isinfl(nanl(NULL));
    //@ assert result == 0;
    result = isinfl(HUGE_VALL);
    //@ assert result == 1;
    //result = isinfl(-HUGE_VALL);
    ////@ assert result == -1;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
