#include "../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        ftell(file);
    }
}

void runFailure() {
    ftell(NULL);
}

int f;
void testValues() {
    f = 2;
    long int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = ftell(file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
