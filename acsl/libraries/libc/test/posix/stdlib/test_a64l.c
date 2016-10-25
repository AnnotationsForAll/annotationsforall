#include "../../../test_common.h"
#include <stdlib.h>

void runSuccess() {
   a64l(l64a(3L));
}

void runFailure() {
    a64l(NULL);
}

int f;
void testValues() {
    f = 2;
    long int result;
    
    result = a64l(l64a(3L));
    ////@ assert result == 3; //to strong to prove currently
    
    long int x = anylongint();
    result = a64l(l64a(x));
    ////@ assert result == x; //to strong to prove currently
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
