#include "../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        ferror(file);
    }
}

void runFailure() {
    ferror(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = ferror(file);
    }
    //returns zero if not error, and nonzero if error
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
