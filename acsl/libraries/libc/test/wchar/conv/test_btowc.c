#include "../../../test_common.h"
#include <wchar.h>

void runSuccess() {
    btowc('a');
    btowc(42);
    btowc(EOF);
    btowc(anyint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    wint_t result;
    
    result = btowc(EOF);
    //@ assert result == WEOF;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
