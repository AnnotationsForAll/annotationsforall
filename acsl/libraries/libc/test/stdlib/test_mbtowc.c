#include "../../test_common.h"
#include <stdlib.h>

wchar_t pwc;

void runSuccess() {
   mbtowc(NULL, "string", 5);
   mbtowc(&pwc, "string", 4);
   mbtowc(NULL, NULL, 0);
}

void runFailure() {
    mbtowc(&pwc, "", 5); //buffer too short
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = mbtowc(NULL, "string", 5);
    //@ assert -1 <= result <= 5;
    //@ assert -1 <= result <= MB_CUR_MAX;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
