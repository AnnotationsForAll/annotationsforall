#include "../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        clearerr(file);
    }
}

void runFailure() {
    clearerr(NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        clearerr(file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
