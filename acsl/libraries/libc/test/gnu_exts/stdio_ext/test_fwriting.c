#include "../../../stdio_common.h"
#include <stdio_ext.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        __fwriting(file);
    }
}

void runFailure() {
    __fwriting(NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        __fwriting(file);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
