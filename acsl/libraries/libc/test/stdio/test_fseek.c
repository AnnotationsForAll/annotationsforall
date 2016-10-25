#include "../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fseek(file, anylong(), SEEK_SET);
    }
}

void runFailure() {
    fseek(NULL, anylong(), SEEK_CUR);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fseek(file, anylong(), SEEK_SET);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
