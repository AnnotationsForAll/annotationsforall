#include "../../../test_common.h"
#include <math.h>

/*@
assigns \result;
ensures \result < 0;
*/
extern double anyneg();

void runSuccess() {
    y1(0.0);
    y1(43.0);
    y1(-1.2);
    y1(anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = y1(anyneg());
    //@ assert result == -HUGE_VAL || is_NaN_dbl(result);
    result = y1(0.0);
    //@ assert result == -HUGE_VAL;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
