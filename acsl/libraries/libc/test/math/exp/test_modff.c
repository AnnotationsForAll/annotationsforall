#include "../../../test_common.h"
#include <math.h>

float ipart;

/*@
predicate can_be_int(float x) = (int)x == x;
*/

void runSuccess() {
    modff(1.0, &ipart);
    modff(0.0, &ipart);
    modff(-1.0, &ipart);
    modff(anyfloat(), &ipart);
}

void runFailure() {
    modff(0.0, NULL);
}

void runFailure1() {
    modff(anyfloat(), NULL);
}

int f;
void testValues() {
    f = 2;
    float result;
    
    result = modff(1.0, &ipart);
    // assert result == 0 && ipart == 1;
    result = modff(3.5, &ipart);
    // assert result == 0.5 && ipart == 3;
    result = modff(-7.25, &ipart);
    // assert result == -0.25 && ipart == -7;
    result = modff(anyfloat(), &ipart);
    // assert can_be_int(ipart);
    // assert 0 <= result < 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
