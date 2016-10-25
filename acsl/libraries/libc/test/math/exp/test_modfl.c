#include "../../../test_common.h"
#include <math.h>

long double ipart;

/*@
predicate can_be_int(long double x) = (int)x == x;
*/

void runSuccess() {
    modfl(1.0, &ipart);
    modfl(0.0, &ipart);
    modfl(-1.0, &ipart);
    modfl(anylongdouble(), &ipart);
}

void runFailure() {
    modfl(0.0, NULL);
}

void runFailure1() {
    modfl(anylongdouble(), NULL);
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    result = modfl(1.0, &ipart);
    //@ assert result == 0 && ipart == 1;
    result = modfl(3.5, &ipart);
    //@ assert result == 0.5 && ipart == 3;
    result = modfl(-7.25, &ipart);
    //@ assert result == -0.25 && ipart == -7;
    result = modfl(anylongdouble(), &ipart);
    //@ assert can_be_int(ipart);
    //@ assert 0 <= result < 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}