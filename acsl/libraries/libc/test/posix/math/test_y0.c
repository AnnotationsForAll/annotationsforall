#include "../../../test_common.h"
#include <math.h>

/*@
assigns \result;
ensures \result < 0;
*/
extern double anyneg();

void runSuccess() {
    y0(0.0);
    y0(43.0);
    y0(-1.2);
    y0(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = y0(anyneg());
    //@ assert result == -HUGE_VAL || is_NaN_dbl(result);
    result = y0(0.0);
    //@ assert result == -HUGE_VAL;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
