#include "../../test_common.h"
#include <stdlib.h>

char str[MB_CUR_MAX];

void runSuccess() {
    wcstombs(str, L"wide string", 10);
}

void runFailure() {
    wcstombs(NULL, NULL, anysize());
}

int f;
void testValues() {
    f = 2;
    size_t result;
    
    result = wcstombs(str, L"wide string", 10);
    //@ assert (result != (size_t)(-1)) ==> (0 <= result < (10 * sizeof(char)));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
