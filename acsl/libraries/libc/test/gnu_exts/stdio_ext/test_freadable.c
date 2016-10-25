#include "../../../stdio_common.h"
#include <stdio_ext.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        __freadable(file);
    }
}

void runFailure() {
    __freadable(NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        __freadable(file);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
