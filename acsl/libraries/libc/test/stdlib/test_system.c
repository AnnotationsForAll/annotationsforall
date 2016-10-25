#include "../../test_common.h"
#include <stdlib.h>

void runSuccess() {
   system("commands go here");
   system("");
   system(NULL);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    system("");

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
