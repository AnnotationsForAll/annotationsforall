#include "../../../stdio_common.h"
#include <stdio_ext.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        __flbf(file);
    }
}

void runFailure() {
    __flbf(NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        __flbf(file);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
