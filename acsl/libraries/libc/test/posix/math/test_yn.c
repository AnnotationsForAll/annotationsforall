#include "../../../test_common.h"
#include <math.h>

/*@
assigns \result;
ensures \result < 0;
*/
extern double anyneg();

void runSuccess() {
    yn(5,0.0);
    yn(32,43.0);
    yn(-2,-1.2);
    yn(anyint(),anydouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = yn(anyint(),anyneg());
    //@ assert result == -HUGE_VAL || is_NaN_dbl(result);
    result = yn(anyint(),0.0);
    //@ assert result == -HUGE_VAL;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
