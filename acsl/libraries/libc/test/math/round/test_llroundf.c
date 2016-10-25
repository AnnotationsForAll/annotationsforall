#include "../../../test_common.h"
#include <math.h>

void runSuccess() {
    llroundf(1.0f);
    llroundf(0.0f);
    llroundf(43.56f);
    llroundf(-2.5f);
    llroundf(anyfloat());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    long long int result;
    
    llroundf(anyfloat());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
