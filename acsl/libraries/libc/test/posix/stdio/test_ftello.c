#include "../../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        ftello(file);
    }
}

void runFailure() {
    ftello(NULL);
}

int f;
void testValues() {
    f = 2;
    off_t result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = ftello(file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
