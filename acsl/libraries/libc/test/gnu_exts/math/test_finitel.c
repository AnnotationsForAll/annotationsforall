#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    finitel(anylongdouble());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;

    int result;
    result = finitel(0.0L);
    //@ assert result != 0;
    result = finitel(-5.0L);
    //@ assert result != 0;
    result = finitel(3e20L);
    //@ assert result != 0;
    result = finitel(nanl(NULL));
    //@ assert result == 0;
    result = finitel(HUGE_VALL);
    //@ assert result == 0;
    //result = finitel(-HUGE_VALL);
    ////@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
