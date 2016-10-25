#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    lroundf(1.0f);
    lroundf(0.0f);
    lroundf(43.56f);
    lroundf(-2.5f);
    lroundf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long int result;
    
    lroundf(anyfloat());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
