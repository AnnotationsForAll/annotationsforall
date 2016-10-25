#include "../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fflush(file);
    }
}

void runSuccess1() {
    fflush(NULL);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fflush(file);
        //@ assert result == 0 || result == EOF;
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
