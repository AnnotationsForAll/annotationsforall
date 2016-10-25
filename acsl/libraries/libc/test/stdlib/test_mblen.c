#include "../../test_common.h"
#include <stdlib.h>

void runSuccess() {
   mblen("string", 5);
   mblen(NULL, 0);
}

void runFailure() {
    mblen("", 5); //buffer too short
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = mblen("string", 5);
    // assert -1 <= result <= \min(5, MB_CUR_MAX);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
