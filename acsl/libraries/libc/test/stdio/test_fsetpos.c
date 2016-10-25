#include "../../stdio_common.h"

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fpos_t pos;
        int good = fgetpos(file, &pos);
        if (good == 0) {
            fsetpos(file, &pos);
        }
    }
}

void runFailure() {
    fpos_t pos;
    
    fsetpos(NULL, &pos);
}

void runFailure1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fsetpos(file, NULL);
    }
}

void runFailure2() {
    fsetpos(NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fpos_t pos;
        int good = fgetpos(file, &pos);
        if (good == 0) {
            result = fsetpos(file, &pos);
        }
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
