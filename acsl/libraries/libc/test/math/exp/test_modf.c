#include "../../../test_common.h"
#include <math.h>

double ipart;

/*@
predicate can_be_int(double x) = (int)x == x;
*/

void runSuccess() {
    modf(1.0, &ipart);
    modf(0.0, &ipart);
    modf(-1.0, &ipart);
    modf(anydouble(), &ipart);
}

void runFailure() {
    modf(0.0, NULL);
}

void runFailure1() {
    modf(anydouble(), NULL);
}

int f;
void testValues() {
    f = 2;
    double result;
    
    result = modf(1.0, &ipart);
    // assert result == 0 && ipart == 1;
    result = modf(3.5, &ipart);
    // assert result == 0.5 && ipart == 3;
    result = modf(-7.25, &ipart);
    // assert result == -0.25 && ipart == -7;
    result = modf(anydouble(), &ipart);
    // assert can_be_int(ipart);
    // assert 0 <= result < 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
