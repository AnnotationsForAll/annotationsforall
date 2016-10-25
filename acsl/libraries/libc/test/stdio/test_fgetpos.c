#include "../../stdio_common.h"

void runSuccess() {
    fpos_t pos;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgetpos(file, &pos);
    }
}

void runFailure() {
    fpos_t pos;
    
    fgetpos(NULL, &pos);
}

void runFailure1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fgetpos(file, NULL);
    }
}

void runFailure2() {
    fgetpos(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    fpos_t pos;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fgetpos(file, &pos);
    }
    //fpos_t is opaque type; cannot test for validity of contents
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
