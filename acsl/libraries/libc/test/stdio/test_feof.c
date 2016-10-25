#include "../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        feof(file);
    }
}

void runFailure() {
    feof(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = feof(file);
    }
    //returns zero if not EOF, and nonzero if EOF
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
