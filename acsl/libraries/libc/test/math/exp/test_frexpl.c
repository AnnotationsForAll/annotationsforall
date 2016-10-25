#include "../../../test_common.h"
#include <math.h>

int expv;

/*@
predicate is_power_of_2(integer x) = \exists integer y; y >= -1 && \pow(2, y) == x;
*/

void runSuccess() {
    frexpl(1.0L, &expv);
    frexpl(0.0L, &expv);
    frexpl(-1.0L, &expv);
    frexpl(anylongdouble(), &expv);
}

void runFailure() {
    frexpl(0.0L, NULL);
}

void runFailure1() {
    frexpl(anylongdouble(), NULL);
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    //result = frexpl(1.0L, &expv);
    // assert .5 <= \abs(result) < 1;
    //result = frexpl(1.5L, &expv);
    // assert result * \pow(2, expv) == 1.5
    result = frexpl(0.0L, &expv);
    //@ assert result == 0 && expv == 0;
    //result = frexpl(anylongdouble(), &expv);
    // assert is_power_of_2(expv);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}