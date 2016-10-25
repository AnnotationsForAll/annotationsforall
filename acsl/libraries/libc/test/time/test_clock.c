#include "../../test_common.h"
#include <time.h>

void runSuccess() {
    clock();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    clock_t result;
    
    result = clock();
    //@ assert result == (clock_t)(-1) || result >= 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}