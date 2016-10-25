#include "../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fclose(file);
    }
}

void runFailure() {
    fclose(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    FILE* file = VALID_FILE;
    
    if (file != NULL) {
        result = fclose(file);
        //@ assert result == 0 || result == EOF;
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
