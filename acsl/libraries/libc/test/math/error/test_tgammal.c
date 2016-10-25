#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    tgammal(0.0L);
    tgammal(1.0L);
    tgammal(-1.0L);
    tgammal(56.5L);
    tgammal(anylongdouble());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long double result;
    
    tgammal(0.0L);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
