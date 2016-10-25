#include "../../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        ftrylockfile(file);
    }
}

void runFailure() {
    ftrylockfile(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = ftrylockfile(file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
