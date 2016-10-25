#include "../../test_common.h"
#include <stdlib.h>

wchar_t str[MB_CUR_MAX];

void runSuccess() {
    mbstowcs(str, "short string", 10);
}

void runFailure() {
    mbstowcs(NULL, NULL, anysize());
}

int f;
void testValues() {
    f = 2;
    size_t result;

    // Is n < MB_CUR_MAX guaranteed?
    result = mbstowcs(str, "short string", 10);
    //@ assert (result == (size_t)(-1)) || (0 <= result < 10);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
