#include "../../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fileno(file);
    }
}

void runFailure() {
    fileno(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fileno(file);
        //@ assert result >= -1;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
