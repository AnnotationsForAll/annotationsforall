#include "../../test_common.h"
#include <stdlib.h>

void runSuccess() {
   srand(10);
   srand(0);
   srand(465);
   srand(anyunit());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result, result2;
    unsigned int x;
    
    x = anyuint();
    srand(x);
    result = rand();
    srand(x);
    result2 = rand();
    //@ assert result == result2;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
