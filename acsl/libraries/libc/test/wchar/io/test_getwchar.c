#include "../../../stdio_common.h"
#include <wchar.h>

void runSuccess() {
    getwchar();
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    wint_t result;
    
    result = getwchar();
    //@ assert result == WEOF || (wchar_t)result == result;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
