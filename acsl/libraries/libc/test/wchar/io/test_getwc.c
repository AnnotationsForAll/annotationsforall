#include "../../../stdio_common.h"
#include <wchar.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        getwc(file);
    }
}

void runFailure() {
    getwc(NULL);
}

int f;
void testValues() {
    f = 2;
    wint_t result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = getwc(file);
        //@ assert result == WEOF || (wchar_t)result == result;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
