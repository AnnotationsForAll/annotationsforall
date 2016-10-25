#include "../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        rewind(file);
    }
}

void runFailure() {
    rewind(NULL);
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        rewind(file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
