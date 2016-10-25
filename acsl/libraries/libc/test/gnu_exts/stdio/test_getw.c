#include "../../../stdio_common.h"
#include <stdio.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        getw(file);
    }
}

void runFailure() {
    getw(NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        getw(file);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
