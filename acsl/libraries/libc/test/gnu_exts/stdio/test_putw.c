#include "../../../stdio_common.h"
#include <stdio.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        putw(anyint(), file);
    }
}

void runFailure() {
    putw(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        putw(anyint(), file);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
