#include "../../test_common.h"
#include <stdlib.h>

void runSuccess() {
   rand(); 
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = rand();
    //@ assert 0 <= result <= RAND_MAX;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}