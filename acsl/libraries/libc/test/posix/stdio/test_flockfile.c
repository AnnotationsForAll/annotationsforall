#include "../../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        flockfile(file);
    }
}

void runFailure() {
    flockfile(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        flockfile(file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
